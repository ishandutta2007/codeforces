#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) FOR(i,0,a-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back

long long n, cnt[1<<20], ans, val, dp[21][1<<20];

long long expo(long long x, long long y)
{
    long long ret = 1;
    FORD (i, 30, 0)
    {
        ret *= ret;
        ret %= mod;
        if((1ll << i) & y)
        {
            ret *= x;
            ret %= mod;
        }
    }
    return ret;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    scanf("%lld", &n);
    FOR (i, 1, n)
    {
        scanf("%lld", &val);
        cnt[val]++;
    }
    FORD (i, (1 << 20) - 1, 0)
    {
        //BUG(i);
        dp[0][i] = cnt[i];
        FOR (j, 1, 20)
        {
            dp[j][i] = dp[j - 1][i];
            if ((i & (1 << (j - 1))) == 0) dp[j][i] += dp[j - 1][i | (1 << (j - 1))];
        }
        //if(cnt[i]) BUG(dp[20][i]);
        long long change = expo(2, dp[20][i]);
        if (__builtin_popcount(i) & 1) ans = (ans + mod - change) % mod;
        else ans = (ans + change) % mod;
    }
    cout << ans;
}