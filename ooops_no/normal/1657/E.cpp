#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int MOD = 998244353, N = 300;
int c[N][N];

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int mul(int a, int b) {
    return (a * b % MOD);
}

int binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n /= 2;
    }
    return res;
}

int n, k, ans = 0;

vector<int> a;

void rec(int i, int res) {
    if (i == n) {
        for (int j = 0; j < n; j++) {
            for (int f = j + 1; f < n; f++) {
                res = mul(res, k - max(a[j], a[f]) + 1);
            }
        }
        ans = add(ans, res);
        return;
    }
    int need = (a.size() == 0 ? 0 : a.back());
    for (int q = 1; q + i <= n; q++) {
        for (int j = need + 1; j <= k; j++) {
            for (int ind = 0; ind < q; ind++) a.pb(j);
            rec(q + i, mul(res, c[n - i][q]));
            for (int ind = 0; ind < q; ind++) a.pop_back();
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
        }
    }
    cin >> n >> k;
    n--;
    vector<vector<int>> dp(n + 1, vector<int>(k));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            dp[i][j] = mul(c[n][i], binpow(k - j, i * (i - 1) / 2));
        }
    }
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int f = 0; f < k; f++) {
            for (int q = 1; q + i <= n; q++) {
                dp[i + q][f] = add(dp[i + q][f], mul(sum, mul(c[n - i][q], binpow(k - f, i * q + q * (q - 1) / 2))));
            }
            sum = add(sum, dp[i][f]);
        }
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans = add(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}