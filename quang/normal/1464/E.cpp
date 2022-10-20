#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

inline int add(int u, int v, int mod = MOD) {return (u += v) >= mod ? u - mod : u;}
inline int sub(int u, int v, int mod = MOD) {return (u -= v) < 0 ? u + mod : u;}
inline int mul(int u, int v, int mod = MOD) {return (long long)u * v % mod;}
inline int power(int u, int v, int mod = MOD) {int res = 1;for (; v; v >>= 1, u = mul(u, u, mod)) if (v & 1) res = mul(res, u, mod); return res;}
inline int inv(int u, int mod = MOD) {return power(u, mod - 2, mod);}
inline void addTo(int &u, int v, int mod = MOD) {u = add(u, v, mod);}
inline void subTo(int &u, int v, int mod = MOD) {u = sub(u, v, mod);}
inline void mulTo(int &u, int v, int mod = MOD) {u = mul(u, v, mod);}

const int N = 100010;
const int LOG = 20;
const int M = 512;

int n, m;
vector<int> adj[N], revAdj[N];
int deg[N];
int g[N];
int cnt[M];
int a[M][M + 1];
int tot[M];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
        deg[u]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            cnt[g[v]]++;
        }

        g[u] = 0;
        while (cnt[g[u]]) g[u]++;

        for (int v : adj[u]) {
            cnt[g[v]]--;
        }

        for (int v : revAdj[u]) {
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        tot[g[i]]++;
    }

    int A = inv(n + 1);
    for (int i = 0; i < M; i++) {
        if (i != 0) a[i][M] = sub(0, A);
        for (int j = 0; j < M; j++) {
            a[i][j] = mul(tot[i ^ j], A);
        }
        subTo(a[i][i], 1);
    }

    for (int col = 0; col < M; col++) {
        int pos = -1;
        for (int row = col; row < M; row++) {
            if (a[row][col] != 0) {
                pos = row;
                break;
            }
        }
        assert(pos != -1);
        if (pos != col) {
            for (int j = col; j <= M; j++) swap(a[col][j], a[pos][j]);
        }
        for (int row = 0; row < M; row++) {
            if (row == col) continue;
            int first = a[row][col];
            for (int j = 0; j <= M; j++) {
                a[row][j] = sub(mul(a[row][j], a[col][col]), mul(a[col][j], first));
            }
        }
    }
    cout << mul(a[0][M], inv(a[0][0])) << endl;
    return 0;
}