#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mod = 1e9 + 7;
void dfs(int v, vector <vector <int>> &a, vector <int> &cnt,  vector <bool> &used) {
	used[v] = true;
	cnt[v]++;
	for (auto u : a[v]) {
		if (used[u]) continue;
		dfs(u, a, cnt, used);
		cnt[v] += cnt[u];
	}
}
void solve() {
	int n; cin >> n;
	vector <vector <int>> a(n + 1);
	vector <pair <int, int>> ok;
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
		ok.push_back({ u, v });
	}
	int m; cin >> m;
	vector <int> p(m);
	for (auto& x : p) cin >> x;
	vector <int> cnt(n + 1);
	vector <bool> used(n + 1);
	dfs(1, a, cnt, used);
	vector <int> res;
	for (auto x : ok) {
		int mn = min(cnt[x.first], cnt[x.second]);
		res.push_back(mn * (n - mn));
	}
	sort(res.rbegin(), res.rend());
	sort(p.rbegin(), p.rend());
	if (m > n - 1) {
		int cur = 1;
		while (m > n - 1) {
			--m;
			p[0] *= p[cur++];
			p[0] %= mod;
		}
		vector <int> newp = { p[0] };
		for (int i = cur; i < p.size(); ++i) newp.push_back(p[i]);
		p = newp;
	}
	int ans = 0;
	for (int i = 0, x; i < n - 1; ++i) {
		if (i < p.size()) x = p[i];
		else x = 1;
		ans += (x * (res[i] % mod)) % mod;
		ans %= mod;
	}
	cout << ans << '\n';
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt-- > 0) {
		solve();
	}
}