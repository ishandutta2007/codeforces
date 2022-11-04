#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MOD = 998244353;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline int inv(int x) {
    return lgput(x, MOD - 2);
}

const int MAXP = 100;
const int MAXS = 5000;

int fact[2 * MAXS + 1], invfact[2 * MAXS + 1];

inline void prec() {
    fact[0] = invfact[0] = 1;
    for(int i = 1; i <= 2 * MAXS; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
        invfact[i] = lgput(fact[i], MOD - 2);
    }
}

inline int comb(int n, int k) {
    return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}

int dp[MAXP + 1][MAXS + 1];

inline int get(int a, int b) {
    if(b == 0) {
        return dp[a][b];
    }
    int ans = dp[a][b] - dp[a][b - 1] + MOD;
    mod(ans);
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, p, s, r;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> p >> s >> r;
    if(s == 0) {
        cout << inv(p);
        return 0;
    }
    if(p == 1) {
        cout << 1;
        return 0;
    }
    prec();
    int ans = 0, tot = 0;
    for(int mx = r; mx <= s; mx++) {
        if(mx == 0) {
            tot += comb(s + p - 2, p - 2);
            continue;
        }
        for(j = 0; j <= s - mx; j++) {
            dp[0][j] = 1;
        }
        for(i = 1; i < p; i++) {
            for(j = 0; j <= s - mx; j++) {
                if(j - mx >= 0) {
                    dp[i][j] = dp[i - 1][j] - dp[i - 1][j - mx] + MOD;
                    mod(dp[i][j]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
                if(j > 0) {
                    dp[i][j] += dp[i][j - 1];
                    mod(dp[i][j]);
                }
            }
        }
        //cerr << get(p - 1, s - mx) << "\n";
        tot += comb(p - 2 + s - mx, p - 2);
        mod(tot);
        for(i = 1; mx * i <= s && i <= p; i++) {
            ans = (ans + 1LL * inv(i) * (1LL * get(p - i, s - mx * i) * comb(p - 1, i - 1) % MOD)) % MOD;
        }
    }
    tot = inv(tot);
    cout << (1LL * ans * tot) % MOD;
    //cin.close();
    //cout.close();
    return 0;
}