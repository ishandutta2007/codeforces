#pragma Voodoo magic("superfast")
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

//   )
// 

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

int d[maxN];
int was[maxN];

//   )
void init() {
    for(int i = 1; i < maxN; ++i) {
        for(int j = i; j < maxN; j += i) d[j] += i;
    }
    for(int i = maxN - 1; i >= 1; --i) {
        if (d[i] >= maxN) continue;
        was[d[i]] = i;
    }
}

//   )
void solve() {
    int c; cin >> c;
    if (was[c] == 0) cout << "-1\n";
    else cout << was[c] << '\n';
}

//   )
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    init();
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}