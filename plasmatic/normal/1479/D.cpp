// ./d-odd-mineral-resource.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 3e5 + 1, LG = 19;
int N, Q,
    A[MN], tb[LG][MN];
ll wn[MN];
vector<int> loc[MN], g[MN];

// LCA data structure
int cord = 0, in[MN], out[MN], dep[MN];
void dfs(int c, int p) {
    in[c] = ++cord;
    tb[0][c] = p;
    for (auto to : g[c]) {
        if (to != p) {
            dep[to] = dep[c] + 1;
            dfs(to, c);
        }
    }
    out[c] = cord;
}

int lca(int u, int v) {
    if (u == v) return u;
    if (dep[u] > dep[v]) swap(u, v);
    int delta = dep[v] - dep[u];
    for (auto i = 0; i < LG; i++)
        if ((delta >> i) & 1)
            v = tb[i][v];
    if (u == v) return u;
    for (auto i = LG-1; i >= 0; i--) {
        if (tb[i][u] != tb[i][v]) {
            u = tb[i][u];
            v = tb[i][v];
        }
    }
    return tb[0][u];
}

// Euler Tour BIT
int ptr = 0;
ll bit[MN];
void add(int x, ll v) {
    for (; x < MN; x += x & -x)
        bit[x] ^= v;
}
ll sum(int x) {
    ll sum = 0;
    for (; x; x -= x & -x)
        sum ^= bit[x];
    return sum;
}
void move(int target) {
    while (ptr < target) {
        ptr++;
        for (auto k : loc[ptr]) {
            add(in[k], wn[ptr]);
            add(out[k]+1, wn[ptr]);
        }
    }
    while (ptr > target) {
        for (auto k : loc[ptr]) {
            add(in[k], wn[ptr]);
            add(out[k]+1, wn[ptr]);
        }
        ptr--;
    }
}

// query stuff
struct query {
    int i, u, v, l, r, lcav; ll base;
    bool operator<(const query &o) const {
        return l < o.l;
    }
};
ll path(query &q) {
    ll res = sum(in[q.u]) ^ sum(in[q.v]);
    if (A[q.lcav] <= ptr) res ^= wn[A[q.lcav]];
    return res;
}
ll ans[MN];

void CDQ(vector<query> qs, int l, int r) {
    if (qs.empty() || l > r) return;
    if (l == r) {
        move(l);
        for (auto &q : qs)
            ans[q.i] = path(q) != q.base ? l : -1;
        return;
    }

    int mid = (l + r) / 2; move(mid);
    vector<query> lhs, rhs;
    for (auto &q : qs) {
        if (q.r <= mid) lhs.push_back(q);
        else if (q.l > mid) rhs.push_back(q);
        else {
            if (path(q) != q.base) lhs.push_back(q);
            else rhs.push_back(q);
        }
    }
    CDQ(lhs, l, mid); CDQ(rhs, mid+1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mt19937 mt(26022021);
    uniform_int_distribution<ll> dis(0, LLONG_MAX);
    
    cin >> N >> Q;
    for (auto i = 1; i <= N; i++) {
        cin >> A[i];
        loc[A[i]].push_back(i);
        wn[i] = dis(mt);
    }
    for (auto i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // DFS, build lca
    dfs(1, -1);
    for (auto i = 1; i < LG; i++) {
        for (auto j = 1; j <= N; j++) {
            int pp = tb[i-1][j];
            tb[i][j] = pp == -1 ? -1 : tb[i-1][pp];
        }
    }

    // read and init queries, run CDQ
    vector<query> qs;
    for (auto i = 0; i < Q; i++) {
        int u, v, l, r; cin >> u >> v >> l >> r;
        qs.push_back({i, u, v, l, r, lca(u, v), 0LL});
    }
    sort(qs.begin(), qs.end());
    for (auto &q : qs) {
        move(q.l-1);
        q.base = path(q);
    }
    CDQ(qs, 1, N);
    for (auto i = 0; i < Q; i++)
        cout << ans[i] << '\n';

    return 0;
}