#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int INF=1000000007;
int n,cnt,l[305],c[305];
int m[305],dp[305][(1<<9)+5];
bool vis[305][(1<<9)+5];
int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}
int dfs(int cur,int mask)
{
    if(cur==n+1)
    {
        if(mask==(1<<cnt)-1)return 0;
        else return INF;
    }
    if(vis[cur][mask])
    {
        return dp[cur][mask];
    }
    vis[cur][mask]=1;
    dp[cur][mask]=min(dfs(cur+1,mask),dfs(cur+1,mask|m[cur])+c[cur]);
    return dp[cur][mask];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&l[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
    int res=l[1];
    for(int i=2;i<=n;i++)
    {
        res=gcd(res,l[i]);
    }
    if(res==1)
    {
        int ans=INF;
        for(int i=1;i<=n;i++)
        {
            vector<int>f;
            int t=l[i];
            for(int j=2;j<=(int)sqrt(t);j++)
            {
                if(t%j==0)
                {
                    f.push_back(j);
                    while(t%j==0)t/=j;
                }
            }
            if(t!=1)f.push_back(t);
            cnt=f.size();
            for(int j=1;j<=n;j++)
            {
                m[j]=0;
                for(int k=0;k<cnt;k++)
                {
                    if(l[j]%f[k])
                    {
                        m[j]|=(1<<k);
                    }
                }
            }
            memset(vis,0,sizeof(vis));
            ans=min(ans,dfs(1,0)+c[i]);
        }
        printf("%d\n",ans);
    }
    else printf("-1\n");
    return 0;
}