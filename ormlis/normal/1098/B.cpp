#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 2e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    range(i, n) {
        range(j, m) {
            char x;
            cin >> x;
            if (x == 'A') a[i][j] = 0;
            else if (x == 'C') a[i][j] = 1;
            else if (x == 'T') a[i][j] = 2;
            else a[i][j] = 3;
        }
    }
    ar<int, 3> ans = {INFi, -1, -1};
    vector<vector<int>> b(n, vector<int>(m));
    auto check0 = [&](int mask) {
        int res = 0;
        vector<vector<int>> need(2);
        range(j, 4) {
            if (mask & (1 << j)) {
                need[0].push_back(j);
            } else {
                need[1].push_back(j);
            }
        }
        range(i, n) {
            ar<int, 2> cnt = {0, 0};
            range(j, m) {
                int t = (i ^ (mask >> a[i][j])) & 1;
                if (t == 0) {
                    cnt[0]++;
                    cnt[1]++;
                    continue;
                }
                if (a[i][j] == need[i & 1][0]) {
                    cnt[(j & 1) ^ 1]++;
                } else {
                    cnt[j & 1]++;
                }
            }
            if (cnt[0] < cnt[1]) {
                res += cnt[0];
                range(j, m) {
                    b[i][j] = need[i&1][j & 1];
                }
            } else {
                res += cnt[1];
                range(j, m) {
                    b[i][j] = need[i&1][(j & 1) ^ 1];
                }
            }
        }
        return res;
    };
    auto check1 = [&](int mask) {
        int res = 0;
        vector<vector<int>> need(2);
        range(j, 4) {
            if (mask & (1 << j)) {
                need[0].push_back(j);
            } else {
                need[1].push_back(j);
            }
        }
        range(j, m) {
            ar<int, 2> cnt = {0, 0};
            range(i, n) {
                int t = (j ^ (mask >> a[i][j])) & 1;
                if (t == 0) {
                    cnt[0]++;
                    cnt[1]++;
                    continue;
                }
                if (a[i][j] == need[j & 1][0]) {
                    cnt[(i & 1) ^ 1]++;
                } else {
                    cnt[i & 1]++;
                }
            }
            if (cnt[0] < cnt[1]) {
                res += cnt[0];
                range(i, n) {
                    b[i][j] = need[j&1][i & 1];
                }
            } else {
                res += cnt[1];
                range(i, n) {
                    b[i][j] = need[j&1][(i & 1) ^ 1];
                }
            }
        }
        return res;
    };
    range(mask, 1 << 4) {
        if (__builtin_popcount(mask) != 2) continue;
        ans = min(ans, {check0(mask), mask, 0});
        ans = min(ans, {check1(mask), mask, 1});
    }
    if (ans[2] == 0) {
        check0(ans[1]);
    } else {
        check1(ans[1]);
    }
    string s = "ACTG";
    range(i, n) {
        range(j, m) {
            cout << s[b[i][j]];
        }
        cout << '\n';
    }
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