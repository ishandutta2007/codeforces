#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int nums[2 * n];
    for (int i = 0; i < 2 * n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + 2 * n);
    bool s = true;
    for (int i = 0; i < 2 * n; i++) {
        if (nums[i] != nums[2 * n - i - 1]) {
            s = false;
            break;
        }
    }
    if (s) {
		cout << -1;
		return 0;
	}
    for (int i = 0; i < 2 * n; i++) {
        cout << nums[i] << " ";
    }
}