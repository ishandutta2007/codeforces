#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int T, n, m, co[N];
ll x[N], y[N];

vector<int> G[N];

int dfs(int u) {
    for(int v : G[u]) if(!co[v]) {
        co[v] = 3 - co[u];
        if(!dfs(v)) return 0;
    } else if(co[v] == co[u]) return 0;
    return 1;
}
void solve() {
    cin >> n >> m;
    rep(i, 1, n) scanf("%lld", &x[i]), G[i].clear(), co[i] = 0;
    rep(i, 1, n) scanf("%lld", &y[i]), y[i] -= x[i];
    int u, v;
    while(m--) scanf("%d%d", &u, &v), G[u].pb(v), G[v].pb(u);
    co[1] = 1;
    if(dfs(1)) {
        ll su = 0;
        rep(i, 1, n) if(co[i] == 1) su += y[i]; else su -= y[i];
        puts(su ? "NO" : "YES");
    } else {
        ll su = 0;
        rep(i, 1, n) su += y[i];
        puts(su & 1 ? "NO" : "YES");
    }
}
int main() {
#ifdef local
    freopen(".in", "r", stdin);
#endif
    int T; for(cin >> T; T--;)
    solve();
}