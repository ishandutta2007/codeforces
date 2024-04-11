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
const int maxN = 2e5 + 15;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ans;

    vector<pair<int, int>> pa;
    auto solve = [&](int l, int r) {
        pa.emplace_back(l, r);
        for (int step = 2; step <= r - l; step *= 2) {
            for (int i = l; i < r; i += step) {
                for (int j = i; j < i + step / 2; ++j) {
                    ans.emplace_back(j, j + step / 2);
                }
            }
        }
    };
    int sz = 0;
    while (sz < n) {
        int k = 1;
        while (sz + k <= n) k *= 2;
        k /= 2;
        solve(sz + 1, sz + k + 1);
        sz += k;
    }
    int e = 1;
    for (int i = (int) pa.size() - 1; i >= 2; --i) {
        while (pa[i - 1].second - pa[i - 1].first > pa[i].second - pa[i].first) {
            for (int j = pa[i].first; j < pa[i].second; ++j) {
                ans.emplace_back(e, j);
                e++;
            }
            pa[i].second += pa[i].second - pa[i].first;
        }
        for(int j = pa[i].first; j < pa[i].second; ++j) {
            ans.emplace_back(j, pa[i-1].first + j - pa[i].first);
        }
        pa[i-1].second += pa[i].second - pa[i].first;
    }
    cout << ans.size() << "\n";
    for (auto &x: ans) {
        cout << (x.first - 1) % n + 1 << " " << (x.second - 1) % n + 1 << "\n";
    }
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