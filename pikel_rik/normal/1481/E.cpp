#include <bits/stdc++.h>
using namespace std;

int compress(vector<int> &a) {
	vector<int> temp = a;
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	for (auto &x : a) x = lower_bound(temp.begin(), temp.end(), x) - temp.begin();
	return int(temp.size());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	int mx = compress(a);
	vector<vector<int>> pos(mx);
	for (int i = 0; i < n; i++) {
		pos[a[i]].push_back(i);
	}

	vector<int> l(mx), r(mx), w(mx);
	for (int i = 0; i < mx; i++) {
		l[i] = pos[i].front(), r[i] = pos[i].back(), w[i] = int(pos[i].size());
		for (int j = 1; j < int(pos[i].size()); j++) {
			l.push_back(pos[i][j]);
			r.push_back(n - 1);
			w.push_back(int(pos[i].size()) - j);
		}
	}

	mx = int(l.size());

	vector<int> ind(mx);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&](int i, int j) {
		return r[i] < r[j];
	});

	vector<int> dp(mx); dp[0] = w[ind[0]];
	for (int i = 1; i < mx; i++) {
		int lo = 0, hi = i - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;
			if (r[ind[mid]] < l[ind[i]]) {
				lo = mid;
			} else hi = mid - 1;
		}

		if (r[ind[lo]] < l[ind[i]]) {
			dp[i] = w[ind[i]] + dp[lo];
		} else dp[i] = w[ind[i]];
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << n - dp.back() << '\n';
	return 0;
}