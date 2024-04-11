#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	vector<int> arr(n), used(n);
	for (int i = 1; i < n; ++i) cin >> arr[i], arr[i] = arr[arr[i] - 1] + 1, used[arr[i]] = !used[arr[i]];
	for (auto i : used) ans += i;
	cout << ans + 1;
    return 0;
}