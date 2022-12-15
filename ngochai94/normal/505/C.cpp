#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define MAXN 30005

int n, lis[MAXN], dp[1000][MAXN], val, d;


int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    // ios::sync_with_stdio(0);
    cin >> n >> d;
    FOR (i, 1, n) {
        cin >> val;
        lis[val]++;
    }
    reset(dp, -1);
    dp[500][d] = lis[d];
    int ans = lis[d];
    FOR (i, d, 30000) REP (j, 999) if (~dp[j][i]) {
        // cout << i << ' ' << j << endl;
        ans = max(ans, dp[j][i]);
        if (i + j - 500 + d <= 30000) dp[j][i + j - 500 + d] = max(dp[j][i + j - 500 + d], dp[j][i] + lis[i + j - 500 + d]);
        // BUG(j);
        if (i + j - 500 + d + 1 <= 30000) dp[j + 1][i + j - 500 + d + 1] = max(dp[j + 1][i + j - 500 + d + 1], dp[j][i] + lis[i + j - 500 + d + 1]);
        // BUG(i);
        if (j - 500 + d > 1 && i + j - 500 + d - 1 <= 30000) dp[j - 1][i + j - 500 + d - 1] = max(dp[j - 1][i + j - 500 + d - 1], dp[j][i] + lis[i + j - 500 + d - 1]);
    }
    cout << ans;
}