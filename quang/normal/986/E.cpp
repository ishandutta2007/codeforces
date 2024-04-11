#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) {
        u -= MOD;
    }
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) {
        u += MOD;
    }
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) {
            res = mul(res, u);
        }
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

const int N = 100010, LOG = 20;
const int MAX = 10000010;

int n;
vector<int> adj[N];
int p[MAX];
int cntPrime = 0;
int prime[N * 10];
vector<pair<int, int> > event[N * 10];
int primePos[MAX];

int lv[N], par[LOG][N];
int in[N], out[N], cntEuler;

int u[N], v[N], w[N];

void dfs(int u, int p) {
    in[u] = ++cntEuler;
    lv[u] = lv[p] + 1;
    par[0][u] = p;
    for (int i = 1; i < LOG; i++) {
        par[i][u] = par[i - 1][par[i - 1][u]];
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    out[u] = cntEuler;
}

int lca(int u, int v) {
    if (lv[u] < lv[v]) {
        swap(u, v);
    }
    int h = lv[u] - lv[v];
    for (int i = LOG - 1; i >= 0; i--) {
        if (h & (1 << i)) {
            u = par[i][u];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}

struct BIT {
    int t[N];

    void add(int x, int v) {
        while (x < N) {
            t[x] += v;
            x += x & -x;
        }
    }

    int get(int x) {
        int res = 0;
        while (x) {
            res += t[x];
            x -= x & -x;
        }
        return res;
    }
} bit;

int res[N];

int main() {
    for (int i = 2; i < MAX; i++) {
        if (!p[i]) {
            prime[++cntPrime] = i;
            primePos[i] = cntPrime;
            for (int j = i; j < MAX; j += i) {
                if (!p[j]) {
                    p[j] = i;
                }
            }
        }
    } 
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        int u;
        scanf("%d", &u);
        while (u > 1) {
            int foo = p[u];
            int cnt = 0;
            while (u % foo == 0) {
                u /= foo;
                cnt++;
            }
            event[primePos[foo]].emplace_back(cnt, i);
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        res[i] = 1;
        int x;
        scanf("%d %d %d", u + i, v + i, &x);
        w[i] = lca(u[i], v[i]);
        while (x > 1) {
            int foo = p[x];
            int cnt = 0;
            while (x % foo == 0) {
                x /= foo;
                cnt++;
            }
            for (int j = 1; j <= cnt; j++) {
                event[primePos[foo]].emplace_back(j, -i);
            }
        }
    }
    for (int i = 1; i <= cntPrime; i++) {
        if (event[i].empty()) {
            continue;
        }
        // cout << "id " << i << " " << prime[i] << endl;
        sort(event[i].begin(), event[i].end(), greater<pair<int, int> > ());
        for (pair<int, int> it : event[i]) {
            // cout << "event " << it.first << " " << it.second << endl;
            if (it.second > 0) {
                // cout << "update " << it.second << " " << in[it.second] << endl;
                bit.add(in[it.second], 1);
                bit.add(out[it.second] + 1, -1);
                // cout << bit.get(in[it.second]) << endl;
            } else {
                int id = -it.second;
                int foo = add(bit.get(in[u[id]]), bit.get(in[v[id]]));
                // cout << foo << " ";
                foo = sub(foo, bit.get(in[w[id]]));
                if (w[id] > 1) {
                    foo = sub(foo, bit.get(in[par[0][w[id]]]));
                }
                // cout << id << " " << foo << " " << prime[i] << endl;
                res[id] = mul(res[id], power(prime[i], foo));
            }
        }
        for (pair<int, int> it : event[i]) {
            if (it.second > 0) {
                bit.add(in[it.second], -1);
                bit.add(out[it.second] + 1, 1);
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}