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
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;

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
const int maxN = 100;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


void solve() {
    int n; cin >> n;
    vector<vector<char>> a(n, vector<char> (n));
    range(i, n) range(j, n) cin >> a[i][j];
    vector<pair<int, int>> ans1, ans2;
    if (a[0][1] == '1') ans2.emplace_back(0, 1);
    else ans1.emplace_back(0, 1);
    if (a[1][0] == '1') ans2.emplace_back(1, 0);
    else ans1.emplace_back(1, 0);
    if (a[n-1][n-2] == '1') ans1.emplace_back(n-1, n-2);
    else ans2.emplace_back(n-1, n-2);
    if (a[n-2][n-1] == '1') ans1.emplace_back(n-2, n-1);
    else ans2.emplace_back(n-2, n-1);
    if (ans1.size() > ans2.size()) swap(ans1, ans2);
    cout << ans1.size() << "\n";
    for(auto &[i, j] : ans1) cout << i + 1 << " " << j + 1 << "\n";
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