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

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e6 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };
vector<pair<int, int>> a;
vector<pair<pair<int, int>, int>> xy;
vector<vector<int>> row, col;
int n;

bool check(ll m) {
    vector<vector<int>> g(n);
    range(i, (int)row.size()) {
        range(j, (int)row[i].size() - 1) {
            if (a[row[i][j+1]].first - a[row[i][j]].first <= m) {
                g[row[i][j+1]].push_back(row[i][j]);
                g[row[i][j]].push_back(row[i][j+1]);
            }
        }
    }
    range(i, (int)col.size()) {
        range(j, (int)col[i].size() - 1) {
            if (a[col[i][j+1]].second - a[col[i][j]].second <= m) {
                g[col[i][j+1]].push_back(col[i][j]);
                g[col[i][j]].push_back(col[i][j+1]);
            }
        }
    }
    vector<int> comp(n);
    function<void(int)> dfs = [&] (int v) {
        for(auto &u: g[v]) {
            if (comp[u]) continue;
            comp[u] = comp[v];
            dfs(u);
        }
    };
    int c = 1;
    range(i, n) {
        if (!comp[i]) {
            comp[i] = c;
            dfs(i);
            c++;
        }
    }
    c--;
    if (c == 1) return true;
    range(i, (int)row.size()) {
        range(e, (int)col.size()) {
            int y = a[row[i][0]].second;
            int x = a[col[e][0]].first;
            int j = 0, f = 0;
            while(j < (int)row[i].size() && a[row[i][j]].first < x) j++;
            while(f < (int)col[e].size() && a[col[e][f]].second < y) f++;
            vector<int> s;
            if (j != 0) {
                if (x - a[row[i][j-1]].first <= m) s.push_back(comp[row[i][j-1]]);
            }
            if (j != (int)row[i].size()) {
                if (a[row[i][j]].first - x <= m) s.push_back(comp[row[i][j]]);
            }
            if (f != 0) {
                if (y - a[col[e][f-1]].second <= m) s.push_back(comp[col[e][f-1]]);
            }
            if (f != (int)col[e].size()) {
                if (a[col[e][f]].second- y <= m) s.push_back(comp[col[e][f]]);
            }
            sort(all(s));
            s.resize(unique(all(s)) - s.begin());
            if (s.size() == c) {
                return true;
            }
        }
    }
    range(i, (int)row.size()) {
        range(j, (int)row[i].size() - 1) {
            vector<int> s;
            if (a[row[i][j+1]].first - a[row[i][j]].first <= 2 * m) {
                s.push_back(comp[row[i][j+1]]);
                s.push_back(comp[row[i][j]]);
            }
            sort(all(s));
            s.resize(unique(all(s)) - s.begin());
            if (s.size() == c) {
                return true;
            }
        }
    }

    range(i, (int)col.size()) {
        range(j, (int)col[i].size() - 1) {
            vector<int> s;
            if (a[col[i][j+1]].second - a[col[i][j]].second <= 2 * m) {
                s.push_back(comp[col[i][j+1]]);
                s.push_back(comp[col[i][j]]);
            }
            sort(all(s));
            s.resize(unique(all(s)) - s.begin());
            if (s.size() == c) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> n;
    xy.resize(n);
    a.resize(n);
    range(i, n) cin >> a[i].first >> a[i].second;
    range(i, n) xy[i] = {a[i], i};
    sort(all(xy));
    col.emplace_back();
    col.back().push_back(xy[0].second);
    for(int i = 1; i < n; ++i) {
        if (xy[i-1].first.first != xy[i].first.first) {
            col.emplace_back();
        }
        col.back().push_back(xy[i].second);
    }
    sort(all(xy), [] (pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
        if (a.first.second != b.first.second) return a.first.second < b.first.second;
        return a.first.first < b.first.first;
    });
    row.emplace_back();
    row.back().push_back(xy[0].second);
    for(int i = 1; i < n; ++i) {
        if (xy[i].first.second != xy[i-1].first.second) row.emplace_back();
        row.back().push_back(xy[i].second);
    }
    ll l = 0, r = 4e9 + 1;
    while(r - l > 1) {
        ll m = (r + l) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    if (r == 4e9 + 1) {
        cout << "-1\n";
        return;
    }
    cout << r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}