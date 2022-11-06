#include <bits/stdc++.h>
#include <unistd.h>
#define pb push_back
#define mp make_pair
#define int long long

using namespace std;

std::vector<std::vector<pair<int, int> > > adj;
std::vector<std::vector<int> > up, up1;
std::vector<int> depth, pa, siz, closestred;
int l;

int lcamaxdist(int a, int b) {
	int y = 0;
	if (depth[a] > depth[b]) swap(a, b);
	int d = depth[b] - depth[a];
	for (int i = 0; i <= l; ++i) {
		if (d & (1 << i)) {
			y = max(y, up1[b][i]);
			b = up[b][i];
		}
	}
	if (a == b) return y;
	for (int i = l; i >= 0 ; --i) {
		if (up[a][i] != up[b][i]) {
			y = max(y, max(up1[a][i], up1[b][i]));
			a = up[a][i], b = up[b][i];
		}
	}
	y = max(y, max(up1[a][0], up1[b][0]));
	return y;
}
void _pre_dfs(int u) {
	for (auto v : adj[u])
		if (v.first != up[u][0])
		{
			up[v.first][0] = u;
			up1[v.first][0] = v.second;
			depth[v.first] = depth[u] + 1;
			_pre_dfs(v.first);
		}
}

void init(int n) {
	l = ceil(log2(n));
	up.assign(n, std::vector<int> (l + 1));
	depth.resize(n);
	up1.assign(n, std::vector<int> (l + 1));
	up[0][0] = 0;
	depth[0] = 0;
	up1[0][0] = 0ll;
	_pre_dfs(0);
	for (int i = 1; i <= l; ++i)
		for (int u = 0; u < n; ++u) {
			up[u][i] = up[up[u][i - 1]][i - 1];
			up1[u][i] = max(up1[up[u][i - 1]][i - 1], up1[u][i - 1]);
		}
}

#define MAXN 200002

vector< pair<int, int> > adj1[MAXN];
bool marked[MAXN] = {false};
#define PII pair<pair<int, int>, int>
priority_queue< PII, vector<PII>, greater<PII> > pq;

int prim(int x) {
	int mincost = 0;
	pq.push(mp(mp(0, x), -1));
	while (!pq.empty()) {
		PII p = pq.top();
		pq.pop();
		x = p.first.second;
		if (marked[x] == true) {
			continue;
		}
		mincost += p.first.first;
		marked[x] = true;
		if (p.second != -1) {
			adj[x].pb({p.second, p.first.first});
			adj[p.second].pb({x, p.first.first});
		} 
		for (int i = 0; i < adj1[x].size(); i++) {
			int y = adj1[x][i].second;
			if (!marked[y]) {
				pq.push({adj1[x][i], x});
			}
		}
	}
	return mincost;
}



int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);

	int n; cin >> n;
	int m; cin >> m;
	std::vector< pair< pair<int, int>, int > > ed;
	for (int i = 0; i < m; i++) {
		int x, y, weight;
		cin >> x >> y >> weight; x--; y--;
		adj1[x].pb(mp(weight, y));
		adj1[y].pb(mp(weight, x));
		ed.pb({{x, y}, weight});
	}
	adj.resize(n);
	int mincost = prim(0);
	init(n);
	for (int i = 0; i < m; ++i) {
		int y = lcamaxdist(ed[i].first.first, ed[i].first.second);
		cout << (mincost - y + ed[i].second) << "\n";
	}
}