//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1e4;
bool mark[maxn];
int deg[maxn],
	comp[maxn],
	compcnt,
	n, m, s;
vector<int> adj[maxn],
	jda[maxn];
stack<int> stc;

void dfs(int u) {
	mark[u] = true;
	for (auto v : adj[u])
		if (!mark[v])
			dfs(v);
	stc.push(u);
}

void sfd(int u) {
	mark[u] = true;
	comp[u] = compcnt;
	for (auto v : jda[u])
		if (!mark[v])
			sfd(v);
		else if (comp[v] != compcnt)
			deg[compcnt]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	s--;
	for (int i = 0; i < m; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		jda[se].PB(fi);
	}
	for (int i = 0; i < n; i++)
		if (!mark[i])
			dfs(i);
	memset(mark, false, sizeof mark);
	while (sz(stc)) {
		int u = stc.top();
		stc.pop();
		if (mark[u])
			continue;
		sfd(u);
		compcnt++;
	}

	int ans = 0;
	for (int i = 0; i < compcnt; i++)
		if (deg[i] == 0 and i != comp[s])
			ans++;
	cout << ans << endl;
	return 0;
}