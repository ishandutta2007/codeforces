#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const int MAXV=8;
const int INF=0x3f3f3f3f;
int a[MAXN],dp[1<<MAXV][MAXV];
vector<int>v[MAXV];
int getNxt(int d,int i,int k)
{
    if(k==0)return i;
    int t=upper_bound(v[d].begin(),v[d].end(),i)-v[d].begin()-1;
    return (t+k>=(int)v[d].size() ? INF : v[d][t+k]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]),a[i]--;
        v[a[i]].push_back(i);
    }
    int res=0;
    for(int _=0;_<=n/MAXV;_++)
    {
        memset(dp,INF,sizeof(dp));
        dp[0][0]=0;
        for(int i=0;i<(1<<MAXV);i++)
            for(int j=0;j<MAXV;j++)if(~i&(1<<j))
                for(int k=0;k<MAXV;k++)
                {
                    dp[i|(1<<j)][k]=min(dp[i|(1<<j)][k],getNxt(j,dp[i][k],_));
                    if(k+1<MAXV)dp[i|(1<<j)][k+1]=min(dp[i|(1<<j)][k+1],getNxt(j,dp[i][k],_+1));
                }
        for(int k=0;k<MAXV;k++)
            if(dp[(1<<MAXV)-1][k]<INF)res=max(res,_*MAXV+k);
    }
    return 0*printf("%d",res);
}