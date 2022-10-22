#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define F0R(i, a) for (int i = 0; i < a; ++i)

int n, k, N, tot, a[100000], t[100000], dp[100000];

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    F0R(i, n) cin >> a[i];
    F0R(i, n) cin >> t[i];
    
    N = 0;
    F0R(i, n) {
        if (t[i]) {
            N += a[i];
        }
    }

    tot = 0;
    FOR(i, 0, k) {
        if (t[i] == 0) {
            tot += a[i];
        }
    }
    dp[0] = tot;

    FOR(i, 1, n-k+1) {
        if (t[i+k-1] == 0) {
            tot += a[i+k-1];
        }
        if (t[i-1] == 0) {
            tot -= a[i-1];
        }
        dp[i] = max(dp[i-1], tot);
    }

    cout << dp[n-k] + N;
    return 0;
}