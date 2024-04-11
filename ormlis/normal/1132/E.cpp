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

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };


void solve() {
    ll W; cin >> W;
    vector<ll> a(8);
    vector<ll> u(8);
    range(i, 8) cin >> a[i];
    ll x = 0;
    for(ll i = 7; i >= 0; --i) {
        u[i] = min(a[i], (W-x)/(i+1));
        x += (i+1) * min(a[i], u[i]);
    }
    vector<int> dp(1001, 0);
    if (W - x >= 8) {
        cout << x;
        return;
    }
    dp[500] = 1;
    range(i, 8) {
        vector<int> dp2 = dp;
        range(j, 1001) {
            for(int e = j % (i + 1); e < 1001; e += i + 1) {
                if (dp[e]) {
                    if (e <= j && a[i] - u[i] >= (j-e)/(i+1)) {
                        dp2[j] = true;
                    }
                    else if (e >= j && u[i] >= (e - j) / (i + 1)) {
                        dp2[j] = true;
                    }
                }
            }
        }
        dp = dp2;
    }
    for(ll z = W - x; z >= 0; --z) {
        if (dp[z+500]) {
            cout << x + z << "\n";
            return;
        }
    }
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