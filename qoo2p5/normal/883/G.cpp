#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <memory.h>
#include <iomanip>
#include <set>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define sz(x) ((int) x.size())
#define all(x) (x).begin(), (x).end()

void run();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	run();
#ifdef _DEBUG
	cerr << "OK" << endl;
	while (1);
#endif
	return 0;
}

struct edge {
	int from, to, type, num;
	edge(int f, int to, int t, int n) : from(f), to(to), type(t), num(n) {}

	bool operator<(const edge &e) const {
		return num < e.num;
	}
};

const int MAXN = 5e5 + 123;

vector<edge> initial_edges;
set<edge> ans1, ans2;
bool edges_used[MAXN][2];
bool used[MAXN];
vector<edge> mat[MAXN];

int dfs1(int v) {
	used[v] = true;
	int res = 1;
	for (auto e : mat[v]) {
		int to = e.to;
		if (used[to]) {
			if (e.type && !edges_used[e.num][0]) {
				ans1.insert(e);
				edges_used[e.num][0] = true;
			}
			continue;
		}
		if (e.type && !edges_used[e.num][0]) {
			ans1.insert(e);
			edges_used[e.num][0] = true;
		}
		res += dfs1(to);
	}
	return res;
}

int dfs2(int v) {
	used[v] = true;
	int res = 1;
	for (auto e : mat[v]) {
		int to = e.to;
		if (used[to]) {
			if (e.type && !edges_used[e.num][1]) {
				ans2.insert(e);
				edges_used[e.num][1] = true;
			}
			continue;
		}
		if (e.type && !edges_used[e.num][1]) {
			ans2.insert(e);
			edges_used[e.num][1] = true;
		}
		else 
			res += dfs2(to);
	}
	return res;
}

void run()
{
	int n, m, s;
	cin >> n >> m >> s;
	s--;
	for (int i = 0; i < m; i++) {
		int t, u, v;
		cin >> t >> u >> v;
		u--;
		v--;
		edge r(u, v, t - 1, i);
		edge b(v, u, t - 1, i);
		initial_edges.push_back(r);
		mat[u].push_back(r);
		if (t - 1) {
			mat[v].push_back(b);
		}
	}


	int res1 = dfs1(s);
	fill(used, used + MAXN, 0);
	int res2 = dfs2(s);

	cout << res1 << endl;
	for (auto e : initial_edges) {
		if (!e.type)
			continue;
		if (!edges_used[e.num][0])
			ans1.insert(e);
		if (!edges_used[e.num][1])
			ans2.insert(e);
	}
	for (auto e : ans1) {
		edge real = initial_edges[e.num];
		cout << (real.from == e.from ? '+' : '-');
	}
	cout << endl;

	cout << res2 << endl;
	for (auto e : ans2) {
		edge real = initial_edges[e.num];
		cout << (real.from == e.from ? '-' : '+');
	}
	cout << endl;

}