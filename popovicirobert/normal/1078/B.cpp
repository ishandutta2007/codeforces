#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 9;
const int MAXN = 100;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

int arr[MAXN + 1], fr[MAXN + 1];
int fact[MAXN + 1], invfact[MAXN + 1];

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

inline void prec() {
    fact[0] = invfact[0] = 1;
    for(int i = 1; i <= MAXN; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
        invfact[i] = lgput(fact[i], MOD - 2);
    }
}

inline int comb(int n, int k) {
    if(n < k)
        return 0;
    return (1LL * fact[n] * ((1LL * invfact[k] * invfact[n - k]) % MOD)) % MOD;
}

int dp[MAXN + 1][MAXN * MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int s = 0;
    dp[0][0] = 1;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        for(int p = i; p >= 1; p--) {
            for(j = s; j >= 0; j--) {
                dp[p][j + arr[i]] += dp[p - 1][j];
                mod(dp[p][j + arr[i]]);
            }
        }
        s += arr[i];
        fr[arr[i]]++;
    }
    prec();
    int ans = 0;
    int cnt = 0;
    bool ok = 1;
    for(i = 1; i <= MAXN; i++) {
        cnt += (fr[i] > 0);
        for(j = 1; j <= fr[i]; j++) {
            if(dp[j][i * j] == comb(fr[i], j)) {
                ans = max(ans, j);
                if(j == fr[i]) {
                    ok = 1;
                }
            }
        }
        for(j = 1; j <= fr[i]; j++) {
            if(dp[n - j][s - i * j] == comb(fr[i], j)) {
                ans = max(ans, j);
                if(j == fr[i]) {
                    ok = 1;
                }
            }
        }
    }
    if(cnt == 2 && ok == 1) {
        ans = n;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}