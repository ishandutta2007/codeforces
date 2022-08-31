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
const int maxN = 2e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m;
    cin >> n >> m;
    int sx, sy, fx, fy; cin >> sx >> sy >> fx >> fy;
    vector<int> x(m), y(m);
    range(i, m) {
        cin >> x[i] >> y[i];
    }
    m++;
    x.push_back(sx); y.push_back(sy);
    vector<int> orderx(m), ordery(m);
    range(i, m) orderx[i] = ordery[i] = i;
    sort(all(orderx), [&] (const int &a, const int &b) {
        return x[a] < x[b];
    });
    sort(all(ordery), [&] (const int &a, const int &b) {
        return y[a] < y[b];
    });
    set<pair<int, int>> ds;
    vector<int> timet(m, INFi);
    timet[m-1] = 0;
    range(i, m) ds.insert({timet[i], i});

    auto check = [&] (int i, int j, int t) {
        int newt = t + min(abs(x[i] - x[j]), abs(y[i] - y[j]));
        if (newt < timet[j]) {
            ds.erase({timet[j], j});
            timet[j] = newt;
            ds.insert({newt, j});
        }
    };

    vector<int> posx(m);
    vector<int> posy(m);
    range(i, m) posx[orderx[i]] = i;
    range(i, m) posy[ordery[i]] = i;

    while(!ds.empty()) {
        auto p = *ds.begin();
        ds.erase(ds.begin());
        int px = posx[p.second];
        int py = posy[p.second];
        int t = p.first;
        int i = p.second;
        if (px != m - 1) check(i, orderx[px+1], t);
        if (px != 0) check(i, orderx[px-1], t);
        if (py != m - 1) check(i, ordery[py+1], t);
        if (py != 0) check(i, ordery[py-1], t);
    }

    int ans = 2e9;
    range(i, m) {
        ans = min(ans, timet[i] + abs(x[i] - fx)  +abs(y[i] - fy));
    }
    cout << ans;
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