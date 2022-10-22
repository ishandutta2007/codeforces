#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 5005;

int n, m, vs[N], d[N], as;
vector <int> G[N];

int dfs(int u, int v, int s) {
	vs[u] = s;
	if(G[u].size() < as) return G[u].pb(v), 1;
	for(int& w : G[u]) if(vs[w] < s && dfs(w, u, s)) return w = v;
	return 0;
}

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	int u, v;
	rep(i, 1, m) {
		scanf("%d%d", &u, &v);
		if(!dfs(u, v, i * 2) && !dfs(v, u, i * 2 + 1)) as++, G[u].pb(v);
	}
	cout << as << endl;
	rep(u, 1, n) for(int v : G[u]) printf("%d %d\n", u, v);
	return 0;
}