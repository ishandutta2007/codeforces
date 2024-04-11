#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 3e5;

int dp[MAXN + 1];
int fr[MAXN + 1];

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
    if(n < k)
        return 0;
    return (1LL * fact[n] * ((1LL * invfact[k] * invfact[n - k]) % MOD)) % MOD;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    int nr = 0;
    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;
        nr = __gcd(nr, x);
        fr[x]++;
    }
    if(nr > 1) {
        cout << -1;
        return 0;
    }
    for(i = 1; i <= MAXN; i++) {
        for(j = 2 * i; j <= MAXN; j += i) {
            fr[i] += fr[j];
        }
    }
    prec();
    for(i = 1; i <= 7; i++) {
        for(j = MAXN; j >= 1; j--) {
            dp[j] = comb(fr[j], i);
            for(int k = 2 * j; k <= MAXN; k += j) {
                dp[j] = (dp[j] - dp[k] + MOD) % MOD;
            }
        }
        if(dp[1] > 0) {
            cout << i;
            return 0;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}