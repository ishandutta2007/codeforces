#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define pb push_back

long long n, h, lis[2222], dp[2][2222];

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> h;
    REP (i, n) {
        cin >> lis[i];
        if (lis[i] > h || i && abs(lis[i] - lis[i - 1]) > 1) {
            cout << 0;
            return 0;
        }
    }
    if (lis[0] < h - 1) {
        cout << 0;
        return 0;
    } else if (lis[0] == h) {
        dp[0][0] = 1;
        dp[1][0] = 0;
    } else {
        dp[0][0] = 1;
        dp[1][0] = 1;
    }
    FOR (i, 1, n - 1) {
        if (lis[i] - lis[i - 1] == 0) {
            dp[0][i] = dp[0][i - 1];
            if (lis[i] - h) dp[0][i] += dp[1][i - 1];
            dp[1][i] = dp[0][i] * (h - lis[i]);
        } else if (lis[i] - lis[i - 1] == -1) {
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = dp[0][i] * (h - lis[i]);
        } else {
            dp[0][i] = dp[1][i - 1];
            dp[1][i] = dp[1][i - 1] * (h - lis[i]);
        }
        dp[0][i] %= mod;
        dp[1][i] %= mod;
        // cout << i << ' ' << dp[0][i] << ' ' << dp[1][i] << endl;
    }
    if (lis[n - 1] == h) cout << dp[0][n - 1];
    else if (lis[n - 1] == h - 1) cout << dp[1][n - 1];
    else cout << 0;
}