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

long long n, m, b, md;
long long lis[555], dp[2][555][555];

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m >> b >> md;
    FOR (i, 1, n) cin >> lis[i];
    dp[0][0][0] = 1;
    FOR (i, 1, n) FOR (j, 0, m) FOR (k, 0, b) {
        dp[i&1][j][k] = dp[1-(i&1)][j][k];
        if (j && k - lis[i] >= 0) dp[i&1][j][k] += dp[i&1][j - 1][k - lis[i]];
        dp[i&1][j][k] %= md;
    }
    long long res = 0;
    FOR (i, 0, b) {
        res += dp[n&1][m][i];
        res %= md;

    }
    cout << res;
}