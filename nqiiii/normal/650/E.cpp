#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000;

int n, fg[maxn + 10], fz[maxn + 10], tp[maxn + 10];
vector<int> g[maxn + 10], z[maxn + 10];
vector<pair<pair<int, int>, pair<int, int> > > ans;

void dfsg(int p) {
	for (int i = 0; i < g[p].size(); ++i) {
		int e = g[p][i];
		if (e != fg[p]) {
			fg[e] = p; dfsg(e);
		}
	}
}

void dfsz(int p) {
	if (p != 1 && (fg[p] == fz[p] || fg[fz[p]] == p)) tp[p] = tp[fz[p]];
	else tp[p] = p;
	for (int i = 0; i < z[p].size(); ++i) {
		int e = z[p][i];
		if (e != fz[p]) {
			fz[e] = p; dfsz(e);
		}
	}
}

void dfs(int p) {
	for (int i = 0; i < g[p].size(); ++i) {
		int e = g[p][i];
		if (e != fg[p]) {
			dfs(e);
			if (e != fz[p] && p != fz[e])
				ans.push_back(make_pair(make_pair(p, e), make_pair(tp[e], fz[tp[e]])));
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		g[l].push_back(r); g[r].push_back(l);	
	}
	for (int i = 1; i < n; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		z[l].push_back(r); z[r].push_back(l);
	}
	dfsg(1); dfsz(1);
	dfs(1);
	printf("%d\n", ans.size());
	for (auto i: ans)
		printf("%d %d %d %d\n", i.first.first, i.first.second, i.second.first, i.second.second);
}