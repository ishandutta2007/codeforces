#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int MOD = 1000000007;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}
 
inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}
 
inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}
 
inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}
 
inline int inv(int u) {
    return power(u, MOD - 2);
}

int n;
vector<int> adj[N];
int l[N], r[N];
int res = 0;
int numChild[N], dist[N], isDead[N];
int prod;
int invRange[N];

void dfsInit(int u, int p) {
    numChild[u] = 1;
    for (int v : adj[u]) {
        if (v == p || isDead[v]) continue;
        dfsInit(v, u);
        numChild[u] += numChild[v];
    }
}

int dfsFindCentroid(int u, int p, int sz) {
    int found = 0;
    for (int v : adj[u]) {
        if (v == p || isDead[v]) continue;
        int foo = dfsFindCentroid(v, u, sz);
        if (foo > 0) return foo;
        found |= (numChild[v] * 2 > sz);
    }
    found |= sz > 2 * numChild[u];
    if (found) return -1;
    return u;
}

int getCentroid(int u) {
    dfsInit(u, 0);
    return dfsFindCentroid(u, 0, numChild[u]);
}

void dfsInitDist(int u, int p) {
    for (int v : adj[u]) {
        if (v == p || isDead[v]) continue;
        dist[v] = dist[u] + 1;
        dfsInitDist(v, u);
    }
}

struct BIT {
    int t[N];
    vector<int> affected;
    int used[N];
    void reset() {
        for (int u : affected) {
            used[u] = 0;
            t[u] = 0;
        }
        affected.clear();
    }
    void add(int x, int v) {
        while (x < N) {
            if (!used[x]) {
                used[x] = 1;
                affected.push_back(x);
            }
            t[x] = ::add(t[x], v);
            x += x & -x;
        }
    }
    int get(int x) {
        int res = 0;
        while (x) {
            res = ::add(res, t[x]);
            x -= x & -x;
        }
        return res;
    }
} tId1, t1, tId2, t2;

void add(int u, int v, int l, int r) {
    tId1.add(l, u);
    t1.add(l, mul(u, sub(1, l)));
    tId1.add(r + 1, sub(0, u));
    t1.add(r + 1, mul(r, u));

    tId2.add(l, v);
    t2.add(l, mul(v, sub(1, l)));
    tId2.add(r + 1, sub(0, v));
    t2.add(r + 1, mul(r, v));
}

void reset() {
    tId1.reset();
    t1.reset();
    t2.reset();
    tId2.reset();
}

int get(int u, BIT &tId, BIT &t) {
    return add(mul(u, tId.get(u)), t.get(u));
}

int get(int l, int r, BIT &tId, BIT &t) {
    return sub(get(r, tId, t), get(l - 1, tId, t));
}

void getRes(int dist, int delta, int l, int r) {
    int foo, bar;
    foo = get(l, r, tId1, t1);
    bar = get(l, r, tId2, t2);
    int now = add(foo, mul(bar, dist));
    now = mul(now, delta);
    res = add(res, now);
}

void dfsGetRes(int u, int p) {
    getRes(dist[u], invRange[u], l[u], r[u]);
    for (int v : adj[u]) {
        if (isDead[v] || v == p) continue;
        dfsGetRes(v, u);
    }
}

void dfsUpdate(int u, int p) {
    add(mul(dist[u], mul(prod, invRange[u])), mul(prod, invRange[u]), l[u], r[u]);
    for (int v : adj[u]) {
        if (v == p || isDead[v]) continue;
        dfsUpdate(v, u);
    }
}

void solveCentroid(int u) {
    u = getCentroid(u);
    dist[u] = 0;
    dfsInitDist(u, 0);
    reset();
    add(0, mul(prod, invRange[u]), l[u], r[u]);
    for (int v : adj[u]) {
        if (isDead[v]) continue;
        dfsGetRes(v, u);
        dfsUpdate(v, u);
    }
    isDead[u] = 1;
    for (int v : adj[u]) {
        if (isDead[v]) continue;
        solveCentroid(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    prod = 1;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        if (l[i] > r[i]) swap(l[i], r[i]);
        prod = mul(prod, (r[i] - l[i] + 1));
        invRange[i] = inv(r[i] - l[i] + 1);
    }
    for (int i = 1; i < n; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    solveCentroid(1);
    cout << res << endl;
    return 0;
}