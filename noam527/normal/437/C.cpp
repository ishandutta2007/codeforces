#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

ll ans = 0;
int n, m;
vector<int> b;
vector<pair<int, int>> a;
vector<vector<int>> g;

ll cost(int x) {
	ll rtn = 0;
	for (auto &i : g[x]) rtn += b[i];
	b[x] = 0;
	return rtn;
}

int main() {
	fast;
	cin >> n >> m;
	a.resize(n), g.resize(n), b.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i, b[i] = a[i].first;
	sort(a.begin(), a.end());
	for (int i = 0, u, v; i < m; i++) cin >> u >> v, g[--u].push_back(--v), g[v].push_back(u);
	for (int i = n - 1; i >= 0; i--) ans += cost(a[i].second);
	cout << ans << endl;
}