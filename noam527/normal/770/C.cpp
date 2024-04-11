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
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, k, cnt = 0;
bool valid = true;
vector<int> a, vis;
vector<pair<int, int>> ans;
vector<vector<int>> g;

void dfs(int v) {
	vis[v] = 1;
	for (auto i : g[v]) {
		if (vis[i]) {
			if (!ans[i].first) valid = false;
		}
		else dfs(i);
	}
	ans[v] = { 1, cnt++ };
}

int main() {
	fast;
	cin >> n >> k;
	a.resize(k);
	for (int i = 0; i < k; i++) cin >> a[i], a[i]--;
	g.resize(n), vis.resize(n, 0), ans.resize(n, { 0, -1 });
	for (int i = 0, u, v; i < n; i++) {
		cin >> u;
		for (int j = 0; j < u; j++)
			cin >> v, g[i].push_back(v - 1);
	}
	for (auto i : a) if (!vis[i]) dfs(i);
	if (valid) {
		vector<int> output(cnt);
		for (int i = 0; i < n; i++) if (ans[i].first) output[ans[i].second] = i + 1;
		cout << cnt << endl;
		for (auto i : output) cout << i << " "; cout << endl;
	}
	else cout << -1 << endl;
}