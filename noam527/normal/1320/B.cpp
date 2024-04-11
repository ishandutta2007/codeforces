#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define finish(X) return cout << (X) << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n, m, k;
vector<vector<int>> g, rev;
vector<int> p;
set<pair<int, int>> t;

vector<int> dist;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	g.resize(n);
	rev.resize(n);
	dist.resize(n, md);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		rev[v].push_back(u);
	}
	cin >> k;
	p.resize(k);
	for (auto &i : p) cin >> i, --i;

	queue<int> q;
	q.push(p.back());
	dist[p.back()] = 0;
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (const auto &i : rev[x]) {
			if (1 + dist[x] <= dist[i]) {
				t.insert({ x, i });
				if (1 + dist[x] < dist[i]) {
					dist[i] = 1 + dist[x];
					q.push(i);
				}
			}
		}
	}
	int lo = 0, hi = 0;
	for (int i = 0; i + 1 < p.size(); i++) {
		if (!t.count({ p[i + 1], p[i] }))
			lo++;
		for (const auto &x : g[p[i]])
			if (x != p[i + 1] && t.count({ x, p[i] })) {
				hi++;
				break;
			}
	}
	cout << lo << " " << hi << endl;
}