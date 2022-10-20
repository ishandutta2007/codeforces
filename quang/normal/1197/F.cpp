#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int SZ = 64;
const int MOD = 998244353;
const int LOG = 31;

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

struct Matrix {
    int a[SZ][SZ];
    Matrix(int dia = 0) {
        memset(a, 0, sizeof a);
        for (int i = 0; i < SZ; i++) a[i][i] = dia;
    }
    int* operator [] (int u) {
        return a[u];
    }
};

Matrix add(Matrix &u, Matrix &v) {
    Matrix res;
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            res[i][j] = add(u[i][j], v[i][j]);
        }
    }
    return res;
}

Matrix mul(Matrix &u, Matrix &v, int sz = SZ) {
    Matrix res;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < SZ; j++) {
            for (int k = 0; k < SZ; k++) {
                res[i][j] = add(res[i][j], mul(u[i][k], v[k][j]));
            }
        }
    }
    return res;
}

int n, m;
int a[N];
vector<pair<int, int>> b[N];
int f[3][3];
int dp[2][4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        c--;
        b[x].push_back({y, c});
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> f[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(b[i].begin(), b[i].end());
    }
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    Matrix base[3];
    //build matrix
    for (int i = 0; i < SZ; i++) {
        int g[3];
        g[0] = i & 3, g[1] = i >> 2 & 3, g[2] = i >> 4 & 3;
        for (int color = 0; color < 3; color++) {
            set<int> s;
            for (int j = 0; j < 3; j++) {
                if (f[color][j]) {
                    s.insert(g[j]);
                }
            }
            int nxt = 0;
            while (s.count(nxt)) nxt++;
            int nxtMask = (g[1] << 4) | (g[0] << 2) | nxt;
            base[color][i][nxtMask]++;
        }
    }
    //init sparse table 
    Matrix p2[LOG];
    p2[0] = add(base[0], base[1]);
    p2[0] = add(base[2], p2[0]);

    for (int i = 1; i < LOG; i++) {
        p2[i] = mul(p2[i - 1], p2[i - 1]);
    }


    auto update = [&](Matrix &u, int v) {
        for (int i = 0; i < LOG; i++) {
            if ((v >> i) & 1) {
                u = mul(u, p2[i], 1);
            }
        }
    };
    //dp
    int cur = 0;
    for (int i = 1; i <= n; i++, cur ^= 1) {
        //dp current
        Matrix now;
        now[0][SZ - 1] = 1;
        int last = 0;
        for (auto u : b[i]) {
            update(now, u.first - last - 1);
            now = mul(now, base[u.second], 1);
            last = u.first;
        }
        update(now, a[i] - last);
        //update whole dp
        vector<int> g(4, 0);
        memset(dp[cur ^ 1], 0, sizeof dp[cur ^ 1]);
        for (int mask = 0; mask < SZ; mask++) {
            int foo = mask & 3;
            g[foo] = add(g[foo], now[0][mask]);
        }

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                dp[cur ^ 1][j ^ k] = add(dp[cur ^ 1][j ^ k], mul(dp[cur][j], g[k]));
            }
        }
    }
    cout << dp[cur][0] << endl;
    return 0;
}