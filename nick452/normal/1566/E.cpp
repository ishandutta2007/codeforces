#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

pair<ll, ll> solve(const vector<vector<int>>& g, int cur, int prev) {
	pair<ll, ll> ret{0, 0};
	vector<ll> d;
	for (int next : g[cur]) {
		if (next != prev) {
			pair<ll, ll> tmp = solve(g, next, cur);
			ret.second += tmp.first;
			d.push_back(tmp.second - tmp.first);
		}
	}
	sort(d.begin(), d.end());
	ret.first = 1e8;
	ll sum = ret.second;
	for (int k = 0; k < d.size(); ++k) {
		sum += d[k];
		ret.first = min(ret.first, sum + k);
	}
	ret.second = min<ll>(1e8, ret.second);
	return ret;
}

ll solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}	
	pair<ll, ll> ret = solve(g, 0, -1);
	return min(ret.first, ret.second) + 1;
}

int main()
{
#ifdef _MSC_VER
	freopen("e.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_id = 0; case_id < n_cases; ++case_id) {
		cout << solve() << endl;
	}
	return 0;
}