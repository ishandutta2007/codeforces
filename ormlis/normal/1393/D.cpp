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
const int maxN = 1e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char> (m));
    range(i, n) range(j, m) cin >> a[i][j];
    vector<vector<int>> min_dist(n, vector<int> (m, INFi));
    range(i, n) {
        range(j, m) {
            if (!j || a[i][j] != a[i][j-1]) min_dist[i][j] = 1;
            if (j) {
                min_dist[i][j] = min(min_dist[i][j], min_dist[i][j-1] + 1);
            }
            if (!i || a[i][j] != a[i-1][j]) min_dist[i][j] = 1;
            if (i) {
                min_dist[i][j] = min(min_dist[i][j], min_dist[i-1][j] + 1);
            }
        }
    }
    for(int i = n - 1; i >= 0; --i) {
        for(int j = m - 1; j >= 0; --j) {
            if (j == m - 1 || a[i][j] != a[i][j+1]) min_dist[i][j] = 1;
            if (j != m - 1) {
                min_dist[i][j] = min(min_dist[i][j], min_dist[i][j+1] + 1);
            }
            if (i == n - 1 || a[i][j] != a[i+1][j]) min_dist[i][j] = 1;
            if (i != n - 1) {
                min_dist[i][j] = min(min_dist[i][j], min_dist[i+1][j] + 1);
            }
        }
    }
    ll ans = 0;
    range(i, n) range(j, m) ans += min_dist[i][j];
    cout << ans << "\n";
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