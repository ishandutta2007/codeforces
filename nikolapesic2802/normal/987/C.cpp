#include <bits/stdc++.h>

using namespace std;
const int N=3002,oo=1000000009;
int n;
int s[N];
int c[N];
int dp[N][3][N];
int min_dp(int do_kog,int koliko,int pred)
{
    if(koliko==0)
    {
        dp[do_kog][koliko][pred]=0;
        return 0;
    }
    if(do_kog>n)
    {
        return oo;
    }
    if(dp[do_kog][koliko][pred]!=-2)
    {
        return dp[do_kog][koliko][pred];
    }
    int stanje1=oo,stanje2=oo;
    if(s[pred]<s[do_kog])
    {
        stanje1=c[do_kog]+min_dp(do_kog+1,koliko-1,do_kog);
    }
    stanje2=min_dp(do_kog+1,koliko,pred);
    dp[do_kog][koliko][pred]=min(stanje1,stanje2);
    return dp[do_kog][koliko][pred];
}
int main()
{
    scanf("%i",&n);
    for(int i=0;i<=n;i++)
    {
        for(int k=0;k<=3;k++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][k][j]=-2;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&s[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&c[i]);
    }
    int res=min_dp(1,3,0);
    if(res>=oo)
    {
        printf("-1\n");
        return 0;
    }
    printf("%i\n",res);
    return 0;
}