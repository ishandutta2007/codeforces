#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=20;
const int INF=0x3f3f3f3f;
char s[MAXN][MAXN+5];
int a[MAXN][MAXN],v[MAXN][MAXN],c[MAXN][MAXN],dp[1<<MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int mx=0;
            for(int k=0;k<n;k++)
                if(s[k][j]==s[i][j])
                {
                    v[i][j]|=(1<<k);
                    c[i][j]+=a[k][j];
                    mx=max(mx,a[k][j]);
                }
            c[i][j]-=mx;
        }
    memset(dp,INF,sizeof(dp));
    dp[(1<<n)-1]=0;
    for(int mask=(1<<n)-1;mask>0;mask--)
        for(int i=0;i<n;i++)
        {
            if(~mask&(1<<i))continue;
            for(int j=0;j<m;j++)
            {
                dp[mask^(1<<i)]=min(dp[mask^(1<<i)],dp[mask]+a[i][j]);
                dp[mask&(mask^v[i][j])]=min(dp[mask&(mask^v[i][j])],dp[mask]+c[i][j]);
            }
            break;
        }
    return 0*printf("%d",dp[0]);
}