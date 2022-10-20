#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int MOD = 998244353;
const int M = 100010;

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

int n, k;
int a[N];
int dp[N][N];

int get(int u) {
    for (int i = 1; i <= k; i++) {
        dp[0][i] = 0;
    }
    dp[0][0] = 1;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        while (cur + 1 < i && a[cur + 1] + u < a[i]) cur++;
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j == 0) continue;
            dp[i][j] = add(dp[i][j], dp[cur][j - 1]);
        }
    }
    return dp[n][k];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int max_val = *max_element(a + 1, a + n + 1) / (k - 1);
    int res = 0;
    for (int i = 0; i <= max_val; i++) {
        res = add(res, get(i));
    }
    cout << res << endl;
    return 0;
}