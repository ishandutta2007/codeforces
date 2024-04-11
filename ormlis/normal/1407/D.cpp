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
    int n;
    cin >> n;
    vector<int> h(n);
    range(i, n) cin >> h[i];
    vector<int> dp(n);
    vector<int> stk1 = {0}, stk2 = {0};
    dp[0] = 0;
    for(int i = 1; i <  n; ++i) {
        dp[i] = dp[i-1] + 1;
        bool bad = false;
        while(!stk1.empty() && h[stk1.back()] >= h[i]) {
            if (!bad && h[i-1] >= h[i]) {
                dp[i] = min(dp[i], dp[stk1.back()] + 1);
                if (h[stk1.back()] == h[i]) bad = true;
            }
            stk1.pop_back();
        }
        if (!stk1.empty() && !bad) dp[i] = min(dp[i], dp[stk1.back()] + 1);
        stk1.push_back(i);

        while(!stk2.empty() && h[stk2.back()] <= h[i]) {
            if (!bad && h[i-1] < h[i]) {
                dp[i] = min(dp[i], dp[stk2.back()] + 1);
                if (h[stk2.back()] == h[i]) bad = true;
            }
            stk2.pop_back();
        }
        if (!stk2.empty() && !bad) dp[i] = min(dp[i], dp[stk2.back()] + 1);
        stk2.push_back(i);
    }
    cout << dp[n-1] << "\n";
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