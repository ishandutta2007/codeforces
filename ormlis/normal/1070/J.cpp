#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
const ll INF = 2e18;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    const int L = 26;
    vector<int> cnt(L);
    string s; cin >> s;
    for(auto &c : s) cnt[c - 'A']++;
    auto get_dp = [&] (int wh) {
        vector<bool> dp(n + 1);
        dp[0] = 1;
        range(i, L) {
            if (i == wh) continue;
            for(int j = n; j >= cnt[i]; --j) {
                dp[j] = dp[j] | dp[j - cnt[i]];
            }
        }
        return dp;
    };
    {
        auto dp1 = get_dp(-1);
        if (dp1[n]) {
            cout << "0\n";
            return;
        }
    }
    ll answer = INF;
    range(i, L) {
        auto dp = get_dp(i);
        for(int j = 0; j <= n; ++j) {
            if (j + cnt[i] < n) continue;
            if (!dp[j]) continue;
            int use = n - j;
            int dont_use = cnt[i] - use;
            int other = k - j - cnt[i];
            if (other >= m) {
                answer = 0;
                continue;
            }
            answer = min(answer, 1ll * use * (m - other));
        }
    }
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}