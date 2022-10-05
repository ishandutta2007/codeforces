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
const int md = 998244353;
const ll inf = 2e18;
const int OO = 0;
using namespace std;

struct edge {
	int to, w;
	edge() {}
	edge(int tt, int ww) {
		to = tt;
		w = ww;
	}
	bool operator < (const edge &e) const {
		return w > e.w;
	}
};

struct edge2 {
	int to, w, layer;
	edge2() {}
	edge2(int tt, int ww, int lay) {
		to = tt;
		w = ww;
		layer = lay;
	}
	bool operator < (const edge2 &e) const {
		return w > e.w;
	}
};

ll pw(ll b, ll e) {
	ll rtn = 1;
	while (e) {
		if (e & 1) rtn = rtn * b % md;
		e /= 2, b = b * b % md;
	}
	return rtn;
}

const int L = 20;

int n, m;
vector<vector<int>> g;

vector<vector<edge>> step;
vector<int> mn;

vector<vector<int>> dist;

void solve() {
	cin >> n >> m;
	g.resize(n);
	step.resize(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		step[u].push_back(edge(v, 0));
		step[v].push_back(edge(u, 1));
	}

	mn.resize(n, -1);
	priority_queue<edge> q;
	q.push(edge(0, 0));
	while (q.size()) {
		edge x = q.top();
		q.pop();
		if (mn[x.to] != -1) continue;
		mn[x.to] = x.w;
		for (const auto &i : step[x.to]) {
			if (mn[i.to] == -1) {
				edge nxt(i.to, x.w);
				if (x.w % 2 == 0)
					nxt.w += i.w;
				else
					nxt.w += 1 - i.w;
				q.push(nxt);
			}
		}
	}
	
	dist.resize(n, vector<int>(L, -1));
	priority_queue<edge2> q2;

	q2.push(edge2(0, 0, 0));
	while (q2.size()) {
		edge2 x = q2.top();
		q2.pop();
		if (dist[x.to][x.layer - mn[x.to]] != -1) continue;
		dist[x.to][x.layer - mn[x.to]] = x.w;
		for (const auto &i : step[x.to]) {
			edge2 nxt(i.to, x.w + 1, x.layer);
			if (x.layer % 2 == 0)
				nxt.layer += i.w;
			else
				nxt.layer += 1 - i.w;
			if (nxt.layer - mn[i.to] >= L) continue;
			q2.push(nxt);
		}
	}
	if (OO) {
		cout << "mn:\n";
		for (const auto &i : mn) cout << i << " "; cout << '\n';
	}
	if (mn[n - 1] >= 30) {
		cout << ((pw(2, mn[n - 1]) - 1 + dist[n - 1][0]) % md + md) % md << '\n';
		return;
	}
	if (OO) {
		for (const auto &i : dist[n - 1]) cout << i << " "; cout << '\n';
	}
	ll best = 2e18;
	for (int i = 0; i < L; i++) {
		if (dist[n - 1][i] != -1) {
			ll cur = pw(2, mn[n - 1] + i) - 1 + dist[n - 1][i];
			best = min(best, cur);
		}
	}
	cout << best % md << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
//	cin >> tst;
	while (tst--) {
		solve();
	}
}