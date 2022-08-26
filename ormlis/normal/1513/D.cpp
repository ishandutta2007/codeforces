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
const int maxN = 3e5 + 100;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, p; cin >> n >> p;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<bool> was(n);
    int k = 0;
    ll cost = 0;
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&] (const int &x, const int &y) {
        return a[x] < a[y];
    });
    for(auto &i : ord) {
        if (a[i] >= p) break;
        if (was[i]) continue;
        int t = 0;
        for(int j = i; j < n; ++j) {
            if (a[j] % a[i]) break;
            t++;
            if (was[j]) break;
            was[j] = true;
        }
        for(int j = i - 1; j >= 0; --j) {
            if (a[j] % a[i]) break;
            t++;
            if (was[j]) break;
            was[j] = true;
        }
        t--;
        k += t;
        cost += 1ll * t * a[i];
    }
    cost += 1ll * (n - 1 - k) * p;
    cout << cost << '\n';
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