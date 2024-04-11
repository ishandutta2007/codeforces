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

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 305;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    vector<vector<int>> cl(3);
    range(i, 3) {
        int x; cin >> x;
        cl[i].resize(x, 0);
    }
    range(i, 3) range(j, (int)cl[i].size()) cin >> cl[i][j];
    vector<vector<vector<ll>>> dp(cl[0].size() + 1, vector<vector<ll>> (cl[1].size() + 1, vector<ll> (cl[2].size() + 1, -INFi)));
    range(i, 3) sort(all(cl[i]));
    dp[0][0][0] = 0;
    ll ans = 0;
    range(i, (int)cl[0].size() + 1) {
        range(j, (int)cl[1].size() + 1) {
            range(e, (int)cl[2].size() + 1) {
                if (i + j + e < 2) continue;
                if (max(i, max(j, e)) == i +j + e) continue;
                if (i && j) {
                    dp[i][j][e] = max(dp[i][j][e], dp[i-1][j-1][e] + 1ll * cl[0][(int)cl[0].size() - i] * cl[1][(int)cl[1].size() - j]);
                }
                if (i && e) {
                    dp[i][j][e] = max(dp[i][j][e], dp[i-1][j][e-1] + 1ll * cl[0][(int)cl[0].size() - i] * cl[2][(int)cl[2].size() - e]);
                }
                if (j && e) {
                    dp[i][j][e] = max(dp[i][j][e], dp[i][j-1][e-1] + 1ll * cl[2][(int)cl[2].size() - e] * cl[1][(int)cl[1].size() - j]);
                }
                ans = max(ans, dp[i][j][e]);
            }
        }
    }
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