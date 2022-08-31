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
const int maxN = 2e3 + 1;
const int md1 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> prevdp(k, -1);
    prevdp[0] = 0;
    range(i, n) {
        vector<vector<ll>> dp(m / 2 + 1, vector<ll>(k, -1));
        dp[0][0] = 0;
        range(j, m) {
            ll x;
            cin >> x;
            auto newdp = dp;
            for (int e = 0; e < m / 2; ++e) {
                range(f, k) {
                    if (dp[e][f] == -1) continue;
                    newdp[e + 1][(f + x) % k] = max(newdp[e + 1][(f + x) % k], dp[e][f] + x);
                }
            }
            swap(newdp, dp);
        }
        auto newdp = prevdp;
        range(j, k) {
            range(e, m / 2 + 1) dp[0][j] = max(dp[0][j], dp[e][j]);
        }
        range(e, k) {
            range(j, k) {
                if (dp[0][e] == -1 || prevdp[j] == -1) continue;
                newdp[(e + j) % k] = max(newdp[(e + j) % k], dp[0][e] + prevdp[j]);
            }
        }
        swap(newdp, prevdp);
    }
    cout << prevdp[0] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}