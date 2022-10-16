#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, k; cin >> n >> k;
	vector<int> c(n*k);
	for (int i = 0; i < n*k; i++) {
		cin >> c[i]; c[i]--;
	}

	int lim = (n+k-2)/(k-1);

	vector<int> used(n);
	vector<pair<int, int>> ans(n);

	vector<int> lst(n, -1);
	int tried = 0;
	for (int i = 0; i < n*k; i++) {
		if (used[c[i]]) continue;

		if (lst[c[i]] != -1) {
			tried++;
			ans[c[i]] = {lst[c[i]]+1, i+1};
			used[c[i]] = 1;

			if (tried == lim) {
				tried = 0;
				for (int &j: lst) j = -1;
			}
		} else {
			lst[c[i]] = i;
		}
	}

	for (auto [u, v]: ans) {
		cout << u << ' ' << v << '\n';
	}

	return 0;
}