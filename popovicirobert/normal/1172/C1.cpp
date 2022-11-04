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

int dp[51][51][51];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    vector <int> arr(n + 1), w(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        if(arr[i] == 0) {
            arr[i] = -1;
        }
    }
    int bad = 0, good = 0;
    for(i = 1; i <= n; i++) {
        cin >> w[i];
        if(arr[i] == -1) {
            bad += w[i];
        }
        else {
            good += w[i];
        }
    }

    vector <int> sol(n + 1);
    for(i = 1; i <= n; i++) {
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;

        for(int k = 1; k <= m; k++) {
            for(int a = k; a >= 0; a--) {
                for(int b = k; b >= 0; b--) {
                    int c = k - a - b - 1;
                    if(c < 0) { continue; }

                    int tot = bad + good + a - b + c * arr[i] + MOD;
                    tot = inv(tot); mul(tot, dp[a][b][c]);

                    int cur = (1LL * (good + a - (arr[i] == 1) * w[i] + MOD) * tot) % MOD;
                    add(dp[a + 1][b][c], cur);

                    cur = (1LL * (bad - b - (arr[i] == -1) * w[i] + MOD) * tot) % MOD;
                    add(dp[a][b + 1][c], cur);

                    add(dp[a][b][c + 1], (1LL * (w[i] + arr[i] * c + MOD) * tot) % MOD);
                }
            }
        }
        for(int a = 0; a <= m; a++) {
            for(int b = 0; b <= m; b++) {
                for(int c = 0; c <= m; c++) {
                    if(a + b + c == m) {
                        add(sol[i], (1LL * dp[a][b][c] * (w[i] + c * arr[i] + MOD)) % MOD);
                    }
                }
            }
        }
        cout << sol[i] << "\n";
    }

    return 0;
}