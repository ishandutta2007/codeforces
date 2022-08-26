#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> s(n);
    range(i, n) cin >> s[i].first >> s[i].second;
    ll sa = 0, sb = 0;
    range(i, n) sa += s[i].first, sb += s[i].second;
    ll ans = sa / k + sb / k;
    sa %= k;
    sb %= k;
    /*
    range(i, n) {
        ll vza = min(sa, (ll)s[i].first);
        ll vzb = min(sb, (ll)s[i].second);
        if (vza + vzb >= k) {
            cout << ans + 1;
            return;
        }
    }*/
    if (sa + sb < k) {
        cout << ans;
        return;
    }
    vector<vector<pair<int, int>>> nxt(k);
    range(i, k) range(j, k) nxt[(i+j)%k].push_back({i, j});
    vector<vector<bool>> dp(k, vector<bool> (k, false));
    dp[0][0] = true;
    range(i, n) {
        auto new_dp = dp;
        if (s[i].first == 0 || s[i].second == 0) continue;
        if (s[i].first + s[i].second < k) continue;
        int mina = max(1, k - s[i].second);
        int maxa = min(s[i].first, k - 1);
        range(e, k) {
            int cnt = 0;
            int r = k - mina, l = k - maxa;
            for(int f = l; f < r; ++f) cnt += dp[nxt[e][f].first][nxt[e][f].second];
            for(int f = 0; f < k; ++f) {
                cnt += dp[nxt[e][r].first][nxt[e][r].second];
                r++;
                if (r == k) r = 0;
                if (cnt) new_dp[nxt[e][f].first][nxt[e][f].second] = true;
                cnt -= dp[nxt[e][l].first][nxt[e][l].second];
                l++;
                if (l == k) l = 0;
            }
        }
        dp = new_dp;
    }
    range(i, k) {
        range(j, k) {
            if (dp[i][j]) {
                int osta = sa - i, ostb = sb - j;
                if (osta < 0) osta += k;
                if (ostb < 0) ostb += k;
                if (osta + ostb < k) {
                    cout << ans + 1;
                    return;
                }
            }
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}