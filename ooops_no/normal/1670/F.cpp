#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int MOD = 1e9 + 7, N = 1010;
const ll INF = 1e18;
int c[N][N];
ll po[61];

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b) {
    return a - b < 0 ? a - b + MOD : a - b;
}

int mul(int a, int b) {
    return 1ll * a * b % MOD;
}

int solve(int n, ll m, ll z) {
    vector<int> dp(2 * n + 1);
    dp[0] = 1;
    for (int i = 60; i >= 0; i--) {
        vector<int> dpp(2 * n + 1);
        ll val = po[i];
        int need = 0;
        if (z & po[i]) need = 1;
        if (m & po[i]) {
            dp[2 * n] = add(dp[2 * n], dp[2 * n - 1]);
            for (int j = 2 * n - 1; j >= 1; j--) {
                dp[j] = dp[j - 1];
            }
            dp[0] = 0;
        }
        for (int j = 0; j <= 2 * n; j++) {
            for (int k = need; k <= n; k += 2) {
                if (j - k < 0) break;
                int val = min(2 * n, (j - k) * 2);
                dpp[val] = add(dpp[val], mul(dp[j], c[n][k]));
            }
        }
        swap(dp, dpp);
    }
    int ans = 0;
    for (auto to : dp) {
        ans = add(ans, to);
    }
    return ans;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    po[0] = 1;
    for (int i = 1; i <= 60; i++) {
        po[i] = po[i - 1] * 2;
    }
    for (int i = 0; i < N; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
        }
    }
    int n;
    ll l, r, z;
    cin >> n >> l >> r >> z;
    cout << sub(solve(n, r, z), solve(n, l - 1, z)) << endl;
    return 0;
}