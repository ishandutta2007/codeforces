#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 998244353;
const int N = 150010;
const int B = sqrt(N * 50) ;
const int LOG = 21;
 
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
 
int n, q, invN;
vector<int> adj[N];
int lv[N], numChild[N], in[N], out[N], cntEuler;
int eulerList[N * 3];
int lg2[N * 3];
int res[N];
int delta[N];
vector<int> affected;
bool used[N];
int addVal[N];
int par[N];

struct Node {
    int lv, u, id;
    bool operator < (const Node &u) const {
        if (lv != u.lv) return lv < u.lv;
        return id > u.id;
    }
    void debug() {
        cout << lv << ' ' << u << ' ' << id << endl;
    }
} minVal[LOG][N * 3];
 
Node rmq(int l, int r) {
    int lg = lg2[r - l + 1];
    return min(minVal[lg][l], minVal[lg][r - (1 << lg) + 1]);
}
 
void dfsInit(int u, int p) {
    numChild[u] = 1;
    lv[u] = lv[p] + 1;

    par[u] = p;
 
    in[u] = ++cntEuler;
    eulerList[cntEuler] = u;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfsInit(v, u);
        // eulerList[++cntEuler] = u;
        numChild[u] += numChild[v];
    }
    out[u] = cntEuler;
}
 
void addQuery(int u, int d) {
    if (!used[u]) {
        affected.push_back(u);
        used[u] = 1;
    }
    delta[u] = add(delta[u], d);
}
 
int getRoot(int v, int u) {
    Node w = rmq(in[u] + 1, in[v]);
    return w.u;
}
 
bool isChild(int v, int u) {
    return in[u] <= in[v] && out[v] <= out[u];
}
 
int calc(int v, int u) {
    if (u == v) return delta[u];
    if (!isChild(v, u)) {
        return mul(mul(delta[u], invN), numChild[u]);
    }   
    int w = getRoot(v, u);
    return mul(mul(delta[u], invN), sub(n, numChild[w]));
}

void dfsReset(int u, int p) {
    res[u] = add(res[u], addVal[u]);
    for (int v : adj[u]) {
        if (v == p) continue;
        addVal[v] = add(addVal[v], addVal[u]);
        dfsReset(v, u);
    }
}
 
void reset() {
    fill(addVal + 1, addVal + n + 1, 0);
    for (int u : affected) {
        res[u] = add(res[u], delta[u]);
        int val = mul(mul(delta[u], invN), numChild[u]);
        addVal[1] = add(addVal[1], val);
        addVal[u] = sub(addVal[u], val);
        for (int v : adj[u]) {
            if (par[u] == v) continue;
            int foo = mul(mul(delta[u], invN), sub(n, numChild[v]));
            addVal[v] = add(addVal[v], foo);
        }
    }
    dfsReset(1, 0);
    for (int u : affected) {
        used[u] = 0;
        delta[u] = 0;
    }
    affected.clear();
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    invN = inv(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfsInit(1, 0);
    // for (int i = 2; i <= n; i++) {
    //     for (int j = 0; j < adj[i].size(); j++) {
    //         if (adj[i][j] == par[i]) {
    //             adj[i].erase(adj[i].begin() + j);
    //             break;
    //         }
    //     }
    // }
    lg2[1] = 0;
    for (int i = 2; i < N * 3; i++) {
        lg2[i] = lg2[i >> 1] + 1;
    }
    for (int j = 1; j <= cntEuler; j++) {
        int u = eulerList[j];
        minVal[0][j] = {lv[u], u, j};
    }
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j + (1 << i) - 1 <= cntEuler; j++) {
            minVal[i][j] = min(minVal[i - 1][j], minVal[i - 1][j + (1 << i - 1)]);
        }
    }
    for (int qq = 1; qq <= q; qq++) {
        int op;
        cin >> op;
        if (op == 1) {
            int v, d; cin >> v >> d;
            addQuery(v, d);
        } else {
            int v; cin >> v;
            int now = res[v];
            for (int u : affected) {
                now = add(now, calc(v, u));
            }
            cout << now << '\n';
        }
 
        if (qq % B == 0) {
            reset();
        }
    }
    return 0;
}