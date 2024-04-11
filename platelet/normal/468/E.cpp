#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#pragma GCC target("popcnt")

using namespace std;
using ll = long long;

const int N = 1e5 + 5, P = 1e9 + 7;

int A, B, fac[N], ix[N], iy[N];
vector<pair<int, int>> G[105], T[105];
vector<int> L, R;
vector<tuple<int, int, int>> e;
int f[1 << 18], g[1 << 18], dp[105][55][2], tmp[55][2];
int idx, dfn[105];
bool used[105];

inline void inc(int& a, int b) {
    if((a += b) >= P) a -= P;
}
inline void inc(int& a, ll b) {
    a = (a + b) % P;
}
void dfs(int u, bool side) {
    dfn[u] = ++idx, side ? R.pb(u) : L.pb(u);
    for(auto [v, w] : G[u]) if(!dfn[v])
        T[u].eb(v, w), dfs(v, !side);
    else if(dfn[v] > dfn[u]) e.eb(u, v, w);
}
int Dfs(int u) {
    mem(dp[u], 0);
    (used[u] ? dp[u][0][1] : dp[u][0][0]) = 1;
    int szu = !used[u];
    for(auto [v, w] : T[u]) {
        int szv = Dfs(v);
        mem(tmp, 0);
        rep(i, 0, szu >> 1) rep(j, 0, szv >> 1) {
            ll x = dp[v][j][0] + dp[v][j][1];
            inc(tmp[i + j][0], dp[u][i][0] * x);
            inc(tmp[i + j][1], dp[u][i][1] * x);
            inc(tmp[i + j + 1][1], dp[u][i][0] * (ll)dp[v][j][0] % P * w);
        }
        memcpy(dp[u], tmp, sizeof tmp), szu += szv;
    }
    return szu;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    mem(ix, -1), mem(iy, -1);
    cin >> A >> B;
    rep(i, 0, A) fac[i] = i ? (ll)fac[i - 1] * i % P : 1;
    int x, y, z, idx = 0;
    rep(i, 1, B) {
        cin >> x >> y >> z, z = (z + P - 1) % P;
        if(ix[x] < 0) ix[x] = idx++;
        if(iy[y] < 0) iy[y] = idx++;
        G[ix[x]].eb(iy[y], z), G[iy[y]].eb(ix[x], z);
    }
    int dp[55] = {};
    dp[0] = 1;
    For(kase, 0, idx) if(!dfn[kase]) {
        L.clear(), R.clear(), e.clear();
        For(i, 0, idx) T[i].clear();
        dfs(kase, 0);
        int n = L.size(), m = R.size();
        int now[55] = {};
        if(min(n, m) <= 18) {
            if(n < m) swap(L, R), swap(n, m);
            memset(f, 0, 4 << m), f[0] = 1;
            for(int i : L) {
                memcpy(g, f, 4 << m);
                for(auto [j, w] : G[i]) {
                    int k = 1 << find(all(R), j) - R.begin();
                    for(int Sh = 0; Sh < 1 << m; Sh += k << 1)
                        for(int S = Sh; S < Sh + k; S++)
                            f[S + k] = (f[S + k] + (ll)g[S] * w) % P;
                }
            }
            For(S, 0, 1 << m) inc(now[__builtin_popcount(S)], f[S]);
        } else For(S, 0, 1 << e.size()) {
            mem(used, 0);
            ll p = 1;
            For(i, 0, e.size()) if(S >> i & 1) {
                auto [u, v, w] = e[i];
                if(used[u] || used[v]) p = 0;
                used[u] = used[v] = 1, p = p * w % P;
            }
            if(!p) continue;
            int sz = Dfs(kase);
            rep(i, 0, sz >> 1) inc(now[i + __builtin_popcount(S)], p * (::dp[kase][i][0] + ::dp[kase][i][1]));
        }
        per(i, B, 0) {
            int res = 0;
            rep(j, 0, i) inc(res, (ll)dp[j] * now[i - j]);
            dp[i] = res;
        }
    }
    int ans = 0;
    rep(i, 0, min(A, B)) inc(ans, (ll)dp[i] * fac[A - i]);
    cout << ans;
}