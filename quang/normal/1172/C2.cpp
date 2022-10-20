#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int M = 3010;
const int N = 200010;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}
 
inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}
 
inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}
 
inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}
 
inline int inv(int u) {
    return power(u, MOD - 2);
}

int n, m;
int a[N], w[N];
int dp[M][M];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int sumPos = 0, sumNeg = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        if (a[i]) sumPos = add(sumPos, w[i]);
        else sumNeg = add(sumNeg, w[i]);
    }
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int step = 0; step < m; step++) {
        for (int pos = 0; pos <= step; pos++) {
            int neg = sub(step, pos);
            int curPos = add(sumPos, pos);
            int curNeg = sub(sumNeg, neg);
            int sum = add(curPos, curNeg);
            int invSum = inv(sum);
            dp[pos + 1][neg] = add(dp[pos + 1][neg], mul(dp[pos][neg], mul(curPos, invSum)));
            dp[pos][neg + 1] = add(dp[pos][neg + 1], mul(dp[pos][neg], mul(curNeg, invSum)));
        }
    }
    int expPos = 0, expNeg = 0;
    for (int pos = 0; pos <= m; pos++) {
        int neg = sub(m, pos);
        expPos = add(expPos, mul(dp[pos][neg], add(sumPos, pos)));
        expNeg = add(expNeg, mul(dp[pos][neg], sub(sumNeg, neg)));
    }
    for (int i = 1; i <= n; i++) {
        if (a[i]) cout << mul(mul(w[i], inv(sumPos)), expPos) << '\n';
        else cout << mul(mul(w[i], inv(sumNeg)), expNeg) << '\n';
    }
    return 0;
}