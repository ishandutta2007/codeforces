#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

typedef long double old;
typedef unsigned long long ll;

const int N = 2001;

int dp[N][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (a[0] == 1) {
        dp[0][0] = 1;
    } else {
        dp[0][1] = 1;
    }
    ///1 2 1 2
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            dp[i][j] = dp[i - 1][j];
        }
        if (a[i] == 1) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][2] = max(dp[i - 1][2] + 1, dp[i - 1][1] + 1);
        }
        if (a[i] == 2) {
            dp[i][1] = max(dp[i - 1][1] + 1, dp[i - 1][0] + 1);
            dp[i][3] = max(dp[i - 1][3] + 1, dp[i - 1][2] + 1);
        }
    }
    cout << *max_element(dp[n - 1], dp[n - 1] + 4);
    return 0;
}