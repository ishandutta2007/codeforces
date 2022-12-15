#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,a) FOR(i,0,a-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back

long long n, lis[1000006], dp[1000006], trend, lback;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    scanf("%lld", &n);
    FOR (i, 1, n) scanf("%lld", &lis[i]);
    FOR (i, 2, n)
    {
        if (trend * (lis[i] - lis[i - 1]) <= 0) lback = i - 1;
        trend = lis[i] - lis[i - 1];
        dp[i] = max(dp[i - 1], dp[lback] + abs(lis[i] - lis[lback + 1]));
        dp[i] = max(dp[i], dp[lback - 1] + abs(lis[i] - lis[lback]));
    }
    cout << dp[n];
}