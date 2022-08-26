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
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n), p(n);
    range(i, n) cin >> a[i];
    range(i, n) cin >> b[i];
    range(i, n) cin >> c[i];
    range(i, n) {
        p[i] = a[i];
        if (p[i] == p[(i+n-1)%n]) p[i] = b[i];
    }
    int banned = p[1%n], banned2 = p[n-1];
    if (a[0] != banned && a[0] != banned2) p[0] = a[0];
    if (b[0] != banned && b[0] != banned2)  p[0] = b[0];
    if (c[0] != banned && c[0] != banned2) p[0] = c[0];
    range(i, n ) cout << p[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}