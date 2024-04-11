#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

struct edge {
	int u, v, i, vis;
	edge() {}
	edge(int uu, int vv, int ii) {
		u = uu;
		v = vv;
		i = ii;
		vis = 0;
	}
	int to(int source) {
		return source ^ u ^ v;
	}
};

const int N = 1 << 20;

int n;
vector<pair<int, int>> a;
vector<int> ans;
vector<pair<int, int>> ans2;
vector<edge> e;
vector<int> g[N];

void dfs(int v, vector<int> &build, vector<pair<int, int>> &build2) {
	while (g[v].size()) {
		edge &x = e[g[v].back()];
		g[v].pop_back();
		if (x.vis) continue;
		x.vis = 1;
		dfs(x.to(v), build, build2);
		build.push_back(x.i);
		build2.push_back({ v, x.to(v) });
	}
}

bool work(int d) {
	if (OO) cout << "start work " << d << endl;
	e.clear();
	for (int i = 0; i < d; i++)
		g[i].clear();
	for (int i = 0; i < n; i++) {
		int u = a[i].first % d;
		int v = a[i].second % d;
		g[u].push_back(e.size());
		g[v].push_back(e.size());
		e.push_back(edge(u, v, i));
	}

	for (int i = 0; i < d; i++) {
		if (g[i].size() % 2 == 1) {
			return false;
		}
	}

	int at = -1;
	for (int i = 0; i < d; i++) {
		if (g[i].size()) {
			at = i;
			break;
		}
	}
	if (at == -1) {
		cout << "wtf\n";
	}
	if (OO) {
		cout << "found at " << at << endl;
	}
	vector<int> build;
	vector<pair<int, int>> build2;
	dfs(at, build, build2);
	if (build.size() != n) return false;
	ans = build;
	ans2 = build2;
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i.first >> i.second;
	int d = -1;
	for (int i = 20; i >= 0; i--) {
		if (work(1 << i)) {
			cout << i << endl;
			d = 1 << i;
			break;
		}
	}
	//for (const auto &i : ans) cout << i << " "; cout << endl;
	//for (const auto &i : ans2) cout << i.first << " " << i.second << endl;
	for (int i = 0; i < n; i++) {
		if (ans2[i].first == ans2[i].second) {
			cout << 2 * ans[i] + 1 << " " << 2 * ans[i] + 2 << " ";
		}
		else {
			if (a[ans[i]].first % d == ans2[i].second) {
				cout << 2 * ans[i] + 1 << " " << 2 * ans[i] + 2 << " ";
			}
			else {
				cout << 2 * ans[i] + 2 << " " << 2 * ans[i] + 1 << " ";
			}
		}
	}
}