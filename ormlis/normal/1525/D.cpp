#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<int> a, b;
    range(i, n) {
        int x; cin >> x;
        if (x == 1) a.push_back(i);
        else b.push_back(i);
    }
    int bn = b.size();
    int an = a.size();
    vector<vector<int>> dp(bn + 1, vector<int> (an + 1, INFi));
    dp[0][0] = 0;
    range(i, bn) {
        dp[i + 1][0] = 0;
        for(int j = 1; j <= an; ++j) {
            int x = a[j - 1];
            int y = b[i];
            dp[i + 1][j] = min(dp[i][j], dp[i][j - 1] + abs(x - y));
        }
    }
    cout << dp[bn][an] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(2) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}