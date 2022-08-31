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
const int maxN = 2006;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

bool a[maxN][7];
bool d[10][7] = {
        {1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1},
        {0, 1, 1, 1, 0, 1, 0},
        {1, 1, 0, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1}
};

void solve() {
    int n, k;
    cin >> n >> k;
    range(i, n) {
        range(j, 7) {
            char x;
            cin >> x;
            if (x == '1') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    vector<vector<int>> need_to(n, vector<int>(10));
    range(i, n) {
        range(e, 10) {
            need_to[i][e] = 0;
            range(j, 7) {
                if (!d[e][j] && a[i][j]) {
                    need_to[i][e] = 10000;
                    break;
                }
                if (d[e][j] != a[i][j]) need_to[i][e]++;
            }
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1)),
            pref(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        vector<pair<pair<int, int>, int>> for_sort(k + 1);
        range(u, k + 1) {
            pair<int, int> kek = {-1, -1};
            range(e, 10) {
                if (need_to[i][e] > 8) continue;
                if (u - need_to[i][e] < 0) continue;
                if (dp[i][u-need_to[i][e]] == -1) continue;
                pair<int, int> kek2 = {dp[i][u-need_to[i][e]], e};
                if (kek < kek2) {
                    pref[i+1][u] = e;
                }
                kek = max(kek, kek2);
            }
            for_sort[u] = {kek, u};
        }
        sort(all(for_sort));
        range(j, k + 1) {
            if (for_sort[j].first.first == -1) continue;
            dp[i+1][for_sort[j].second] = j;
        }
    }
    if (dp[n][k] == -1) {
        cout << -1;
        return;
    }
    vector<int> ans(n);
    for(int i = n - 1; i >= 0; --i) {
        ans[i] = pref[i+1][k];
        int w = need_to[i][pref[i+1][k]];
        k -= w;
    }
    range(i, n) cout << ans[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}