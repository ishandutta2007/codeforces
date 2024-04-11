/**
 * Author   : rama_pang
 * Problem  : https://codeforces.com/contest/877/problem/E
 * Time     : O(N log N)
 * Memory   : O(N)
**/

#include <bits/stdc++.h>
using namespace std;

template<int SZ>
struct SegmentTree {
    int tree[4 * SZ] = {};
    int lazy[4 * SZ] = {};
    
    void push(int n, int tl, int tr) {
        if (lazy[n]) {
            int mid = (tl + tr) / 2;
            lazy[n * 2] ^= 1;
            tree[n * 2] = (mid - tl + 1) - tree[n * 2];

            lazy[n * 2 + 1] ^= 1;
            tree[n * 2 + 1] = (tr - mid) - tree[n * 2 + 1];

            lazy[n] = 0;
        }
    }

    void update(int n, int tl, int tr, int l, int r) {
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r) {
            tree[n] = (tr - tl + 1) - tree[n];
            lazy[n] ^= 1;
            return;
        }
        int mid = (tl + tr) / 2;
        push(n, tl, tr);
        update(n * 2, tl, mid, l, r);
        update(n * 2 + 1, mid + 1, tr, l, r);
        tree[n] = tree[n * 2] + tree[n * 2 + 1];
    }

    int query(int n, int tl, int tr, int l, int r) {
        if (r < tl || tr < l) return 0;
        if (l <= tl && tr <= r) return tree[n];
        int mid = (tl + tr) / 2;
        push(n, tl, tr);
        return query(n * 2, tl, mid, l, r) + query(n * 2 + 1, mid + 1, tr, l, r);
    }

};

const int NMAX = 200005;

vector<int> adj[NMAX];
int sz[NMAX];
int pos[NMAX];
int ptr = 0;
SegmentTree<NMAX> seg;

void dfs(int n) {
    pos[n] = ptr++;
    sz[n] = 1;
    for (auto &i : adj[n]) dfs(i), sz[n] += sz[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        adj[p].emplace_back(i);
    }
    
    dfs(1);

    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        if (t == 1) {
            seg.update(1, 0, ptr - 1, pos[i], pos[i]);
        }
    }

    int q; cin >> q;
    for (int qi = 0; qi < q; qi++) {
        string s; int v;
        cin >> s >> v;
        if (s == "get") {
            cout << seg.query(1, 0, ptr - 1, pos[v], pos[v] + sz[v] - 1) << "\n";
        }
        else if (s == "pow") {
            seg.update(1, 0, ptr - 1, pos[v], pos[v] + sz[v] - 1);
        }
    }

    return 0;
}