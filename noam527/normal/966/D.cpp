#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m;
vector<vector<int>> g, d;
vector<int> dist, vis, pre;
queue<int> q;
int ans = inf;

void bfs() {
	for (auto &i : dist) i = inf;
	for (auto &i : vis) i = 0;

	q.push(0);
	dist[0] = 0;
	vis[0] = 1;
	pre[0] = -1;
	int x;
	while (!q.empty()) {
		x = q.front(), q.pop();
		for (const auto &i : g[x]) {
			if (!vis[i]) {
				vis[i] = 1;
				dist[i] = 1 + dist[x];
				pre[i] = x;
				q.push(i);
				if (i == n - 1) {
					ans = dist[i];
					return;
				}
			}
		}
	}
}

vector<int> path(int to) {
	vector<int> a;
	int at = to;
	while (at != -1) {
		a.push_back(at);
		at = pre[at];
	}
	reverse(a.begin(), a.end());
	return a;
}

void makeans() {
	vector<int> a = path(n - 1);
	cout << a.size() - 1 << endl;
	for (const auto &i : a) cout << i + 1 << " "; cout << endl;
	exit(0);
}

void bfs2(int v) {
	vis[v] = 1;
	vector<int> t;
	vector<int> a, b = path(v);
	for (const auto &i : b) vis[i] = 1;
	for (const auto &i : g[v]) {
		if (!vis[i]) {
			t.push_back(i), vis[i] = 1;
		}
	}
	for (const auto &i : t) {
		for (const auto &j : g[i]) {
			if (!vis[j]) {
				a.push_back(v);
				a.push_back(i);
				a.push_back(j);
				a.push_back(v);
				a.push_back(n - 1);
				b.pop_back();
				cout << b.size() + a.size() - 1 << endl;
				for (const auto &i : b) cout << i + 1 << " ";
				for (const auto &i : a) cout << i + 1 << " "; cout << endl;
				exit(0);
			}
		}
	}
	for (const auto &i : g[v]) vis[i] = 0;
	for (const auto &i : b) vis[i] = 0;
}

bool cmp(const int &aa, const int &bb) {
	return g[aa].size() < g[bb].size();
}

int main() {
	fast;
	cin >> n >> m;
	g.resize(n);
	d.resize(n);
	dist.resize(n);
	vis.resize(n);
	pre.resize(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs();
	for (auto &i : vis) i = 0;
	for (int i = 0; i < n; i++)
		if (dist[i] < inf) d[dist[i]].push_back(i);
	for (int i = 0; i < n; i++) sort(d[i].begin(), d[i].end(), cmp);
	for (int i = 0; i < n; i++) {
		if (ans < i + 4) makeans();
		for (const auto &j : d[i]) bfs2(j);
	}
	if (dist[n - 1] != inf) makeans();
	cout << -1 << endl;
}