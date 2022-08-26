#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    range(i, n) range(j, m) cin >> a[i][j];
    range(i, n) range(j, m) a[i][j] -= i + j;
    vector<ll> ans;
    range(i, n) range(j, m) ans.push_back(a[i][j]);
    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());
    ll answer = INF;
    for(auto &res: ans) {
        vector<vector<ll>> dp(n, vector<ll> (m, INF));
        if (res > a[0][0]) break;
        dp[0][0] = 0;
        range(i, n) {
            range(j, m) {
                if (res > a[i][j]) continue;
                if (i) dp[i][j] = min(dp[i][j], dp[i-1][j]);
                if (j) dp[i][j] = min(dp[i][j], dp[i][j-1]);
                dp[i][j] += a[i][j] - res;
            }
        }
        answer = min(answer, dp[n-1][m-1]);
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}