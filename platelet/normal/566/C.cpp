#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#define cmi(a, b) (a = min(a, b))
#define cma(a, b) (a = max(a, b))
#define fi first
#define se second

using namespace std;
using lf = double;

const int N = 2e5 + 5;

int n, a[N], sz[N], ts, mi, rt, vs[N];
vector<pair<int, int>> G[N];
pair as(1e30, 0);

void find(int u, int fa) {
	sz[u] = 1;
	int ma = 0;
	for(auto [v, w] : G[u]) if(v ^ fa && !vs[v])
        find(v, u), sz[u] += sz[v], cma(ma, sz[v]);
	if(cma(ma, ts - sz[u]) < mi) mi = ma, rt = u;
}
lf su;
void dfs(int u, int fa, int d) {
    su += a[u] * sqrt(d) * d;
    for(auto [v, w] : G[u]) if(v ^ fa) dfs(v, u, d + w);
}
void Dfs(int u, int fa, int d) {
    su += a[u] * sqrt(d);
    for(auto [v, w] : G[u]) if(v ^ fa) Dfs(v, u, d + w);
}
void solve(int u) {
    vs[u] = 1, su = 0, dfs(u, 0, 0), cmi(as, pair(su, u));
    if(ts == 1) return;
    pair nw(-1., 0);
    for(auto [v, w] : G[u]) if(!vs[v]) su = 0, Dfs(v, u, w), cma(nw, pair(su, v));
    find(u, 0), ts = mi = sz[nw.se], find(nw.se, 0), solve(rt);
}
int main() {
    cin >> n;
    rep(i, 1, n) scanf("%d", &a[i]);
    int u, v, w;
    rep(i, 2, n) scanf("%d%d%d", &u, &v, &w), G[u].eb(v, w), G[v].eb(u, w);
    ts = mi = n, find(1, 0), solve(rt);
    printf("%d %lf", as.se, as.fi);
}