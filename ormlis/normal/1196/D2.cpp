#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 5001;
ll md = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    vector<int> a(n, 0);
    range(i, n) {
        if (s[i] == 'R') a[i] = 0;
        if (s[i] == 'G') a[i] = 1;
        if (s[i] == 'B') a[i] = 2;
    }
    int ans = n;
    range(i, 3) {
        vector<int> dp(n, 0);
        range(j, k) {
            if (a[j] != (j + i) % 3) {
                dp[k - 1]++;
            }
        }
        ans = min(ans, dp[k - 1]);
        for(int j = k; j < n; ++j) {
            dp[j] = dp[j - 1];
            if (a[j] != (j + i) % 3) dp[j]++;
            if (a[j - k] != (j - k + i) % 3) dp[j]--;
            ans = min(ans, dp[j]);
        }
    }
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}