#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll s[25],dp[25][1<<7][2],p[1<<7],q[1<<7];
int main()
{
    ll n,m;
    scanf("%I64d%I64d",&n,&m);
    n--,m--;
    if(n==0)s[0]=1,s[1]=0;
    while(n)
    {
        s[++s[0]]=n%7;
        n/=7;
    }
    reverse(s+1,s+s[0]+1);
    dp[0][0][1]=1;
    for(int i=1;i<=s[0];i++)
        for(int j=0;j<7;j++)
            for(int k=0;k<(1<<7);k++)
            {
                if(k&(1<<j))continue;
                dp[i][k|(1<<j)][0]+=dp[i-1][k][0];
                if(j<s[i])dp[i][k|(1<<j)][0]+=dp[i-1][k][1];
                if(j==s[i])dp[i][k|(1<<j)][1]+=dp[i-1][k][1];
            }
    for(int i=0;i<(1<<7);i++)
    {
        p[i]+=dp[s[0]][i][0];
        p[i]+=dp[s[0]][i][1];
    }
    memset(dp,0,sizeof(dp));
    s[0]=0;
    if(m==0)s[0]=1,s[1]=0;
    while(m)
    {
        s[++s[0]]=m%7;
        m/=7;
    }
    reverse(s+1,s+s[0]+1);
    dp[0][0][1]=1;
    for(int i=1;i<=s[0];i++)
        for(int j=0;j<7;j++)
            for(int k=0;k<(1<<7);k++)
            {
                if(k&(1<<j))continue;
                dp[i][k|(1<<j)][0]+=dp[i-1][k][0];
                if(j<s[i])dp[i][k|(1<<j)][0]+=dp[i-1][k][1];
                if(j==s[i])dp[i][k|(1<<j)][1]+=dp[i-1][k][1];
            }
    for(int i=0;i<(1<<7);i++)
    {
        q[i]+=dp[s[0]][i][0];
        q[i]+=dp[s[0]][i][1];
    }
    ll res=0;
    for(int i=0;i<(1<<7);i++)
        for(int j=0;j<(1<<7);j++)
            if((i&j)==0)res+=p[i]*q[j];
    return 0*printf("%I64d",res);
}