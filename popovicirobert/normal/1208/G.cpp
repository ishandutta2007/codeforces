#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long



#if 0
const int MOD = ;

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
#endif

#if 0
int fact[], invfact[];

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
}
#endif

using namespace std;

const int MAXN = (int) 1e6;

int phi[MAXN + 1];

int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    if(k == 1) {
        cout << 3;
        return 0;
    }

    ll ans = 1e18;
    for(int two = 0; two < 2; two++) {
        for(i = 1; i <= n; i++) {
            phi[i] = i;
        }
        for(i = 1; i <= n; i++) {
            for(j = 2 * i; j <= n; j += i) {
                phi[j] -= phi[i];
            }
        }
        if(!two) {
            for(i = 2; i <= n; i += 2) {
                phi[i] = n + 1;
            }
        }
        sort(phi + 1, phi + n + 1);
        ll cur = 0;
        for(i = 1; i <= k + 1 + two; i++) {
            cur += phi[i];
        }
        ans = min(ans, cur);
    }
    cout << ans;

    return 0;
}