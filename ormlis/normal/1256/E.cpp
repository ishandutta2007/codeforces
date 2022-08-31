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
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    range(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    vector<int> dp(n + 1, -1);
    vector<int> prev(n + 1, -1);
    dp[0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = i - 2; j >= max(i - 4, 1); j--) {
            if (dp[j - 1] != -1 && (dp[i] > dp[j - 1] + a[i - 1].first - a[j - 1].first || dp[i] == -1)) {
                dp[i] = dp[j - 1] + a[i - 1].first - a[j - 1].first;
                prev[i] = j - 1;
            }
        }
    }
    vector<int> ans(n);
    int cur = n;
    int color = 1;
    while(cur) {
        for(int j = cur; j > prev[cur]; --j) {
            ans[j - 1] = color;
        }
        color++;
        cur = prev[cur];
    }
    vector<int> ans2(n);
    range(i, n) {
        ans2[a[i].second] = ans[i];
    }
    cout << dp[n] << " " << color - 1 << "\n";
    range(i, n) {
        cout << ans2[i] << ' ';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}