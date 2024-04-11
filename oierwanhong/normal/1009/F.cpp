//Wan Hong 3.1
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<map>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::vector<int> Poly;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
bool umax(int& a,int b){if(b>a)return a=b,1;return 0;}
bool umin(int& a,int b){if(b<a)return a=b,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/
#define MAXN 1000011
struct edge{int v,nxt;}e[MAXN<<1|1];
int cnt=0,last[MAXN];
void adde(int u,int v){e[++cnt].v=v,e[cnt].nxt=last[u],last[u]=cnt;}

int fa[MAXN], dfn[MAXN], maxl[MAXN],ls[MAXN], f[MAXN],pos[MAXN],cur=0;
void dfs1(int u)
{
    maxl[u]=0;
    for(int i=last[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa[u])continue;
        fa[v]=u,dfs1(v);
        if(umax(maxl[u],maxl[v]+1))ls[u]=v;
    }
}
void dfs2(int u)
{
    dfn[u]=++cur;
    // printf("u=%d,dfn=%d,ls=%d\n",u,dfn[u],ls[u]);
    if(ls[u])dfs2(ls[u]);
    for(int i=last[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v!=fa[u]&&v!=ls[u])dfs2(v);
    }
}
void dfs3(int u)
{
    f[dfn[u]]=1,pos[u]=0;
    if(ls[u])
    {
        dfs3(ls[u]);
        if(f[dfn[ls[u]]+pos[ls[u]]]>1)pos[u]=pos[ls[u]]+1;
    }
    for(int i=last[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v!=fa[u]&&v!=ls[u])
        {
            dfs3(v);
            for(int x=0;x<=maxl[v];++x)
            {
                f[dfn[u]+x+1]+=f[dfn[v]+x];
                // printf("u=%d,f[%d]=%d,ori=%d\n",u,dfn[u]+x+1,f[dfn[u]+x+1],f[dfn[u]+pos[u]]);
                int t=f[dfn[u]+x+1];
                if((t>f[dfn[u]+pos[u]])||(t==f[dfn[u]+pos[u]]&&x+1<pos[u]))pos[u]=x+1;
            }
        }
    }
}
int main()
{
    int n=read();
    for(int i=1;i<n;++i){int u=read(),v=read();adde(u,v),adde(v,u);}
    dfs1(1),dfs2(1),dfs3(1);
    for(int i=1;i<=n;++i)printf("%d\n",pos[i]);
    return 0;
}