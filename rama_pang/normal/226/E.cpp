/**
 * Author   : rama_pang
 * Problem  : https://codeforces.com/contest/226/problem/E
 * Time     : O(Q log^2 N)
 * Memory   : O(N + Q log N)
**/

#include <bits/stdc++.h>
using namespace std;

using pt = struct Node*;

struct Node { // Persistent Segment Tree Node


    int val = 0;
    pt l = nullptr, r = nullptr;

    void build(int tl, int tr) {
        if (tl == tr) {
            val = 0;
            return;
        }
        int mid = (tl + tr) / 2;
        l = new Node();
        r = new Node();
        l->build(tl, mid);
        r->build(mid + 1, tr);
        val = l->val + r->val;
    }

    pt update(int tl, int tr, int p, int x) {
        if (tr < p || p < tl) return this;
        pt res = new Node();
        if (tl == tr) {
            res->val += x;
            return res;
        }
        int mid = (tl + tr) / 2;
        res->l = l->update(tl, mid, p, x);
        res->r = r->update(mid + 1, tr, p, x);
        res->val = res->l->val + res->r->val;
        return res;
    }

};

const int NMAX = 100005;
const int BITS = 20;

int N, M, R;
int P[NMAX][BITS];

vector<int> adj[NMAX];
int in[NMAX], out[NMAX], depth[NMAX];
vector<int> rpos;

vector<Node*> root;

void dfs(int n) {
    static int t = 1;
    in[n] = t++; rpos.emplace_back(n);
    for (auto &i : adj[n]) depth[i] = depth[n] + 1, dfs(i);
    out[n] = t++; rpos.emplace_back(n);
}

int getAnc(int u, int dist) {
    for (int i = BITS - 1; i >= 0; i--) {
        if (dist & (1 << i)) {
            u = P[u][i];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    v = getAnc(v, depth[v] - depth[u]);
    for (int i = BITS - 1; i >= 0; i--) {
        if (P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    return u == v ? u : P[u][0];
}

int query(pt cur, pt old, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) {
        return cur->val - old->val;
    }
    int mid = (tl + tr) / 2;
    return query(cur->l, old->l, tl, mid, l, r) + query(cur->r, old->r, mid + 1, tr, l, r);
}

int query(int cur, int old, int l, int r) {
    return query(root[cur], root[old], 0, 2 * N, l, r);
}

int solve(int u, int v, int k, int cur, int old) {
    int w = lca(u, v);

    int left = depth[u] - depth[w];
    int right = depth[v] - depth[w];

    auto getKth = [&](int u, int v, int k) {
        if (k <= left) {
            return getAnc(u, k);
        } else {
            return getAnc(v, left + right - k);
        }
    };

    int ans = -1;
    int MINUS = 1 - (query(cur, old, 0, in[u]) - query(cur, old, 0, in[u] - 1));

    for (int l = 1, r = left + right - 1, m = (l + r) / 2; l <= r; m = (l + r) / 2) {
        int nd = getKth(u, v, m);
        int cnt = 0;
        int ww = lca(u, nd);

        cnt += depth[u]        - query(cur, old, 0, in[u]) - MINUS;
        cnt += depth[nd]       - query(cur, old, 0, in[nd]);
        cnt -= depth[ww]       - query(cur, old, 0, in[ww]);
        cnt -= depth[P[ww][0]] - query(cur, old, 0, in[P[ww][0]]);

        if (cnt >= k) {
            ans = nd;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return ans == v ? -1 : ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i][0];
        if (P[i][0] == 0) R = i;
        adj[P[i][0]].emplace_back(i);
    }

    for (int j = 1; j < BITS; j++) {
        for (int i = 1; i <= N; i++) {
            P[i][j] = P[P[i][j - 1]][j - 1];
        }
    }

    depth[R] = 1;
    dfs(R);

    cin >> M;
    root.resize(M + 1);
    root[0] = new Node();
    root[0]->build(0, 2 * N);

    for (int year = 1; year <= M; year++) {
        int type; cin >> type;
        root[year] = root[year - 1];
        if (type == 1) {
            int v; cin >> v;
            root[year] = root[year]->update(0, 2 * N, in[v], 1);
            root[year] = root[year]->update(0, 2 * N, out[v], -1);
        } else if (type == 2) {
            int u, v, k, y;
            cin >> u >> v >> k >> y;
            cout << solve(u, v, k, year, y) << "\n";
        }
    }

    return 0;
}