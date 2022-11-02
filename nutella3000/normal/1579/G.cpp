#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld long double
mt19937 Rand(0);

const int inf = 1e9 + 7;
const int N = 1e4 + 3, M = 2e3 + 4;

int n;
int a[N];
int dp[N][M];


void run() {
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    fill(dp[n], dp[n] + M, 0);
    for (int i = n - 1; i >= 0; --i) {
        for (int r = 0; r < M; ++r) {
            dp[i][r] = inf;
            if (a[i] <= r)
                dp[i][r] = max(0ll, dp[i + 1][r - a[i]] - a[i]);
            if (r + a[i] < M) chkmin(dp[i][r], dp[i + 1][r + a[i]] + a[i]);
        }
    }
    int res = inf;
    for (int i = 0; i < M; ++i)
        chkmin(res, dp[0][i] + i);
    cout << res << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}