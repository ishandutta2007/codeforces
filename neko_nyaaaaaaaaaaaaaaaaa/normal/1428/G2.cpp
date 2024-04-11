#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 999999;
const int INF = 1e16;

vector<int> split(int k) {
	int cur = 1;
	vector<int> ans;
	while (k > 0) {
		int nxt = min(cur, k);
		ans.push_back(nxt); k -= nxt;
		cur *= 2;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int k; cin >> k;
	vector<int> f(6);
	for (int i = 0; i < 6; i++) {
		cin >> f[i];
	}

	vector<pair<int, int>> knapitems;
	vector<int> sp = split(3*k - 3);

	for (int i: sp) {
		int p = 1;
		for (int j = 0; j < 6; j++) {
			knapitems.emplace_back(p*3*i, f[j]*i);
			p *= 10;
		}
	}
	vector<int> dp(MAXN + 1, -INF);
	dp[0] = 0;
	for (auto [cost, val]: knapitems) {
		for (int j = MAXN; j >= cost; j--) {
			dp[j] = max(dp[j], dp[j-cost] + val);
		}
	}

	int p = 1;
	for (int j = 0; j < 6; j++) {
		knapitems.clear();

		for (int i = 1; i <= 9; i++) {
			int d = 0;
			if (i % 3 == 0) d = i/3;
			knapitems.emplace_back(p*i, d*f[j]);
		}

		for (int j = MAXN; j >= 0; j--) {
			for (auto [cost, val]: knapitems) {
				if (j >= cost) dp[j] = max(dp[j], dp[j - cost] + val);
			}
		}

		p *= 10;
	}
	
	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		cout << dp[x] << '\n';
	}

	return 0;
}