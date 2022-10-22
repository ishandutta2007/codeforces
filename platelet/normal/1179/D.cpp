#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define sqr(x) (1LL*(x)*(x))

using namespace std;
const int N = 5e5 + 5;
typedef long long ll;
int n, sz[N], K[N]; ll f[N]; vector <int> G[N];
void dfs(int u, int fa) {
	sz[u] = 1; if(fa && G[u].size() == 1) f[K[u] = u] = 1;
	for(int v : G[u]) if(v ^ fa) dfs(v, u), sz[u] += sz[v];
	for(int v : G[u]) if(v ^ fa && f[v] + sqr(sz[u] - sz[v]) < f[u])
		f[u] = f[v] + sqr(sz[u] - sz[v]), K[u] = K[v];
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n; int u, v;
	rep(i, 2, n) scanf("%d%d", &u, &v), G[u].push_back(v), G[v].push_back(u);
	mem(f, 63), dfs(1, 0), mem(f, 63);
	int rt = K[1]; dfs(rt, 0), cout << (n * (2 * n - 1LL) - f[rt]) / 2;
	return 0;
}