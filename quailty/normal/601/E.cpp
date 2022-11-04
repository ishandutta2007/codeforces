#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=35005;
const int MAXQ=30005;
const int MAXK=1005;
const int p=1e7+19;
const int q=1e9+7;
int v[MAXN],w[MAXN],l[MAXN],r[MAXN],h[MAXQ];
vector<int>s[MAXQ<<1];
int getId(int l,int r)
{
    return (l+r)|(l<r);
}
void add(int ql,int qr,int id,int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(ql==l && qr==r)
    {
        s[n].push_back(id);
        return;
    }
    if(qr<=m)add(ql,qr,id,l,m);
    else if(ql>m)add(ql,qr,id,m+1,r);
    else
    {
        add(ql,m,id,l,m);
        add(m+1,qr,id,m+1,r);
    }
}
int dp[20][MAXK];
void dfs(int l,int r,int dep,int &k)
{
    int n=getId(l,r),m=(l+r)/2;
    for(int i=1;i<=k;i++)
        dp[dep][i]=dp[dep-1][i];
    for(int i=0;i<(int)s[n].size();i++)
        for(int j=k;j>=w[s[n][i]];j--)
            dp[dep][j]=max(dp[dep][j],dp[dep][j-w[s[n][i]]]+v[s[n][i]]);
    if(l==r)
    {
        if(h[l])
        {
            int res=0,now=1;
            for(int i=1;i<=k;i++)
            {
                res=(res+1LL*now*dp[dep][i])%q;
                now=1LL*p*now%q;
            }
            printf("%d\n",res);
        }
    }
    else
    {
        dfs(l,m,dep+1,k);
        dfs(m+1,r,dep+1,k);
    }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&v[i],&w[i]);
    int q;
    scanf("%d",&q);
    for(int i=1;i<=n;i++)
        l[i]=1,r[i]=q;
    for(int i=1;i<=q;i++)
    {
        int ty;
        scanf("%d",&ty);
        if(ty==1)
        {
            n++;
            scanf("%d%d",&v[n],&w[n]);
            l[n]=i,r[n]=q;
        }
        else if(ty==2)
        {
            int x;
            scanf("%d",&x);
            r[x]=i;
        }
        else h[i]=1;
    }
    for(int i=1;i<=n;i++)
        add(l[i],r[i],i,1,q);
    dfs(1,q,1,k);
    return 0;
}