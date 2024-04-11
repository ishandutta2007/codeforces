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
const int maxN = 1e5 + 100;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<int> x, y;
    vector<string> a(n);
    range(i, n) {
        cin >> a[i];
        range(j, n) if (a[i][j] == '*') {
            x.push_back(i);
            y.push_back(j);
        }
    }
    sort(all(x));
    x.resize(unique(all(x)) - x.begin());
    sort(all(y));
    y.resize(unique(all(y)) - y.begin());
    if (x.size() == 1) {
        int d = (x[0] + 1) % n;
        x.push_back(d);
    }
    if (y.size() == 1) {
        int d = (y[0] + 1) % n;
        y.push_back(d);
    }
    for(auto &xx : x) {
        for(auto &yy : y) {
            a[xx][yy] = '*';
        }
    }
    range(i, n) cout << a[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}