#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
typedef long long ll;
typedef std::pair<int,int> pii;
typedef unsigned un;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll t){if(t>a)return a=t,1;return 0;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
ll abs(ll x){return x>0?x:-x;}

#define MAXN 200011
std::vector<int>g[MAXN];
bool flag=0;
int size[MAXN],mson[MAXN],fa[MAXN], n;
void dfs1(int u)
{
    size[u]=1,mson[u]=0;
    for(auto v:g[u])
    {
        if(v==fa[u])continue;
        fa[v]=u;
        dfs1(v);
        size[u]+=size[v];
        if(size[v]>size[mson[u]])mson[u]=v;
    }
}
int dfs2(int u)
{
    if(n%2==0&&size[mson[u]]==n/2)flag=1;
    if(size[mson[u]]>=n/2)return dfs2(mson[u]);
    return u;
}
int main()
{
    int task=read();
    while(task--)
    {
        flag=0;
        n=read();
        for(int i=1;i<=n;++i)g[i].clear(),fa[i]=0;
        for(int i=1;i<n;++i)
        {
            int u=read(),v=read();g[u].push_back(v),g[v].push_back(u);
        }
        dfs1(1);
        int cen=dfs2(1);
        if(!flag)printf("%d %d\n%d %d\n",cen,g[cen].front(),cen,g[cen].front());
        else printf("%d %d\n%d %d\n",cen,mson[cen],mson[cen],fa[cen]);
    }
    return 0;
}