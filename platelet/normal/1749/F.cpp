#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back

using namespace std;
using ll = long long;

const int N = 2e5 + 8;

int n, m, idx, fa[N], dl[N], dr[N], sum[21][N];
ll st[18][N];
vector<int> G[N];
struct {
    int c[N];
    inline void add(int i, int v) {
        for(; i <= n; i += i & -i) c[i] += v;
    }
    inline int qry(int i, int r = 0) {
        for(; i; i &= i - 1) r += c[i];
        return r;
    }
} T[21];
void dfs(int u, int f, ll d) {
    dl[u] = ++idx, fa[u] = f, st[0][idx] = d + f;
    for(int v : G[u]) if(v != f) dfs(v, u, d + (1LL << 32));
    dr[u] = idx;
}
inline int lca(int u, int v) {
    if(u == v) return u;
    u = dl[u], v = dl[v];
    if(u > v) swap(u, v);
    int z = __builtin_clz(v - u) ^ 31;
    return min(st[z][v], st[z][u + (1 << z)]);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int u, v;
    rep(i, 2, n) cin >> u >> v, G[u].pb(v), G[v].pb(u);
    dfs(1, 0, 0);
    rep(i, 1, 17) rep(j, 1 << i, n) st[i][j] = min(st[i - 1][j], st[i - 1][j - (1 << i - 1)]);
    cin >> m;
    while(m--) {
        int t, u, v, k, d;
        cin >> t >> u;
        if(t == 1) {
            int ans = 0;
            rep(i, 0, 20) {
                ans += sum[i][u] + T[i].qry(dr[u]) - T[i].qry(dl[u] - 1);
                if(!(u = fa[u])) break;
            }
            cout << ans << '\n';
        } else {
            cin >> v >> k >> d;
            T[d].add(dl[u], k), T[d].add(dl[v], k);
            u = lca(u, v);
            T[d].add(dl[u], -k * 2);
            rep(i, 0, d) {
                if(u == 1) {
                    per(j, d - i, 0) sum[j][1] += k;
                    break;
                }
                sum[d - i][u] += k;
                if(i != d) sum[d - i - 1][u] += k;
                u = fa[u];
            }
        }
    }
}