#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 1005, M = 100005;
int n, m, d[N], q[N], idx;
vector <int> G[N], bcc[N];
int dfs(int u) {
	bcc[idx].pb(u);
	for(int v : G[u])
	if(d[v] ? d[v] == d[u] : (d[v] = 3 - d[u], !dfs(v))) return 0;
	return 1;
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	int u, v;
	while(m--) scanf("%d%d", &u, &v), G[u].pb(v), G[v].pb(u);
	rep(i, 1, n) if(!d[i]) {
		d[i] = 1, idx++;
		if(!dfs(i)) puts("-1"), exit(0);
	}
	int as = 0;
	rep(i, 1, idx) {
		int ma = 0;
		for(int s : bcc[i]) {
			mem(d, 0), q[1] = s, d[s] = 1;
			for(int l = 1, r = 1, u; u = q[l], l <= r; l++) for(int v : G[u])
			if(!d[v]) ma = max(ma, d[u]), d[v] = d[u] + 1, q[++r] = v;
		}
		as += ma;
	}
	cout << as;
	return 0;
}