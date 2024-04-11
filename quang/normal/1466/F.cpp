#include <bits/stdc++.h>

using namespace std;

const int N = 500010;
const int MOD = 1000000007;

inline int add(int u, int v, int mod = MOD) {return (u += v) >= mod ? u - mod : u;}
inline int sub(int u, int v, int mod = MOD) {return (u -= v) < 0 ? u + mod : u;}
inline int mul(int u, int v, int mod = MOD) {return (long long)u * v % mod;}
inline int power(int u, int v, int mod = MOD) {int res = 1;for (; v; v >>= 1, u = mul(u, u, mod)) if (v & 1) res = mul(res, u, mod); return res;}
inline int inv(int u, int mod = MOD) {return power(u, mod - 2, mod);}
inline void addTo(int &u, int v, int mod = MOD) {u = add(u, v, mod);}
inline void subTo(int &u, int v, int mod = MOD) {u = sub(u, v, mod);}
inline void mulTo(int &u, int v, int mod = MOD) {u = mul(u, v, mod);}

int n, m;

struct DSU {
    int numComp;
    vector<int> root;
    vector<int> sz;
    vector<bool> dead;

    DSU(int n = 0) : numComp(n), root(n + 1, 0), sz(n + 1, 1), dead(n + 1, 0) {}

    int getRoot(int u) {
        return root[u] ? root[u] = getRoot(root[u]) : u;
    }

    bool unite(int u, int v) {
        u = getRoot(u); v = getRoot(v);
        if (u == v) return 0;
        sz[v] += sz[u];
        root[u] = v;
        numComp--;
        return 1;
    }

    void set(int u) {
        dead[getRoot(u)] = 1;   
    }

    int check(int u) {
        return dead[getRoot(u)] == 0;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    DSU dsu(m);
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        vector<int> a;
        for (int j = 0; j < k; j++) {
            int u;
            cin >> u;
            if (dsu.check(u)) a.push_back(u);
        }
        if (a.empty()) continue;
        if (a.size() == 1) {
            res.push_back(i);
            dsu.set(a[0]);
        } else {
            int u = a[0];
            int v = a[1];
            if (dsu.unite(u, v)) {
                res.push_back(i);
            }
        }
    }
    cout << power(2, res.size()) << ' ' << res.size() << '\n';
    for (int u : res) cout << u << ' ';
        cout << '\n';
    return 0;
}