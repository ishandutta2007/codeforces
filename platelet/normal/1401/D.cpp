#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define repe for(int i = head[u], v; v = e[i].v; i = e[i].nxt) if(v ^ fa)

using namespace std;
const int N = 1e5 + 5, P = 1e9 + 7;
typedef long long ll;
int t, n, m, u, v, sz[N], cnt, head[N]; ll p[N], mul[N];
struct edge { int v, nxt; } e[N*2];
void add(int u, int v) {
	e[++cnt] = (edge){ v, head[u] };
	head[u] = cnt;
}
void dfs(int u, int fa) {
	sz[u] = 1;
	for(int i = head[u], v; v = e[i].v; i = e[i].nxt)
	if(v ^ fa) dfs(v, u),
	sz[u] += sz[v], mul[(i+1)/2] = (ll)sz[v] * (n - sz[v]);
}
int main() {
	for(cin >> t; t--;) {
		cin >> n, cnt = 0;
		rep(i, 1, n) head[i] = 0;
		rep(i, 2, n) scanf("%d%d", &u, &v), add(u, v), add(v, u);
		dfs(1, 0), sort(mul + 1, mul + n);
		cin >> m;
		rep(i, 1, m) scanf("%d", &p[i]);
		rep(i, m + 1, n - 1) p[i] = 1;
		sort(p + 1, p + max(m + 1, n));
		while(m >= n) p[m-1] = p[m-1] * p[m] % P, m--;
		ll ans = 0;
		rep(i, 1, n - 1) ans = (ans + mul[i] * p[i]) % P;
		cout << ans << endl;
	}
	return 0;
}