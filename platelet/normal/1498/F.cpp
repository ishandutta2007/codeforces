#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, K, a[N];
ll f[N][40], ans[N];
vector <int> G[N];
void add(int u, int v) {
	For(i, 0, K) f[u][(i + 1) % K] ^= f[v][i];
}
void dfs(int u, int fa) {
	f[u][0] = a[u];
	for(int v : G[u]) if(v ^ fa) dfs(v, u), add(u, v);
}
void Dfs(int u, int fa) {
	For(i, K / 2, K) ans[u] ^= f[u][i];
	for(int v : G[u]) if(v ^ fa) add(u, v), add(v, u), Dfs(v, u), add(v, u), add(u, v);
}
int main() { 
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n >> K, K *= 2;
	int u, v;
	rep(i, 2, n) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	rep(i, 1, n) scanf("%d", &a[i]);
	dfs(1, 0), Dfs(1, 0);
	rep(i, 1, n) printf("%d ", ans[i] != 0);
	return 0;
}