#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int fastpow(int n, int x) {
    if (x == 0) return 1;
    int res = fastpow(n, x / 2);
    res = (1ll * res * res) % MOD;
    if (x & 1) res = (1ll * res * n) % MOD;
    return res;
}

int N;
vector<pair<int, int>> Color;
vector<vector<int>> G;

struct SegmentTree {
    int N;
    vector<int> tree;
    vector<int> lazy;

    SegmentTree() {}
    
    void init(int n) {
        N = n;
        tree.resize(4 * n);
        lazy.resize(4 * n);
    }

    inline void lazydown(int n, int tl, int tr) {
        if (!lazy[n]) return;

        int mid = (tl + tr) / 2;

        tree[n * 2] = (1ll * tree[n * 2] + 1ll * lazy[n] * (mid - tl + 1)) % MOD;
        tree[n * 2 + 1] = (1ll * tree[n * 2 + 1] + 1ll * lazy[n] * (tr - mid)) % MOD;

        lazy[n * 2] = (1ll * lazy[n * 2] + lazy[n]) % MOD;
        lazy[n * 2 + 1] = (1ll * lazy[n * 2 + 1] + lazy[n]) % MOD;

        lazy[n] = 0;
    }

    void update(int n, int tl, int tr, int le, int ri, int x) {
        if (tr < le || ri < tl || tl > tr) return;
        if (le <= tl && tr <= ri) {
            tree[n] = (((1ll * tree[n] + (1ll * x * (tr - tl + 1)) % MOD) % MOD) + MOD) % MOD;
            lazy[n] = (((1ll * lazy[n] + x) % MOD) + MOD) % MOD;
            return;
        }

        lazydown(n, tl, tr);
        int mid = (tl + tr) / 2;
        update(n * 2, tl, mid, le, ri, x);
        update(n * 2 + 1, mid + 1, tr, le, ri, x);
        tree[n] = (1ll * tree[n * 2] + tree[n * 2 + 1]) % MOD;
    }

    int query(int n, int tl, int tr, int le, int ri) {
        if (tr < le || ri < tl || tl > tr) return 0;
        if (le <= tl && tr <= ri) return tree[n];
        lazydown(n, tl, tr);
        int mid = (tl + tr) / 2;
        return (1ll * query(n * 2, tl, mid, le, ri) + query(n * 2 + 1, mid + 1, tr, le, ri)) % MOD; 
    }

    void update(int le, int ri, int x) {
        return update(1, 0, N - 1, le, ri, x);
    }

    int query(int le, int ri) {
        return (1ll * query(1, 0, N - 1, le, ri) + MOD) % MOD;
    }

};

namespace HeavyLight {
    vector<int> par;
    void dfs_par(int v = 0, int p = -1) {
        par[v] = p;
        for (auto u : G[v]) if (u != p) {
            dfs_par(u, v);
        }
    }

    vector<int> sz, depth;
    void dfs_sz(int v = 0, int d = 0) {
        sz[v] = 1;
        depth[v] = d;
        for (auto &u : G[v]) {
            dfs_sz(u, d + 1);
            sz[v] += sz[u];
            if (sz[u] > sz[G[v][0]]) {
                swap(u, G[v][0]);
            }
        }
    }

    vector<int> in, out, root;
    void dfs_hld(int v = 0) {
        static int t = 0;
        if (v == 0) root[v] = 0;
        in[v] = t++;
        for (auto u : G[v]) {
            root[u] = (u == G[v][0])? root[v] : u;
            dfs_hld(u);
        }
        out[v] = t - 1;
    }
}

using namespace HeavyLight;

SegmentTree Path;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;
    
    G.resize(N);
    in.resize(N);
    out.resize(N);
    par.resize(N);
    root.resize(N);
    sz.resize(N);
    depth.resize(N);
    
    vector<int> W(N);
    int P = 1;
    vector<pair<int, pair<int, int>>> events; // time(color), node and type

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a,     {i, +1}});
        events.push_back({b + 1, {i, -1}});
        W[i] = fastpow(b - a + 1, MOD - 2);
        P = (1ll * (b - a + 1) * P) % MOD;
    }

    
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs_par();
    G.clear(); G.resize(N);
    for (int i = 1; i < N; i++) {
        G[par[i]].emplace_back(i);
    }    

    dfs_sz();
    dfs_hld();

    Path.init(2 * N);

    sort(events.begin(), events.end());

    int sumLCA = 0;     // 2 * sumLCA must be decreased to the answer
    int sumW = 0;       // sum of weight[i]
    int sumDW = 0;      // sum of depth[i] * weight[i]
    int sumOff = 0;     // sum of depth[i] * weight[i] * weight[i]

    int maxC = events.back().first;
    int curEvents = 0;

    int ans = 0;

    for (int i = 1; i <= maxC; i++) {
        while (curEvents < events.size() && events[curEvents].first <= i) {
            int n = events[curEvents].second.first;

            if (events[curEvents].second.second == 1) {
                sumW = (1ll * sumW + W[n]) % MOD;
                sumDW = (1ll * sumDW + ((1ll * depth[n] * W[n]) % MOD)) % MOD;
                sumOff = (1ll * sumOff + ((1ll * ((1ll * depth[n] * W[n]) % MOD) * W[n]) % MOD)) % MOD;
                
                int Add = 0;
                
                /* Get values of path from n to 1 */
                int v = n;
                while (v != -1) {
                    Add = (Add + Path.query(in[root[v]], in[v])) % MOD;     
                    v = par[root[v]];               
                }
                Add = (Add - Path.query(0, 0)) % MOD;

                Add = (1ll * Add * W[n]) % MOD;
                sumLCA = (1ll * sumLCA + Add) % MOD;

                /* Update path */
                v = n;
                while (v != -1) {
                    Path.update(in[root[v]], in[v], W[n]);
                    v = par[root[v]];
                }


            } else {
                sumW = (1ll * sumW - W[n]) % MOD; sumW = (sumW + MOD) % MOD;
                sumDW = (1ll * sumDW - ((1ll * depth[n] * W[n]) % MOD)) % MOD; sumDW = (sumDW + MOD) % MOD;
                sumOff = (1ll * sumOff - ((1ll * ((1ll * depth[n] * W[n]) % MOD) * W[n]) % MOD)) % MOD; sumOff = (sumOff + MOD) % MOD;
                
                int Add = 0;

                /* Update Path from n to 0 */
                int v = n;
                while (v != -1) {
                    Path.update(in[root[v]], in[v], MOD - W[n]);
                    v = par[root[v]];
                }
                
                /* Get values of path */
                v = n;
                while (v != -1) {
                    Add = (Add + Path.query(in[root[v]], in[v])) % MOD;     
                    v = par[root[v]];               
                }

                Add = (Add - Path.query(0, 0)) % MOD;

                Add = (1ll * Add * W[n]) % MOD;
                sumLCA = (1ll * sumLCA - Add) % MOD;

            }

            curEvents++;
        }

        ans = (((1ll * ans + 1ll * sumW * sumDW - sumOff - 2ll * sumLCA) % MOD) + MOD) % MOD;
    }

    ans = (1ll * ans * P) % MOD;
    cout << ans << "\n";
    return 0;
}