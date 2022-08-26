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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    range(i, n) range(j, m) cin >> a[i][j];
    ll ans = 0;
    range(i, (n+1)/2) {
        range(j, (m+1)/2) {
            vector<int> cur = {a[i][j], a[n-1-i][j], a[n-1-i][m-1-j], a[i][m-1-j]};
            sort(all(cur));
            int v = cur[1];
            ans += abs(a[i][j] - v);
            a[i][j] = v;
            ans += abs(a[i][m-1-j] - v);
            a[i][m-1-j] = v;
            ans += abs(a[n-1-i][j] - v);
            a[n-1-i][j] = v;
            ans += abs(a[n-1-i][m-1-j] - v);
            a[n-i-1][m-1-j] = v;
        }
    }
    cout << ans << "\n";
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