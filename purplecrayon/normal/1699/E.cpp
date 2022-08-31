#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e2+10, MOD = 1e9+7;

const int M1 = 1e9 + 21, M2 = 1.1e9 + 17;
pair<int, int> add(pair<int, int> a, pair<int, int> b) {
    pair<int, int> ans{a.first + b.first, a.second + b.second};
    if (ans.first >= M1) ans.first -= M1;
    if (ans.second >= M2) ans.second -= M2;
    return ans;
}
pair<int, int> sub(pair<int, int> a, pair<int, int> b) {
    pair<int, int> ans{a.first - b.first, a.second - b.second};
    if (ans.first < 0) ans.first += M1;
    if (ans.second < 0) ans.second += M2;
    return ans;
}
void solve() {
    int n, m; cin >> n >> m;
    vector<bool> has(m + 1);
    while (n--) {
        int x; cin >> x;
        has[x] = 1;
    }

    for (int i = 0; i <= m; i++) n += has[i];
    n++;

    if (has[1]) {
        vector<bool> prime(m + 1, 1);
        int ans = 0;
        for (int i = 2; i <= m; i++) if (prime[i]) {
            for (int j = i; j <= m; j += i) {
                if (has[j]) ans = max(ans, i - 1);
                prime[j] = 0;
            }
        }
        cout << ans << '\n';
        return;
    }

    vector<pair<int, int>> dp(m + 1); dp[1] = {1, 1};

    int ans = m;
    int cnt = 0;
    for (int l = 2, r = l; l <= m; l++) {
        while (r <= m && cnt < n) {
            for (int i = r; i <= m; i += r) {
                if (has[i] && dp[i].first && dp[i].second) cnt--;
                dp[i] = add(dp[i], dp[i / r]);
                if (has[i] && dp[i].first && dp[i].second) cnt++;
            }
            r++;
        }

        if (cnt == n) {
            ans = min(ans, r - l - 1);
        }

        for (int i = m - m % l; i >= l; i -= l) {
            if (has[i] && dp[i].first && dp[i].second) cnt--;
            dp[i] = sub(dp[i], dp[i / l]);
            if (has[i] && dp[i].first && dp[i].second) cnt++;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}