#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n;
string s;
vector<vector<int>> g;
vector<int> vis;

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (const auto &i : g[v])
		dfs(i);
}

void solve() {
	cin >> n >> s;
	g.clear();
	g.resize(2 * n);
	for (int i = 0; i + 1 < s.size(); i++) {
		if (s[i] == ')' && s[i + 1] == '(') {
			g[i].push_back(i + 1);
			g[i + 1].push_back(i);
		}
	}
	vector<int> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') st.push_back(i);
		else {
			int j = st.back();
			st.pop_back();
			g[i].push_back(j);
			g[j].push_back(i);
		}
	}
	vis.resize(2 * n);
	for (int i = 0; i < 2 * n; i++) vis[i] = 0;
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (!vis[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}