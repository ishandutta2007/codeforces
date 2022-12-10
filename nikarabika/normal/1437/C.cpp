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

int solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int m = n + n + 10;
    int dp[n + 1][m];
    memset(dp, 63, sizeof dp);
    memset(dp[0], 0, sizeof dp[0]);
    for (int i = 1; i <= n; i++) {
        int id = i - 1;
        for (int j = 1; j < m; j++)
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(j - a[id]));
    }
    cout << dp[n][m - 1] << '\n';
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}