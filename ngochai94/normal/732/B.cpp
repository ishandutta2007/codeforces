#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back

int n, k, lis[555], dp[555][555], ret[555];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    REP (i, n) cin >> lis[i];
    REP (i, k + 1) dp[0][i] = i;
    FOR (i, 1, n - 1) REP (j, k + 1)
    {
        dp[i][j] = j + dp[i - 1][max(0, k - lis[i] - lis[i - 1] - j)];
    }
    int ans = 0;
    REP (i, k + 1)
    {
        if (dp[n - 1][ans] > dp[n - 1][i]) ans = i;
    }
    cout << dp[n - 1][ans] << endl;
    ret[n - 1] = ans;
    FORD (i, n - 2, 0) ret[i] = max(0, k - lis[i] - lis[i + 1] - ret[i + 1]);
    REP (i, n) cout << ret[i] + lis[i] << ' ';
}