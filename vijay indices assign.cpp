#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Function to find the two indices
vector<int> twoSum(vector<int>& nums, int target) {
    // Map to store the original indices of elements
    unordered_map<int, int> originalIndices;
    for (int i = 0; i < nums.size(); i++) {
        originalIndices[nums[i]] = i;
    }

    // Sort the array and keep track of the original indices
    vector<pair<int, int>> sortedNums;
    for (int i = 0; i < nums.size(); i++) {
        sortedNums.push_back({nums[i], i});
    }
    sort(sortedNums.begin(), sortedNums.end());

    // Two-pointer technique
    int left = 0, right = sortedNums.size() - 1;
    while (left < right) {
        int sum = sortedNums[left].first + sortedNums[right].first;
        if (sum == target) {
            return {sortedNums[left].second, sortedNums[right].second};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    // Return an empty vector if no solution exists
    return {};
}

int main() {
    int n, target;

    // Input size validation
    do {
        cout << "Enter the number of elements in the array (between 2 and 10^4): ";
        cin >> n;
    } while (n < 2 || n > 10000);

    vector<int> nums(n);

    // Input array elements with validation
    cout << "Enter the elements of the array (between -10^9 and 10^9):" << endl;
    for (int i = 0; i < n; i++) {
        int num;
        do {
            cout << "Element " << i + 1 << ": ";
            cin >> num;
        } while (num < -1000000000 || num > 1000000000);
        nums[i] = num;
    }

    // Input target validation
    do {
        cout << "Enter the target value (between -10^9 and 10^9): ";
        cin >> target;
    } while (target < -1000000000 || target > 1000000000);

    // Find the two indices
    vector<int> result = twoSum(nums, target);

    // Output the result
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "Solution not present." << endl;
    }

    return 0;
}
