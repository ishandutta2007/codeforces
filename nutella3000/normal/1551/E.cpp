#include <bits/stdc++.h>
using namespace std;
     
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;

const int inf = 2e9 + 3;
const int max_n = 4e2 + 3;

void run() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = i + 1 - a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n + 1, -inf));
    dp[0][0] = a[0] == 0;
    dp[0][1] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i + 1; ++j) {
            if (j) chkmax(dp[i][j], dp[i - 1][j - 1]);
            chkmax(dp[i][j], dp[i - 1][j]);
            if (a[i] == j) chkmax(dp[i][j], dp[i - 1][j] + 1);
        }
    }
    int res = inf;
    for (int j = n; j >= 0; --j) {
        if (dp[n - 1][j] >= k) res = j;
    }
    cout << (res == inf ? -1 : res) << endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}