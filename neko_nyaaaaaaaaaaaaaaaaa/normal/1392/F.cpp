#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, sum = 0; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; sum += a[i];
	}

	int tri = n*(n-1)/2;
	int left = sum - tri;
	int offset = left/n;

	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		ans[i] = i + offset;
		sum -= ans[i];
	}

	for (int i = 0; i < sum; i++) {
		ans[i]++;
	}

	for (int i: ans) cout << i << ' ';

	return 0;
}