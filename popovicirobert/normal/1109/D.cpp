#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 1e6;

inline void mod(int &x) {
    if(x >= MOD) x -= MOD;
}

inline void add(int &x, int y) {
    x += y, mod(x);
}

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

int fact[MAXN + 1], invfact[MAXN + 1];

inline void prec() {
    fact[0] = 1;
    for(int i = 1; i <= MAXN; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[MAXN] = lgput(fact[MAXN], MOD - 2);
    for(int i = MAXN - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
}

inline int comb(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}

inline int aran(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * invfact[n - k]) % MOD;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, a, b;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> a >> b;
    prec();
    int ans = 0;
    for(i = 0; i <= n - 2; i++) {
        if(i > m) {
            continue;
        }
        // (i + 2) * (i + 3) * ... * n
        int cur = (1LL * aran(n - 2, i) * comb(m - (i + 1) + i, i)) % MOD;
        cur = (1LL * cur * lgput(m, n - i - 2)) % MOD;
        // f(x, y) = y * [x ^ (x - y - 1)]
        // f(x, y) = x noduri, y paduri
        if(i + 2 < n) {
            cur = (1LL * cur * (1LL * (i + 2) * lgput(n, n - (i + 2) - 1) % MOD)) % MOD;
        }
        add(ans, cur);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}