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

const int MAXN = 505;

int dp[MAXN + 1][MAXN + 1], sp[MAXN + 1][MAXN + 1];

inline int get(int l, int r) {
    if(l > r) return 1;
    return dp[l][r];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    vector <int> arr(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i][i] = sp[i + 1][i] = 1;
        sp[i][i] = 2;
    }

    for(int len = 1; len < n; len++) {
        for(int l = 1; l + len <= n; l++) {
            int r = l + len;
            int mn = 1e9, pos;

            for(int k = l; k <= r; k++) {
                if(mn > arr[k]) {
                    mn = arr[k];
                    pos = k;
                }
            }

            for(int a = pos; a >= l; a--) {
                dp[l][r] = (dp[l][r] + 1LL * (1LL * get(l, a - 1) * get(a, pos - 1) % MOD) * sp[pos + 1][r]) % MOD;
            }

            for(int k = l - 1; k <= r; k++) {
                add(sp[l][r], (1LL * get(l, k) * get(k + 1, r)) % MOD);
            }
        }
    }

    cout << dp[1][n];

    return 0;
}