/**
 * Author   : rama_pang
 * Problem  : https://codeforces.com/contest/620/problem/E
 * Time     : O(N log N)
 * Memory   : O(N)
**/

#include <bits/stdc++.h>
using namespace std;

template<int SZ, int BIT>
struct SegmentTree {
    using lint = long long;

    lint tree[4 * SZ] = {};
    int lazy[4 * SZ] = {};
    
    void push(int n) {
        if (lazy[n]) {
            int c = lazy[n]; lazy[n] = 0;
            
            for (int i = 0; i < 2; i++) {
                tree[n * 2 + i] = 1ll << c;
                lazy[n * 2 + i] = c;
            }
        }
    }

    void update(int n, int tl, int tr, int l, int r, int c) {
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r) {
            tree[n] = 1ll << c;
            lazy[n] = c;
            return;
        }
        int mid = (tl + tr) / 2;
        push(n);
        update(n * 2, tl, mid, l, r, c);
        update(n * 2 + 1, mid + 1, tr, l, r, c);
        tree[n] = (tree[n * 2] | tree[n * 2 + 1]);
    }

    lint query(int n, int tl, int tr, int l, int r) {
        if (r < tl || tr < l) return 0;
        if (l <= tl && tr <= r) return tree[n];
        int mid = (tl + tr) / 2;
        push(n);
        return (query(n * 2, tl, mid, l, r) | query(n * 2 + 1, mid + 1, tr, l, r));
    }

};

const int NMAX = 400005;
const int BITS = 61;

vector<int> adj[NMAX];
int sz[NMAX];
int pos[NMAX];
int ptr = 0;
SegmentTree<NMAX, BITS> seg;

void dfs(int n, int p) {
    pos[n] = ptr++;
    sz[n] = 1;
    for (auto &i : adj[n]) if (i != p) dfs(i, n), sz[n] += sz[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, q; 
    cin >> n >> q;

    vector<int> col;
    for (int i = 1; i <= n; i++) {
        int c; cin >> c;
        col.emplace_back(c);
    }

    for (int i = 2; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    
    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        int c = col[i - 1];
        seg.update(1, 0, ptr - 1, pos[i], pos[i], c);
    }
    
    for (int qi = 0; qi < q; qi++) {
        int type; cin >> type;
        if (type == 1) {
            int v, c;
            cin >> v >> c;
            seg.update(1, 0, ptr - 1, pos[v], pos[v] + sz[v] - 1, c);
        }
        else if (type == 2) {
            int v;
            cin >> v;
            cout << __builtin_popcountll(seg.query(1, 0, ptr - 1, pos[v], pos[v] + sz[v] - 1)) << "\n";
        }

    }

    return 0;
}