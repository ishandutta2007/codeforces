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
    int n, c; cin >> n >> c;
    vector<int> a(n), b(n, INFi);
    range(i, n) cin >> a[i];
    range(i, n - 1) cin >> b[i];
    ll days = 0;
    ll answer = INF;
    ll cur = 0;
    range(i, n) {
        answer = min(answer, max(0ll, (c - cur + (a[i] - 1)) / a[i]) + days);
        ll d = max(0ll, (b[i] - cur + (a[i] - 1)) / a[i]);
        days += d;
        cur += d * a[i];
        cur -= b[i];
        days++;
    }
    cout << answer << '\n';
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