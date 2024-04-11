#include <iostream>
#include <vector>
#include <algorithm>
#define graph vector<vector<int>>
using namespace std;

graph c;
vector<int> col(100000, -1);
int n, m, u, v;

bool dfs(int v = 0, int d = 0) {
	if (col[v] != -1)
		return col[v] == d;
	col[v] = d;
	bool ok = true;
	for (auto i : c[v]) ok = ok && dfs(i, 1 - d);
	return ok;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	c.resize(n);
	for (int i = 0; i < m; i++)
		cin >> u >> v, c[--u].push_back(--v), c[v].push_back(u);
	bool ok = true;
	for (int i = 0; i < n; i++)
		if (col[i] == -1)
			ok = ok && dfs(i);
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> white, black;
	for (int i = 0; i < n; i++)
		if (col[i] == 0)
			white.push_back(i + 1);
		else if (col[i] == 1)
			black.push_back(i + 1);
	cout << white.size() << endl; for (auto i : white) cout << i << " "; cout << endl;
	cout << black.size() << endl; for (auto i : black) cout << i << " "; cout << endl;
	return 0;
}