#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 1e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> cur(4, vector<int>(n));
    range(i, 4) {
        range(j, n) cin >> cur[i][j];
    }
    vector<ar<int, 3>> ans;
    while (k > 0) {
        int t = -1;
        int f = -1;
        range(i, n) {
            if (cur[1][i] == cur[0][i] && cur[1][i]) {
                ans.push_back({cur[1][i], 1, i + 1});
                cur[1][i] = 0;
                k--;
            }
            if (cur[2][i] == cur[3][i] && cur[2][i]) {
                ans.push_back({cur[2][i], 4, i + 1});
                cur[2][i] = 0;
                k--;
            }
            if (cur[1][i] == 0) t = i;
            if (cur[2][i] == 0) f = i;
        }
        if (k == 0) break;
        if (t == -1 && f == -1) {
            cout << "-1\n";
            return;
        }
        if (t != -1) {
            for (int to = t - 1; to >= 0; --to) {
                if (cur[1][to]) {
                    ans.push_back({cur[1][to], 2, to + 2});
                    swap(cur[1][to], cur[1][to + 1]);
                }
            }
            if (cur[2][0]) {
                ans.push_back({cur[2][0], 2, 1});
                swap(cur[2][0], cur[1][0]);
            }
            for (int d = 1; d < n; ++d) {
                if (cur[2][d]) {
                    ans.push_back({cur[2][d], 3, d});
                    swap(cur[2][d], cur[2][d - 1]);
                }
            }
            if (t != n - 1 && cur[1][n - 1]) {
                ans.push_back({cur[1][n - 1], 3, n});
                swap(cur[1][n - 1], cur[2][n - 1]);
            }
            for(int d = n - 2; d > t; --d) {
                if (cur[1][d]) {
                    ans.push_back({cur[1][d], 2, d + 2});
                    swap(cur[1][d], cur[1][d + 1]);
                }
            }
        } else {
            for(int d = f + 1; d < n; ++d) {
                if (cur[2][d]) {
                    ans.push_back({cur[2][d], 3, d});
                    swap(cur[2][d], cur[2][d - 1]);
                }
            }
            if (cur[1][n - 1]) {
                ans.push_back({cur[1][n - 1], 3, n});
                swap(cur[1][n - 1], cur[2][n - 1]);
            }
            for (int to = n - 2; to >= 0; --to) {
                if (cur[1][to]) {
                    ans.push_back({cur[1][to], 2, to + 2});
                    swap(cur[1][to], cur[1][to + 1]);
                }
            }
            if (cur[2][0] && f != 0) {
                ans.push_back({cur[2][0], 2, 1});
                swap(cur[2][0], cur[1][0]);
            }
            for (int d = 1; d < f; ++d) {
                if (cur[2][d]) {
                    ans.push_back({cur[2][d], 3, d});
                    swap(cur[2][d], cur[2][d - 1]);
                }
            }
        }
    }
    assert(ans.size() < 2e4);
    cout << ans.size() << '\n';
    for (auto &[i, x, y] : ans) cout << i << ' ' << x << ' ' << y << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}