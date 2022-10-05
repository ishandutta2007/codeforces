#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m;
vector<vector<ll>> c;

bool cmp(ll aa, ll bb) {
	return aa > bb;
}

ll check(int upper) {
	ll rtn = 0;
	int add = 0;
	for (int i = 1; i < m; i++) {
		for (int j = 0; j + upper < c[i].size(); j++) {
			rtn += c[i][j];
			add++;
		}
	}
	if (c[0].size() + add > upper) return rtn;
	vector<ll> tmp;
	for (int i = 1; i < m; i++)
		for (int j = max(0, (int)c[i].size() - upper); j < c[i].size(); j++)
			tmp.push_back(c[i][j]);
	sort(tmp.begin(), tmp.end(), cmp);
	while (c[0].size() + add <= upper) {
		rtn += tmp.back();
		add++;
		tmp.pop_back();
	}
	return rtn;
}

int main() {
	fast;
	cin >> n >> m;
	c.resize(m);
	for (int i = 0, u, v; i < n; i++) {
		cin >> u >> v;
		--u;
		c[u].push_back(v);
	}
	for (int i = 0; i < m; i++) sort(c[i].begin(), c[i].end());
	ll ans = 9e18;
	for (int i = 0; i < n; i++) ans = min(ans, check(i));
	finish(ans);
}