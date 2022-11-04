#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN=6005;
vector<int>e[MAXN];
struct BIT
{
    int c[MAXN],n;
    stack<pair<int*,int> >stk;
    void init(int _n)
    {
        n=_n;
        memset(c,0,sizeof(c));
        while(!stk.empty())stk.pop();
    }
    void rollBack(int top)
    {
        while((int)stk.size()>top)
        {
            *stk.top().first=stk.top().second;
            stk.pop();
        }
    }
    void update(int p,int v)
    {
        for(int i=p;i<=n;i+=i&-i)
        {
            stk.push(make_pair(&c[i],c[i]));
            c[i]=max(c[i],v);
        }
    }
    int query(int p)
    {
        int res=0;
        for(int i=p;i>0;i-=i&-i)res=max(res,c[i]);
        return res;
    }
}bit;
int r[MAXN],rr[MAXN],dp[MAXN];
void dfs(int u,int fa)
{
    int top=(int)bit.stk.size();
    dp[u]=bit.query(r[u]-1)+1;
    bit.update(r[u],dp[u]);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        dfs(v,u);
    }
    bit.rollBack(top);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&r[i]);
    memcpy(rr,r,sizeof(r));
    sort(rr+1,rr+n+1);
    int cnt=unique(rr+1,rr+n+1)-(rr+1);
    for(int i=1;i<=n;i++)
        r[i]=lower_bound(rr+1,rr+cnt+1,r[i])-rr;
    bit.init(cnt);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        memset(dp,0,sizeof(dp));
        dfs(i,0);
        for(int j=1;j<=n;j++)
            res=max(res,dp[j]);
    }
    return 0*printf("%d\n",res);
}