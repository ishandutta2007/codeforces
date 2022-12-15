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

long long n, lis[200005], pre[200005], dp[200005], ans;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    FOR (i, 1, n) {
        cin >> lis[i];
        pre[i] = pre[i - 1] + lis[i];
    }
    dp[n] = pre[n];
    ans = dp[n];
    FORD (i, n - 1, 2)
    {
        dp[i] = pre[i] - ans;
        ans = max(dp[i], ans);
        //cout << i << ' ' << dp[i] << endl;
    }
    cout << ans;
}