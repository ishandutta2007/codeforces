#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#pragma GCC target("bmi")

using namespace std;

const int N = 1e5 + 5;

int n, q, a[N], ans[N], pre[N];
int sz = 1, nw = 1, f[N << 2], len[N << 2], pos[N << 2];
map<int, int> ch[N << 2];
int fa[20][N << 2], c[N];
vector<int> G[N << 2];
vector<tuple<int, int, int>> Q[N << 2];

void add(int i) {
    for(; i <= n; i += i & -i) c[i]++;
}
int qry(int i) {
    int r = 0;
    for(; i; i &= i - 1) r += c[i];
    return r;
}

void ins(int c) {
    int u = ++sz;
    len[u] = len[nw] + 1;
    while(nw && !ch[nw][c]) ch[nw][c] = u, nw = f[nw];
    if(!nw) f[u] = 1;
    else {
        int v = ch[nw][c];
        if(len[v] > len[nw] + 1) {
            f[++sz] = f[v], ch[sz] = ch[v];
            f[v] = f[u] = sz, len[sz] = len[nw] + 1;
            while(ch[nw][c] == v) ch[nw][c] = sz, nw = f[nw];
        } else f[u] = v;
    }
    nw = u;
}
void dfs(int u) {
    for(auto [l, r, i] : Q[u]) ans[i] -= qry(r) - qry(l - 1);
    if(pos[u]) add(pos[u]);
    for(int v : G[u]) dfs(v);
    for(auto [l, r, i] : Q[u]) ans[i] += qry(r) - qry(l - 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n, n--;
    rep(i, 0, n) cin >> a[i];
    per(i, n, 1) a[i] -= a[i - 1];
    rep(i, 1, n) ins(a[i]), pos[nw] = i;
    rep(i, 1, n) ins(-a[i]), pre[i] = nw;
    rep(i, 1, sz) fa[0][i] = f[i], G[f[i]].pb(i);
    rep(i, 1, 19) rep(j, 1, sz) fa[i][j] = fa[i - 1][fa[i - 1][j]];
    cin >> q;
    int l, r;
    rep(i, 1, q) {
        cin >> l >> r, r--;
        if(l > r) { ans[i] = n; continue; }
        int le = r - l + 1;
        int u = pre[r];
        per(j, 19, 0) if(len[fa[j][u]] >= le) u = fa[j][u];
        if(le <= l - 2) Q[u].eb(le, l - 2, i);
        if(r * 2 - l + 2 <= n) Q[u].eb(r * 2 - l + 2, n, i);
    }
    dfs(0);
    rep(i, 1, q) cout << ans[i] << '\n';
}