#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e1+10, MOD = 1e9+7;

int M;
int add_self(int& a, int b) {
    a += b;
    if (a >= M) a -= M;
    return a;
}
int add(int a, int b) {
    return add_self(a, b);
}
int sub_self(int& a, int b) {
    a -= b;
    if (a < 0) a += M;
    return a;
}
int sub(int a, int b) {
    return sub_self(a, b);
}
int mul(int a, int b) {
    return (long long) a * b % M;
}
void mul_self(int& a, int b) {
    a = mul(a, b);
}
int po(int b, int p) {
    int r = 1;
    for (; p; b = mul(b, b), p >>= 1) if (p&1) mul_self(r, b);
    return r;
}

int n;
int sum[N][N * N];
int dp[N][N * N], fact[N], C[N][N];

void solve() {
    cin >> n >> M;

    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = mul(fact[i-1], i);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == i || j == 0) C[i][j] = 1;
            else C[i][j] = add(C[i-1][j-1], C[i-1][j]);
        }
    }

    const int K = n * (n - 1) / 2;

    dp[1][0] = 1;
    for (int k = 0; k <= K; k++) sum[1][k] = add(dp[1][k], (k ? sum[1][k-1] : 0));
    for (int i = 2; i <= n; i++) {
        for (int k = 0; k <= K; k++) {
            int L = k - min(i-1, k);
            int R = k;
            add_self(dp[i][k], sub(sum[i-1][R], (L ? sum[i-1][L-1] : 0)));
            sum[i][k] = add(dp[i][k], (k ? sum[i][k-1] : 0));
        }
    }


    int ans = 0;
    for (int p = 0; p < n; p++) {
        int cur_mul = mul(C[n][p], fact[p]);
        int cur = 0;
        int m = n - p;

        vector<int> cnt(m + 1);
        for (int a = 0; a < m; a++) for (int b = a+1; b < m; b++) add_self(cnt[b-a], 1);

        for (int d = -m; d < 0; d++) {
            int cur_cnt = cnt[-d];
            for (int x = 0; x <= K; x++) {
                int R = min(x + d - 1, K);
                if (R >= 0) add_self(cur, mul(cur_cnt, mul(dp[m-1][x], sum[m-1][R])));
            }
        }
        add_self(ans, mul(cur, cur_mul));
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}