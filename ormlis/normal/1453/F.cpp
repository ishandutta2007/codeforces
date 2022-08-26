#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < (n); ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 1e9;
const int maxN = 3e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, INFi));
    dp[n-1][n] = 0;
    for(int i = n - 2; i >= 0; --i) {
        vector<int> cnt(n + 1);
        int all_cnt = 0;
        for(int j = i + 1; j <= i + a[i]; ++j) {
            if (dp[j][i+a[i]+1] != INFi) {
                dp[i][j] = dp[j][i + a[i] + 1] + all_cnt;
            }
            cnt[a[j] + j]++;
            all_cnt++;
            all_cnt -= cnt[j];
        }
        for(int j = i + a[i] - 1; j >= i + 1; --j) dp[i][j] = min(dp[i][j], dp[i][j + 1]);
    }
    cout << dp[0][1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}