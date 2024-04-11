#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll INF = 2e18;
const int INFi = 2e9;

void solve() {
    int n; cin >> n;
    vector<ll> dp(n + 1, -INF);
    dp[0] = 0;
    range(i, n) {
        int x; cin >> x;
        for(int j = n - 1; j >= 0; --j) {
            if (dp[j] == -INF) continue;
            if (dp[j] + x < 0) continue;
            dp[j + 1] = max(dp[j + 1], dp[j] + x);
        }
    }
    for(int i = n; i >= 0; --i) {
        if (dp[i] != -INF) {
            cout << i << '\n';
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}