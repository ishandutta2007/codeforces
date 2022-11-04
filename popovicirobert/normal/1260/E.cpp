#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int



#if 0
const int MOD = (int) ;

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

const int MAXN = (1 << 18);

ll dp[MAXN + 1][19];


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> a(n + 1);
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }

    const ll INF = 1e18;

    for(i = 0; i <= n; i++) {
        for(j = 0; (1 << j) <= n; j++) {
            dp[i][j] = INF;
        }
    }

    dp[n][0] = 0;
    for(i = n; i >= 0; i--) {
        if(a[i] == -1) {
            break;
        }
        int cur = 0, pw = n / 2;
        for(j = 0; (1 << j) <= n; j++) {
            if(cur >= n - i + 1) {
                dp[i - 1][j] = min(dp[i - 1][j], dp[i][j]);
            }
            if(j + 1 <= 18) {
                dp[i - 1][j + 1] = min(dp[i - 1][j + 1], dp[i][j] + a[i - 1]);
            }

            cur += pw;
            pw /= 2;
        }
    }

    ll ans = INF;
    for(j = 0; (1 << j) <= n; j++) {
        ans = min(ans, dp[i + 1][j]);
    }

    cout << ans << "\n";

    return 0;
}