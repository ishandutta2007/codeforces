#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define SZ(x) int((x).size())

using namespace std;
using ll = long long;
using cmp = complex<int>;
const int N = 2e5 + 5;

int n, q, ans[N];
vector<int> G[N];
vector<pair<int, int>> Q[N];
vector<cmp> f[N];
int slp(const cmp& a) {
    return imag(a) / real(a);
}

void dfs(int u, int fa) {
    for(int v : G[u]) if(v != fa) {
        dfs(v, u);
        vector<cmp> t; swap(t, f[u]);
        for(int i = 0, j = 0; i < SZ(t) || j < SZ(f[v]);)
        if(j == SZ(f[v]) || (i < SZ(t) && slp(t[i]) <= slp(f[v][j]))) f[u].pb(t[i++]);
        else if(i && slp(f[u].back()) == slp(f[v][j])) f[u].back() += f[v][j++];
        else f[u].pb(f[v][j++]);
    }
    for(auto [k, i] : Q[u]) {
        cmp sum;
        for(const cmp& x : f[u]) if(slp(x) >= k) sum += x;
        ans[i] = imag(sum) + SZ(G[u]) - (u > 1) - k * real(sum);
    }
    cmp t(1, SZ(G[u]) - (u > 1) - 1);
    while(SZ(f[u]) && slp(t) <= slp(f[u].back())) t += f[u].back(), f[u].pop_back();
    if(imag(t) > 0) f[u].pb(t);
}
int main() {
#ifdef local
    freopen("in", "r", stdin);
#endif
    cin >> n;
    int u, v;
    rep(i, 2, n) scanf("%d%d", &u, &v), G[u].pb(v), G[v].pb(u);
    cin >> q;
    rep(i, 1, q) scanf("%d%d", &u, &v), Q[u].emplace_back(v, i);
    dfs(1, 0);
    rep(i, 1, q) printf("%d\n", ans[i]);
}