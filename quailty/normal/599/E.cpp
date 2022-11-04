#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=13;
const int MAXQ=100;
int n,m,q;
int u[MAXN],v[MAXN];
int a[MAXQ],b[MAXQ],c[MAXQ];
ll dp[MAXN][1<<MAXN];
void dfs(int rt,int mask)
{
    if(dp[rt][mask]>=0)return;
    if(__builtin_popcount(mask)==1)
    {
        dp[rt][mask]=1;
        return;
    }
    dp[rt][mask]=0;
    int sup=mask^(1<<rt),sub=sup;
    do
    {
        if(sub&sup&-sup)
        {
            dfs(rt,mask^sub);
            for(int i=0;i<n;i++)
            {
                if(~sub&(1<<i))continue;
                bool isok=1;
                for(int j=0;j<m;j++)
                {
                    if(mask&(1<<u[j]) && mask&(1<<v[j])
                    && !(sub&(1<<u[j]) && sub&(1<<v[j]))
                    && !((mask^sub)&(1<<u[j]) && (mask^sub)&(1<<v[j]))
                    && !(rt==u[j] && i==v[j]) && !(rt==v[j] && i==u[j]))
                        isok=0;
                }
                for(int j=0;j<q;j++)
                {
                    if(mask&(1<<a[j]) && mask&(1<<b[j]) && mask&(1<<c[j])
                    && !(sub&(1<<a[j]) && sub&(1<<b[j]) && sub&(1<<c[j]))
                    && !((mask^sub)&(1<<a[j]) && (mask^sub)&(1<<b[j]) && (mask^sub)&(1<<c[j]))
                    && !(c[j]==rt && ((sub&(1<<a[j]) && (mask^sub)&(1<<b[j])) || ((sub&(1<<b[j]) && (mask^sub)&(1<<a[j]))))))
                        isok=0;
                }
                if(!isok)continue;
                dfs(i,sub);
                dp[rt][mask]+=dp[rt][mask^sub]*dp[i][sub];
            }
        }
        sub=(sub-1)&sup;
    }
    while(sub!=sup);
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        u[i]--,v[i]--;
    }
    for(int i=0;i<q;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        a[i]--,b[i]--,c[i]--;
    }
    memset(dp,-1,sizeof(dp));
    dfs(0,(1<<n)-1);
    return 0*printf("%I64d",dp[0][(1<<n)-1]);
}