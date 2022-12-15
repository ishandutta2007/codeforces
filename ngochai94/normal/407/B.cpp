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

long long lis[1111], dp[2][1111], n; 

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    FOR (i, 1, n) cin >> lis[i];
    dp[0][1] = 1;
    dp[1][1] = 2;
    FOR (i, 2, n) {
        dp[0][i] = 1 + dp[1][i - 1];
        dp[0][i] %= mod;
        dp[1][i] = dp[0][i] * 2 - dp[0][lis[i]] + 1 + mod;
        dp[1][i] %= mod;
    }
    cout << dp[1][n];
}