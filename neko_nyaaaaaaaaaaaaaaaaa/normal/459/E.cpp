#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, m, x, y;
	cin >> n >> m;
	vector<pair<int, int>> e[300001];
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		e[z].push_back({x, y});
	}
	
	vector<int> f(300001), g(300001);
	for (int i = 1; i < 300001; i++) {
		for (int j = 0; j < e[i].size(); j++) {
			g[e[i][j].second] = f[e[i][j].second];
		}
		for (int j = 0; j < e[i].size(); j++) {
			g[e[i][j].second] = max(g[e[i][j].second], f[e[i][j].first] + 1);
		}
		for (int j = 0; j < e[i].size(); j++) {
			f[e[i][j].second] = max(f[e[i][j].second], g[e[i][j].second]);
		}
	}
	
	cout << *max_element(f.begin(), f.end());
	
	return 0;
}