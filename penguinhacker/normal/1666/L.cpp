/*
*       ___
*   _ /    _\_
*  / |    |___|
*  | |       |
*  \_|   __  |
*     \_/  \_/
*   uwu amogus
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mx 200005
vector<int> adj[mx];
int mark[mx] = {};
bool mark2[mx] = {};
bool found = false;
int res = -1;
int ca = -1, cb = -1;
vector<int> stk;
int dfs2(int x) {
	if (mark2[x]) return -1;
	mark2[x] = true;
	if (x == res) {
		stk.push_back(x);
		return 1;
	}
	for (auto& i : adj[x]) {
		if (dfs2(i) == 1) {
			stk.push_back(x);
			return 1;
		}
	}
	return -1;
}
void dfs(int x, int c) {
	if (mark[x] != 0 && mark[x] != c) {
		ca = mark[x];
		cb = c;
		found = true;
		res = x;
		return;
	}
	if (mark[x] == c)return;
	mark[x] = c;
	for (auto& x : adj[x]) {
		dfs(x, c);
		if (found) return;
	}
}
int main() {
	int n, m, s; cin >> n >> m >> s; s--;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
	}
	int col = 1;
	for (auto& x : adj[s]) {
		mark[s] = col;
		dfs(x, col);
		col++;
		if (found) break;
	}
	if (found) {
		cout << "Possible" << endl;
		col = 1;
		for (auto& x : adj[s]) {
			if (ca == col || cb == col) {
				stk.clear();
				for (int i = 0; i < n; i++)mark2[i] = false;
				mark2[s] = true; 
				dfs2(x);
				reverse(stk.begin(), stk.end());
				cout << stk.size()+1 << endl;
				cout << s+1 << " ";
				for (auto& i : stk) {
					cout << i + 1 << " ";
				}
				cout << endl;
			}
			col++;
		}
	}
	else {
		cout << "Impossible" << endl;
	}
}