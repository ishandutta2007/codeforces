#include <iostream>
#include <algorithm>
#include <vector>
#define weightedgraph vector<vector<pair<int, int>>>
using namespace std;

int mx = 0, n, x, y, d;
weightedgraph cons;

int process(int v = 0, int prev = -1) {
	int cmx = 0;
	for (int i = 0; i < cons[v].size(); i++)
		if (cons[v][i].first != prev)
			cmx = max(cmx, process(cons[v][i].first, v) + cons[v][i].second);
	return cmx;
}

int main()
{
	cin >> n;
	cons.resize(n);
	for (int i = 0; i < n - 1; i++)
		cin >> x >> y >> d, cons[x].push_back({ y, d }), cons[y].push_back({ x, d });
	cout << process() << endl;
	return 0;
}