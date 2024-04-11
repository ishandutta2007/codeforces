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

long long n, add, mul, dp[20000007];

long long solve(long long x)
{
    if (dp[x] != -1) return dp[x];
    if (x % 2 == 0)
    {
        if (mul < add * (x / 2))
        {
            dp[x] = solve(x / 2) + mul;
            return dp[x];
        }
        else
        {
            dp[x] = x * add;
            return dp[x];
        }
    }
    else
    {
        dp[x] = add + min(solve(x + 1), solve(x - 1));
        return dp[x];
    }
}


int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> add >> mul;
    reset(dp, -1);
    dp[0] = 0;
    dp[1] = add;
    cout << solve(n) << endl;
    //FOR (i, 1, 10) cout << i << ' ' << dp[i] << endl;
}