// This solution was written during the onsite competition.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define wait system("pause")
#define finish(x) return cout << (x) << endl, 0
#define debug cout << "ok" << endl
using namespace std;

int n, m, s;
vector<vector<int>> g;
vector<int> vis[2], ans;
bool can[2] = { false, false };

void dfs(int v, int o, vector<int> &was) {
	if (vis[o][v]) return;
	vis[o][v] = 1;
	was.push_back(v);
	for (const auto &i : g[v]) {
		dfs(i, 1 ^ o, was);
	}
	if (!g[v].size()) {
		if (o == 0) can[0] = true;
		else if (!can[1]) {
			can[1] = true;
			for (const auto &i : was) ans.push_back(i);
		}
	}
	was.pop_back();
}

vector<int> st, fin;

bool dfs(int v) {
	if (st[v]) return !fin[v];
	bool rtn = false;
	st[v] = true;
	for (const auto &i : g[v]) rtn = rtn || dfs(i);
	fin[v] = true;
	return rtn;
}

bool cycle() {
	st.resize(n, 0);
	fin.resize(n, 0);
	return dfs(s);
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	g.resize(n);
	for (int i = 0, x, y; i < n; i++) {
		cin >> x;
		while (x--) {
			cin >> y;
			g[i].push_back(y - 1);
		}
	}
	cin >> s;
	vis[0].resize(n), vis[1].resize(n);
	for (int i = 0; i < n; i++) vis[0][i] = vis[1][i] = 0;

	vector<int> tmp;
	dfs(--s, 0, tmp);
	if (can[1]) {
		cout << "Win" << endl;
		for (const auto &i : ans) cout << i + 1 << " "; cout << endl;
//		wait;
		return 0;
	}
	if (cycle()) finish("Draw");
	if (can[0]) {
		cout << "Lose" << endl;
//		wait;
		return 0;
	}
	cout << "Draw" << endl;
//	wait;
}