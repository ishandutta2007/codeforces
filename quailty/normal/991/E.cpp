#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=35;
ll cnt[MAXN],C[MAXN][MAXN],dp[2][MAXN];
int main()
{
    ll n;
    scanf("%lld",&n);
    while(n)
    {
        cnt[n%10+1]++;
        n/=10;
    }
    reverse(cnt+1,cnt+11);
    for(int i=(C[0][0]=1);i<MAXN;i++)
        for(int j=(C[i][0]=1);j<MAXN;j++)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    int now=0,la=1;
    dp[0][0]=1;
    for(int i=1;i<=10;i++)
    {
        if(!cnt[i])continue;
        swap(now,la);
        memset(dp[now],0,sizeof(dp[now]));
        for(int j=0;j<MAXN;j++)
            for(int k=1;k<=cnt[i] && j+k<MAXN;k++)
                dp[now][j+k]+=dp[la][j]*C[j+k-(i==10)][k];
    }
    ll res=0;
    for(int i=1;i<MAXN;i++)
        res+=dp[now][i];
    return 0*printf("%lld\n",res);
}