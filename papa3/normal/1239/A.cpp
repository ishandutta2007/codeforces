#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

#define MAX_N 1000010

int dp[MAX_N];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    dp[1] = 2;
    dp[0] = 2;
    for (int i = 2; i < MAX_N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }

    cout << (dp[n] + dp[m] + mod - 2) % mod;

    return 0;
}
/*

*/