#include <bits/stdc++.h>

using namespace std;

const int N = 1510;
const int MOD = 1000000007;
const int SZ = 100010;

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

int n, m, a, b, k, p;
int dp[N][N];
int pref[N][N];
int sumG[N], g[N];
int fac[SZ], invFac[SZ];

int comb(int n, int k) {
    if (k > n || k < 0) return 0;
    return mul(fac[n], mul(invFac[k], invFac[n - k]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> a >> b;
    cin >> k;
    
    p = mul(a, inv(b));
    fac[0] = 1;
    for (int i = 1; i < SZ; i++) {
        fac[i] = mul(fac[i - 1], i);
    }
    invFac[SZ - 1] = inv(fac[SZ - 1]);
    for (int i = SZ - 2; i >= 0; i--) {
        invFac[i] = mul(invFac[i + 1], i + 1);
    }

    for (int i = 0; i <= m; i++) {
        g[i] = comb(k, i);
        if (g[i] != 0) {
            g[i] = mul(g[i], power(p, i));
            g[i] = mul(g[i], power(sub(1, p), k - i));
        }
        sumG[i] = g[i];
        if (i > 0) sumG[i] = add(sumG[i], sumG[i - 1]);
    }

    memset(dp, 0, sizeof dp);
    memset(pref, 0, sizeof pref);
    dp[0][m] = 1;
    for (int i = 1; i <= n; i++) {

        for (int r = 1; r <= m; r++) {
            int p1 = mul(sumG[r - 1], sub(dp[i - 1][m], dp[i - 1][m - r]));
            int p2 = pref[i - 1][r - 1];
            int foo = mul(sub(p1, p2), g[m - r]);
            dp[i][r] = add(dp[i][r - 1], foo);

            pref[i][r] = add(pref[i][r - 1], mul(g[r], dp[i][r]));
        } 
    }
    cout << dp[n][m] << endl;
    return 0;   
}