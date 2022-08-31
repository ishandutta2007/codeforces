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

const ll INF = 2e18 + 5;
const int INFi = 1e8;
const int maxN = 1e7 + 100;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<int> p(2 * n);
    range(i, 2 * n) cin >> p[i];
    auto pp = p;
    sort(all(pp));
    int res = INFi;
    range(rot, 2) {
        int cur = rot;
        auto t = p;
        range(_, 5 * n) {
            if (p == pp) {
                res = min(res, _);
                break;
            }
            if (cur) {
                range(i, n) swap(p[i], p[i + n]);
            } else {
                range(i, n) swap(p[2 * i], p[2 * i + 1]);
            }
            cur ^= 1;
        }
        p = t;
    }
    cout << (res == INFi ? -1 : res) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}