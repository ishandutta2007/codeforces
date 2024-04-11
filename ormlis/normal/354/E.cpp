#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef unsigned long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    ll n; cin >> n;
    ll n1 = n;
    vector<vector<int>> dp(21, vector<int> (10));
    vector<vector<ar<int, 3>>> pref(21, vector<ar<int, 3>> (10));
    dp[0][0] = 1;
    vector<int> to(21);
    for(int i = 1; i < 21; ++i) {
        to[i] = n % 10;
        n /= 10;
    }
    for(int i = 1; i < 21; ++i) {
        range(j, 10) {
            if (dp[i-1][j]) {
                for(int cnt4 = 0; cnt4 < 7; ++cnt4) {
                    for(int cnt7 = 0; cnt4 + cnt7 < 7; ++cnt7) {
                        int s = j + cnt4 * 4 + cnt7 * 7;
                        if (s % 10 == to[i]) {
                            dp[i][s/10] = 1;
                            pref[i][s/10] = {j, cnt4, cnt7};
                        }
                    }
                }
            }
        }
    }
    if (!dp[20][0]) {
        cout << "-1\n";
        return;
    }
    vector<pair<int, int>> path;
    for(int i = 20, j = 0; i >= 1; --i) {
        path.emplace_back(pref[i][j][1], pref[i][j][2]);
        j = pref[i][j][0];
    }
    vector<ll> ans(6, 0);
    ll cur = 1;
    reverse(all(path));
    for(auto x: path) {
        range(i, x.first) {
            ans[i] += cur * 4;
        }
        for(int i = x.first; i < x.first + x.second; ++i) {
            ans[i] += cur * 7;
        }
        cur *= 10;
    }
    ll s = 0;
    range(i, 6) s += ans[i];
    if (s != n1) {
        cout << "-1\n";
        return;
    }
    range(i, 6) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}