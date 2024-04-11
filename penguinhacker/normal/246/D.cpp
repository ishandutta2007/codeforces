#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, m, best, colNum, c[100000];
vector<int> adj[100000];
map<int, vector<int>> colors;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> c[i];
		colors[c[i]].push_back(i);
	}
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	colNum=colors.begin()->first;
	for (auto x:colors) {
		set<int> distinct;
		for (int u:x.second) {
			for (int i:adj[u]) {
				if (c[i]!=x.first)
					distinct.insert(c[i]);
			}
		}
		if (distinct.size()>best) {
			best=distinct.size();
			colNum=x.first;
		}
	}
	cout << colNum;
	return 0;
}