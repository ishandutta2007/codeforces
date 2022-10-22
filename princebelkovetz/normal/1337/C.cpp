#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define int long long
#define endl "\n";
using namespace std;
int dist[200020], child[200020];
bool used[200020], used2[200020];

void dfs(int v, vector <vector <int>> &a) {
	used2[v] = true;
	child[v] += a[v].size() - 1 + (v == 1LL);
	for (auto u : a[v]) {
		if (!used2[u]) {
			dfs(u, a);
			child[v] += child[u];
		}
	}
	
}
void solve(){
	int n, k, u, v, ans1 = 0;
	cin >> n >> k;
	vector <vector <int>> a(n + 1);
	dist[1] = 0;
	used[1] = true;
	for (int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		a[v].push_back(u);
		a[u].push_back(v);
	}
	queue <int> q;
	q.push(1);
	while (q.size()) {
		v = q.front();
		q.pop();
		for (auto u : a[v]) {
			if (used[u]) continue;
			dist[u] = dist[v] + 1;
			used[u] = true;
			q.push(u);
		}
	}
	dfs(1, a);
	vector <int> ans;
	/*for (int i = 1; i <= n; ++i) {
		cout << child[i] << " " << dist[i] << endl;
	}*/
	for (int i = 1; i <= n; ++i) {
		ans.push_back(dist[i] - child[i]);
	}
	sort(ans.begin(), ans.end());
	for (int i = n - 1; i > n - k - 1; i--) {
		ans1 += ans[i];
	}
	cout << ans1;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}