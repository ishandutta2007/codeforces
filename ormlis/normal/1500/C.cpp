#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < (n); ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    range(i, n) range(j, m) cin >> a[i][j];
    range(i, n) range(j, m) cin >> b[i][j];
    /*vector<vector<int>> sorts(m, vector<int>(n));
    range(i, m) {
        iota(all(sorts[i]), 0);
        sort(all(sorts[i]), [&](const int x, const int y) {
            if (a[x][i] != a[y][i]) return a[x][i] < a[y][i];
            return x < y;
        });
    }*/
    vector<int> cur(n);
    vector<bool> ended(n);
    ended[n - 1] = true;
    vector<int> ans;
    map<vector<int>, vector<int>> mp;
    range(i, n) mp[a[i]].push_back(i);
    range(i, n) {
        if (mp[b[i]].empty()) {
            cout << "-1\n";
            return;
        }
        cur[i] = mp[b[i]][0];
        mp[b[i]].pop_back();
    }
    int ce = 1;
    range(i, n - 1) {
        if (cur[i] == cur[i + 1]) {
            ce++;
            ended[i] = true;
        }
    }
    auto check = [&](int st, int i, int j) {
        if (a[i][st] == a[j][st]) return 0;
        if (a[i][st] < a[j][st]) return 1;
        return -1;
    };
    vector<bool> used(m);
    vector<int> cntbad(m);
    vector<vector<int>> tobad(n);
    range(j, m) {
        range(i, n) {
            if (ended[i]) continue;
            int x = check(j, cur[i], cur[i + 1]);
            if (x == -1) {
                cntbad[j]++;
                tobad[i].push_back(j);
            }
        }
    }
    bool good = true;
    while (ce != n && good) {
        good = false;
        range(j, m) {
            if (used[j] || cntbad[j]) continue;
            ans.push_back(j);
            used[j] = true;
            good = true;
            range(i, n) {
                if (ended[i]) continue;
                if (check(j, cur[i], cur[i + 1]) == 1) {
                    ended[i] = true;
                    ce++;
                    for (auto &we : tobad[i]) {
                        cntbad[we]--;
                    }
                }
            }
            break;
        }
    }
    if (ce != n) {
        cout << "-1\n";
        return;
    }
    cout << ans.size() << '\n';
    reverse(all(ans));
    for (auto &x : ans) cout << x + 1 << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}