#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=55;
const int INF=0x78787878;
int t[MAXN],dp[MAXN*MAXN];
inline void check_min(int &x,int y)
{
    x=(x<y ? x : y);
}
int main()
{
    int n,k,M;
    scanf("%d%d%d",&n,&k,&M);
    for(int i=1;i<=k;i++)
        scanf("%d",&t[i]);
    sort(t+1,t+k+1);
    for(int i=1;i<=k;i++)
        t[i]+=t[i-1];
    memset(dp,INF,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++)
        for(int j=n*(k+1);j>=0;j--)
            for(int s=0;s<=k;s++)
                check_min(dp[j+s+(s==k)],dp[j]+t[s]);
    int res=0;
    for(int j=0;j<=n*(k+1);j++)
        if(dp[j]<=M)res=j;
    return 0*printf("%d\n",res);
}