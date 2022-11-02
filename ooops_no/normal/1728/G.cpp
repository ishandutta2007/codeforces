#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define ll long long
#define pb push_back
#define ld long double

const int MOD = 998244353, N = 3e5 + 10, M = 20;

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b) {
    return a - b < 0 ? a - b + MOD : a - b;
}

int mul(int a, int b) {
    return (1ll * a * b % MOD);
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

int inv(int a) {
    return binpow(a, MOD - 2);
}

vector<vector<int>> dp(N, vector<int>(M)), rev_dp(N, vector<int>(M));

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> l(n), p(m);
    map<int,int> used;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        used[l[i]] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    dp[0][0] = 1;
    for (int i = 1; i <= d; i++) {
        if (!used[i]) {
            dp[i] = dp[i - 1];
            continue;
        }
        for (int j = 0; j < m; j++) {
            int mn = abs(p[j] - i);
            dp[i][j] = add(dp[i][j], mul(dp[i - 1][j], mn));
            vector<pair<int,int>> arr;
            int last = mn;
            for (int k = j; k < m; k++) {
                if (abs(p[k] - i) <= mn) continue;
                dp[i][k] = add(dp[i][k], mul(dp[i - 1][j], (abs(p[k] - i) - last)));
                last = abs(p[k] - i);
            }
            dp[i][m] = add(dp[i][m], mul(dp[i - 1][j], (d - last + 1)));
        }
        dp[i][m] = add(dp[i][m], mul(dp[i - 1][m], d + 1));
    }
    reverse(p.begin(), p.end());
    rev_dp[d][0] = 1;
    for (int i = d - 1; i >= 0; i--) {
        if (!used[i]) {
            rev_dp[i] = rev_dp[i + 1];
            continue;
        }
        for (int j = 0; j < m; j++) {
            int mn = abs(p[j] - i);
            rev_dp[i][j] = add(rev_dp[i][j], mul(rev_dp[i + 1][j], mn));
            vector<pair<int,int>> arr;
            int last = mn;
            for (int k = j; k < m; k++) {
                if (abs(p[k] - i) <= mn) continue;
                rev_dp[i][k] = add(rev_dp[i][k], mul(rev_dp[i + 1][j], (abs(p[k] - i) - last)));
                last = abs(p[k] - i);
            }
            rev_dp[i][m] = add(rev_dp[i][m], mul(rev_dp[i + 1][j], (d - last + 1)));
        }
        rev_dp[i][m] = add(rev_dp[i][m], mul(rev_dp[i + 1][m], d + 1));
    }
    reverse(p.begin(), p.end());
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int ans = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= m; j++) {
                int rev = m - j - 1, need;
                if (i > rev || max(i, j) == m) {
                    need = d + 1;
                } else {
                    need = d - max(abs(x - p[i]), abs(x - p[rev])) + 1;
                }
                ans = add(ans, mul(need, mul(dp[x][i], rev_dp[x][j])));
            }
        }
        cout << ans << endl;
    }
    return 0;
}