#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
vector<int>e[MAXN];
ll a[MAXN],mx[MAXN],cnt[MAXN];
ll gcd(ll a,ll b)
{
    return b ? gcd(b,a%b) : a;
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}
void dfs(int u,int fa)
{
    int nxt=0;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        dfs(v,u);
        if(!nxt)mx[u]=mx[v],cnt[u]=cnt[v];
        else
        {
            if(cnt[u]<5e13)cnt[u]=lcm(cnt[u],cnt[v]);
            mx[u]=min(mx[u],mx[v])/cnt[u]*cnt[u];
        }
        nxt++;
    }
    if(!nxt)mx[u]=a[u],cnt[u]=1;
    else
    {
        mx[u]*=nxt;
        if(cnt[u]<5e13)cnt[u]*=nxt;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    ll res=0;
    for(int i=1;i<=n;i++)
        res+=a[i];
    res-=mx[1];
    return 0*printf("%lld",res);
}