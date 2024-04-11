#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define upd(a, b) (a = max(a, b))

using namespace std;

const int N = 205;

int n, k, a[N], f[N][N], g[N];
vector<int> G[N];

void dfs(int u, int fa) {
    f[u][0] = a[u];
    for(int v : G[u]) if(v ^ fa) {
        dfs(v, u), mem(g, 0);
        rep(i, 0, n) rep(j, max(k - i, 0), n) upd(g[min(i, j + 1)], f[u][i] + f[v][j]);
        rep(i, 0, n) f[u][i] = g[i];
    }
}

int main() {
#ifdef local
    freopen("in", "r", stdin);
#endif
    cin >> n >> k;
    rep(i, 1, n) scanf("%d", &a[i]);
    int u, v;
    rep(i, 2, n) scanf("%d%d", &u, &v), G[u].pb(v), G[v].pb(u);
    dfs(1, 0);
    int as = 0;
    rep(i, 0, k) upd(as, f[1][i]);
    cout << as;
}