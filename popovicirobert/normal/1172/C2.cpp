#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


const int MOD = 998244353;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int inv(int x) {
    return lgput(x, MOD - 2);
}

/*int fact[], invfact[];

inline void prec(int n) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[n] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
}

inline int comb(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}*/

using namespace std;


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    vector <int> a(n + 1), w(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int G = 0, B = 0;
    for(i = 1; i <= n; i++) {
        cin >> w[i];
        if(a[i] == 0) B += w[i];
        else G += w[i];
    }
    int T = B + G;

    // f(w)[k][i][j] = f(1)[k][i][j] * w
    // f(1)[i][j], k = i + j
    // f(1)[i][j] = f(1)[i][j + 1] * (B - j) / (T + i - j) + f(1)[i + 1][j] * (G + i - 1) / (T + i - j) + f(2)[i + 1][j] * 1 / (T + i - j)
    // f(1)[i][j] = 1 / (T + i - j) * (  f(1)[i][j + 1] * (B - j) + f(1)[i + 1][j] * (G + i + 1)   )
    // g(1)[i][j] = 1 / (T + i - j) * (  g(1)[i + 1][j] * (G + i) + g(1)[i][j + 1] * (B - j - 1)   )

    vector < vector <int> > f(m + 1, vector <int>(m + 1));
    vector < vector <int> > g(m + 1, vector <int>(m + 1));

    for(i = 0; i <= m; i++) {
        f[i][m - i] = g[i][m - i] = 1;
    }
    for(int k = m - 1; k >= 0; k--) {
        for(i = 0; i <= k; i++) {
            j = k - i;
            f[i][j] = (1LL * f[i][j + 1] * (B - j) + 1LL * f[i + 1][j] * (G + i + 1)) % MOD;
            g[i][j] = (1LL * g[i + 1][j] * (G + i) + 1LL * g[i][j + 1] * (B - j - 1)) % MOD;
            int prd = inv(T + i - j);
            mul(f[i][j], prd); mul(g[i][j], prd);
        }
    }
    for(i = 1; i <= n; i++) {
        int cur = (a[i] == 0 ? g[0][0] : f[0][0]);
        mul(cur, w[i]);
        cout << cur << "\n";
    }

    return 0;
}