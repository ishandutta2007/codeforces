#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#define int long long
#define endl "\n"
#define debug(x) cout << #x << " actually equals " << x << endl

using namespace std;
const int mxN = 1e5 + 7;
bool used[mxN];
int no[mxN];
vector <pair <int, int>> adj[mxN];
set <int> badr;

void dfs(int v, int x) {
	used[v] = true;
	for (auto u : adj[v]) {
		if (used[u.first]) continue;
		if (u.second == 2) no[u.first]++;
		dfs(u.first, u.second);
		no[v] += no[u.first];
	}
	if (no[v] == 1 and x == 2) badr.insert(v);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int n; cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int u, v, t; cin >> u >> v >> t;
		adj[u].push_back({ v, t });
		adj[v].push_back({ u , t });
		
	}
	dfs(1, 1);
	cout << badr.size() << endl;
	for (auto i = badr.begin(); i != badr.end(); ++i) cout << *i << " ";
	cout << endl;
	return 0;
}