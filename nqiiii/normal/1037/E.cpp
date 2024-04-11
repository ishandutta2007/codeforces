#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
int n, m, k, deg[maxn + 10], cnt, l[maxn + 10], r[maxn + 10], ans[maxn + 10];
vector<pair<int, int> > g[maxn + 10];
bool vis[maxn + 10];

struct node {
	int id, d;
	bool operator < (const node & t) const {
		return d > t.d;
	}
};

priority_queue<node> hp;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		g[l[i]].push_back(make_pair(r[i], i)); g[r[i]].push_back(make_pair(l[i], i));
		++deg[l[i]]; ++deg[r[i]];
	}
	for (int i = 1; i <= n; ++i)
		hp.push((node){i, deg[i]});
	for (int i = m; i >= 1; --i) {
		while (!hp.empty() && hp.top().d < k) {
			node p = hp.top(); hp.pop();
			if (deg[p.id] != p.d) continue;
			vis[p.id] = 1; ++cnt;
			for (int j = 0; j < g[p.id].size(); ++j) {
				pair<int, int> e = g[p.id][j];
				if (e.second <= i && !vis[e.first]) hp.push((node){e.first, --deg[e.first]});
			}
		}
		ans[i] = n - cnt;
		if (!vis[l[i]] && !vis[r[i]]) {
			hp.push((node){l[i], --deg[l[i]]});
			hp.push((node){r[i], --deg[r[i]]});
		}
	}
	for (int i = 1; i <= m; ++i)
		printf("%d\n", ans[i]);
}