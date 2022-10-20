#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int MOD = 1e9 + 7;
long long a[20], dp[20010], prob[20][20], n;
long long pw(long long a, long long n) {
    long long base = a, res = 1;
    while(n) {
        if(n&1) res = res * base % MOD;
        base = base * base % MOD;
        n >>= 1;
    }
    return res;
}
long long inv(long long a) {
    return pw(a, MOD-2);
}
long long get_dp(int x) {
    if(dp[x] >= 0) return dp[x];
    vector<int> b;
    for(int i = 0; i < n; i++) {
        if((1<<i)&x) b.push_back(i);
    }
    long long res = 1;
    int m = b.size();
    if(m == 1) {
        dp[x] = 1;
        return dp[x];
    }
    for(int i = 1; i < (1<<m)-1; i++) {
        int y = 0;
        for(int j = 0; j < m; j++) {
            if(i&(1<<j)) y |= (1<<b[j]);
        }
        long long t = get_dp(y);
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                if(((1<<j)&i) == 0 && ((1<<k)&i) != 0) t = t * prob[b[j]][b[k]] % MOD;
            }
        }
        res = res - t % MOD;
        res = (res+MOD) % MOD;
    }
    dp[x] = res;
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) prob[i][j] = 1;
            else {
                prob[i][j] = a[i] * inv(a[i]+a[j]) % MOD;
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i < (1<<n); i++) {
        get_dp(i);
    }
    long long ans = n;
    for(int i = 1; i < (1<<n)-1; i++) {
        long long cnt = 0;
        for(int j = 0; j < n; j++) {
            if((i&(1<<j)) == 0) {
                cnt++;
            }
        }
        long long tmp = dp[i];
        for(int k = 0; k < n; k++) {
            for(int l = 0; l < n; l++)
                if((i&(1<<l)) == 0 && (i&(1<<k))) {
                    tmp = tmp * prob[k][l] % MOD;
                }
        }
        ans -= tmp * cnt % MOD;
        ans %= MOD;
        ans = (ans + MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}