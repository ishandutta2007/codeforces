#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

long long n, k, lis[2222], dp[2222], high, low;

long long solve(long long x)
{
    dp[0] = 0;
    long long ret = n - 1;
    FOR (i, 1, n - 1)
    {
        dp[i] = i;
        REP (j, i) if (abs(lis[i] - lis[j]) <= x * (i - j)) dp[i] = min(dp[i], dp[j] + i - j - 1);
        //BUG(dp[i]);
        ret = min(ret, dp[i] + n - 1 - i);
    }
    return ret;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    REP (i, n) cin >> lis[i];
    //cout << solve(0); return 0;
    high = 2000000000ll;
    low = 0;
    while (high > low)
    {
        long long chs = (high + low) / 2;
        if (solve(chs) <= k) high = chs;
        else low = chs + 1;
    }
    cout << high;
}