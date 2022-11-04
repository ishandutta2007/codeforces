#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll num[25],dp[25][2][2];
ll solve(int up)
{
    memset(dp,0,(num[0]+1)*sizeof(dp[0]));
    dp[0][0][1]=1;
    for(int i=1;i<=num[0];i++)
        for(int j=0;j<2;j++)
        {
            if(num[0]-i==up/4)for(int t=0;t<=up;t++)
            {
                if(~t>>(up%4)&1)continue;
                dp[i][j|(t==up)][0]+=dp[i-1][j][0];
                if(t<=num[i])dp[i][j|(t==up)][t==num[i]]+=dp[i-1][j][1];
            }
            else
            {
                dp[i][j][0]+=up*dp[i-1][j][0];
                dp[i][1][0]+=dp[i-1][j][0];
                if(up<=num[i])
                {
                    dp[i][j][0]+=up*dp[i-1][j][1];
                    dp[i][1][up==num[i]]+=dp[i-1][j][1];
                }
                else
                {
                    dp[i][j][0]+=num[i]*dp[i-1][j][1];
                    dp[i][j][1]+=dp[i-1][j][1];
                }
            }
        }
    return dp[num[0]][1][0]+dp[num[0]][1][1];
}
ll cal(ll x)
{
    if(x<=0)return 0;
    num[0]=0;
    while(x)
    {
        num[++num[0]]=x%16;
        x/=16;
    }
    while(num[0]<4)num[++num[0]]=0;
    reverse(num+1,num+num[0]+1);
    ll res=0;
    for(int i=1;i<16;i++)
        res+=solve(i);
    return res;
}
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        ll l,r;
        scanf("%llx%llx",&l,&r);
        printf("%lld\n",cal(r)-cal(l-1));
    }
    return 0;
}