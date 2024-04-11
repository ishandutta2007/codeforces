//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int INF = 1e9;

int *solve(int a[], int n, int mod) {
    int dp[n + 1][n / 2 + 1][mod];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n / 2; j++)
            for (int k = 0; k < mod; k++)
                dp[i][j][k] = -INF;
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n / 2; j++) {
            for (int k = 0; k < mod; k++) {
                smax(dp[i + 1][j][k], dp[i][j][k]);
                if (j + 1 <= n / 2)
                    smax(dp[i + 1][j + 1][(k + a[i]) % mod],
                            dp[i][j][k] + a[i]);
            }
        }
    }
    int *result = (int *)malloc(mod * sizeof(int));
    for (int k = 0; k < mod; k++) {
        result[k] = -INF;
        for (int i = 0; i <= n / 2; i++)
            smax(result[k], dp[n][i][k]);
    }
    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n, m, mod;
    cin >> n >> m >> mod;
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int *row[n] = {NULL};
    for (int i = 0; i < n; i++)
        row[i] = solve(a[i], m, mod);
    int dp[n + 1][mod];
    for (int i = 0; i <= n; i++)
        fill(dp[i], dp[i] + mod, -INF);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < mod; j++) {
            smax(dp[i + 1][j], dp[i][j]);
            for (int k = 0; k < mod; k++)
                smax(dp[i + 1][(j + k) % mod], dp[i][j] + row[i][k]);
        }
    cout << dp[n][0] << '\n';
	return 0;
}