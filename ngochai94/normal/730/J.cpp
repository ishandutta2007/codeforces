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

int n, remain[111], tot[111], all, dp[111][11111], k, cur;
vector<int> tmp;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) cin >> remain[i];
    REP (i, n) cin >> tot[i];
    REP (i, n) all += remain[i];
    REP (i, n) tmp.pb(tot[i]);
    sort(tmp.begin(), tmp.end());
    FORD (i, n - 1, 0)
    {
        cur += tmp[i];
        if (cur >= all)
        {
            k = n - i;
            break;
        }
    }
    reset(dp, -1);
    dp[0][0] = 0;
    REP (ii, n)
    {
        FORD (i, k - 1, 0) FORD (j, 100 * i, 0) if (dp[i][j] > -1) dp[i + 1][j + tot[ii]] = max(dp[i + 1][j + tot[ii]], dp[i][j] + remain[ii]);
    }
    int ans = 0;
    FOR (i, all, 100 * k + 1) ans = max(ans, dp[k][i]);
    //BUG(ans);
    cout << k << ' ' << all - ans;
}