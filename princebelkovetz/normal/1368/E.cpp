#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#define endl "\n";
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
int fastpow(int a, int b) {
	if (!b) return 1ll;
	if (b % 2 == 1) return fastpow(a, b - 1) * a;
	int t = fastpow(a, b / 2);
	return t * t;
}

void solve() {
	int n, m, u, v, inf = -1e9;
	cin >> n >> m;
	vector <vector <int>> a(n + 1);
	vector <int> sz(n + 1), ans;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		for (auto j : a[i]) {
			if (sz[j] == 0) sz[i] = 1;
			else if (sz[j] == 1) {
				ans.push_back(i);
				sz[i] = -1;
				break;
			}
		}
	}
	cout << ans.size() << endl;
	for (auto x : ans) cout << x << " ";
	cout << endl;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}