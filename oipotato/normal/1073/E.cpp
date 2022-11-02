#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
const int MOD=998244353;
int f[20][1<<10][2][2],g[20][1<<10][2][2],a[20];
int cal(long long x,int K)
{
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    int n=0;
    for(;x;x/=10)a[++n]=x%10;
    reverse(a+1,a+n+1);
    g[0][0][0][0]=1;
    for(int i=0;i<n;i++)
    for(int j=0;j<(1<<10);j++)
    for(int msk=0;msk<2;msk++)
    {
        if(g[i][j][msk][0])
        {
            for(int k=0;k<=a[i+1];k++)
            {
                g[i+1][!msk&&!k?j:(j|(1<<k))][msk|(k>0)][k<a[i+1]]=(g[i+1][!msk&&!k?j:(j|(1<<k))][msk|(k>0)][k<a[i+1]]+g[i][j][msk][0])%MOD;
                f[i+1][!msk&&!k?j:(j|(1<<k))][msk|(k>0)][k<a[i+1]]=(f[i+1][!msk&&!k?j:(j|(1<<k))][msk|(k>0)][k<a[i+1]]+10ll*f[i][j][msk][0]+1ll*g[i][j][msk][0]*k)%MOD;
            }
        }
        if(g[i][j][msk][1])
        {
            for(int k=0;k<=9;k++)
            {
                g[i+1][!msk&&!k?j:(j|(1<<k))][msk|(k>0)][1]=(g[i+1][!msk&&!k?j:(j|(1<<k))][msk|(k>0)][1]+g[i][j][msk][1])%MOD;
                f[i+1][!msk&&!k?j:(j|(1<<k))][msk|(k>0)][1]=(f[i+1][!msk&&!k?j:(j|(1<<k))][msk|(k>0)][1]+10ll*f[i][j][msk][1]+1ll*g[i][j][msk][1]*k)%MOD;
            }
        }
        //if(__builtin_popcount(i)<=K)printf("%d %d %d %d %d %d\n",i,j,g[i][j][0],f[i][j][0],g[i][j][1],f[i][j][1]);
    }
    int ans=0;
    for(int i=0;i<(1<<10);i++)if(__builtin_popcount(i)<=K)ans=(0ll+ans+f[n][i][1][0]+f[n][i][1][1])%MOD;
    return ans;
}
int main()
{
    long long l,r;
    int k;
    scanf("%lld%lld%d",&l,&r,&k);
    printf("%d\n",(cal(r,k)-cal(l-1,k)+MOD)%MOD);
	return 0;
}