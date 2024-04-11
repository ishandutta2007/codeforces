#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve1(int n, vector<int> a, vector<int> cnt) {
	cerr << "CASE 1\n";
	vector<int> ans(n);
	int c1 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 3 != 0) {
			ans[i] = 1;
			c1++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (ans[i] == 0) {
			if (c1 < n/2) {
				c1++; ans[i] = 1;
			}
		}
	}

	cout << "2\n";
	for (int i: ans) cout << i;
		cout << '\n';
}

void solve2(int n, vector<int> a, vector<int> cnt) {
	cerr << "CASE 2\n";
	vector<int> ans(n);
	int c1 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 3 == 0) {
			ans[i] = 1;
			c1++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (ans[i] == 0) {
			if (c1 < n/2) {
				c1++; ans[i] = 1;
			}
		}
	}

	cout << "0\n";
	for (int i: ans) cout << i;
		cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> cnt(3);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i] % 3]++;
	}

	if (cnt[0] > n/2) {
		solve1(n, a, cnt);
	} else {
		solve2(n, a, cnt);
	}

	return 0;
}