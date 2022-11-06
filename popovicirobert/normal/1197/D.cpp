#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = 998244353;

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
}*/

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    vector <int> arr(n + 1);
    vector <ll> sp(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        sp[i] = sp[i - 1] + arr[i];
    }

    vector <ll> best(m, 1e18);
    ll ans = 0;

    best[0] = 0;
    for(i = 1; i <= n; i++) {
        for(int l = 0; l < m; l++) {
            int cur = 0;
            if(i % m > l) {
                cur -= k;
            }
            ans = max(ans, sp[i] - 1LL * (i / m) * k - best[l] + cur);
        }
        best[i % m] = min(best[i % m], sp[i] - 1LL * k * (i / m));
    }

    for(i = 1; i <= n; i++) {
        for(int j = i - 1; j >= max(0, i - m); j--) {
            ans = max(ans, sp[i] - sp[j] - 1LL * k * ((i - j + m - 1) / m));
        }
    }

    cout << ans;

    return 0;
}