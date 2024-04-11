#include <bits/stdc++.h>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
#define yesno(X) cout << ((X) ? "YES" : "NO") << endl
#define noyes(X) cout << ((X) ? "NO" : "YES") << endl
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m,u,v;
map<int, vector<int>> ma;

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> u >> v;
		ma[u].push_back(v);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		ma[u].push_back(v);
	}
	ll ans = 0;
	for (const auto &i : ma)
		ans += *max_element(i.second.begin(), i.second.end());
	finish(ans);
}