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
const int maxN = 1500 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int a[maxN][maxN];
int dp[maxN][maxN];
using cols = ar<pair<int, int>, 11>;

ar<pair<int, int>, 11> colors[maxN][maxN];
int n, q;
int was[maxN * maxN];
int T = 0;

cols merge(cols &x, cols &y) {
    T++;
    cols c;
    int i = 0;
    int j = 0;
    range(t, q + 1) {
        while (i <= q && was[x[i].second] == T) i++;
        while (j <= q && was[y[j].second] == T) j++;
        if (i == q + 1) {
            c[t] = y[j++];
        } else if (j == q + 1) {
            c[t] = x[i++];
        } else if (x[i].first < y[j].first) {
            c[t] = x[i++];
        } else {
            c[t] = y[j++];
        }
        if (c[t].second) was[c[t].second] = T;
    }
    return c;
}

struct super_queue {
    vector<cols> stk1;
    vector<cols> stk2;
    vector<cols> pref1;
    vector<cols> pref2;

    void push(cols &x) {
        stk1.push_back(x);
        if (pref1.empty()) {
            pref1.push_back(x);
        } else {
            auto c = merge(x, pref1.back());
            pref1.push_back(c);
        }
    }

    void pop() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                auto x = stk1.back();
                stk1.pop_back();
                pref1.pop_back();
                stk2.push_back(x);
                if (pref2.empty()) {
                    pref2.push_back(x);
                } else {
                    auto c = merge(x, pref2.back());
                    pref2.push_back(c);
                }
            }
        }
        stk2.pop_back();
        pref2.pop_back();
    }

    int get() {
        if (pref1.empty() && pref2.empty()) return INFi;
        if (pref2.empty()) {
            return pref1.back()[q].first - 1;
        }
        if (pref1.empty()) {
            return pref2.back()[q].first - 1;
        }
        return merge(pref2.back(), pref1.back())[q].first - 1;
    }
};

void build_colors() {
    range(i, n) {
        set<pair<int, int>> last;
        map<int, int> mp;
        for (int j = n - 1; j >= 0; --j) {
            int x = a[i][j];
            if (mp.count(x)) {
                last.erase({mp[x], x});
            }
            last.insert({j, x});
            mp[x] = j;
            auto it = last.begin();
            range(e, q + 1) {
                if (e >= last.size()) {
                    colors[i][j][e] = {INFi, 0};
                } else {
                    colors[i][j][e] = *it;
                    it++;
                }
            }
        }
    }
}

void solve() {
    cin >> n >> q;
    range(i, n) range(j, n) cin >> a[i][j];
    vector<int> ans(n + 1, 0);
    build_colors();
    range(j, n) {
        super_queue sq;
        int sz = 0;
        range(i, n) {
            while (i + sz < n && j + sz < n && sq.get() - j + 1 >= sz) {
                sq.push(colors[i + sz][j]);
                sz++;
            }
            int x = sq.get();
            if (sq.get() - j + 1 >= sz) {
                dp[i][j] = sz;
            } else {
                dp[i][j] = sz - 1;
            }
            ans[dp[i][j]]++;
            sq.pop();
            sz--;
        }
    }
    for (int i = n - 1; i >= 0; --i) ans[i] += ans[i + 1];
    for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
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