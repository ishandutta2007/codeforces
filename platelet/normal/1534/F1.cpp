#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define upd(a, b) (a = min(a, b))

using namespace std;
using ll = long long;

const int N = 4e5 + 5;

int n, m, id, idx, dfn[N], stk[N], tp;
string a[N];
int sid, co[N], d[N];
vector<int> G[N];
map<int, int> p[N];

int dfs(int u) {
    int low = dfn[u] = ++idx;
    stk[++tp] = u;
    for(int v : G[u]) if(!dfn[v]) upd(low, dfs(v));
    else if(!co[v]) upd(low, dfn[v]);
    if(low == dfn[u]) {
        sid++; int v;
        do v = stk[tp--], co[v] = sid; while(v ^ u);
    }
    return low;
}

int main() {
#ifdef local
	freopen(".in", "r", stdin);
#endif
    cin >> n >> m;
    rep(i, 1, n) a[i].resize(m + 2), scanf("%s", &a[i][1]);
    rep(i, 1, n) rep(j, 1, m) if(a[i][j] == '#') p[j][i] = ++id;
    rep(i, 0, m + 1) p[i][n + 1] = 0;
    rep(i, 1, n) rep(j, 1, m) if(a[i][j] == '#') {
        int u = p[j][i], v;
        if(a[i - 1][j] == '#') G[u].pb(p[j][i - 1]);
        v = p[j].upper_bound(i) -> second;
        if(v) G[u].pb(v);
        v = p[j - 1].lower_bound(i) -> second;
        if(v) G[u].pb(v);
        v = p[j + 1].lower_bound(i) -> second;
        if(v) G[u].pb(v);
    }
    rep(i, 1, id) if(!dfn[i]) dfs(i);
    rep(u, 1, id) for(int v : G[u]) if(co[v] ^ co[u]) d[co[v]]++;
    int as = 0;
    rep(i, 1, sid) as += !d[i];
    cout << as;
    return 0;
}