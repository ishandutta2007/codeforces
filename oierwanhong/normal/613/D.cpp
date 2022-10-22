#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
typedef long long ll;
typedef unsigned un;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(int& a,int t){if(t>a)a=t;}
bool umin(int& a,int t){if(t<=a)return a=t,1;return 0;}
ll abs(ll x){return x>0?x:-x;}

#define MAXN 200011
struct edge{int v,nxt;}e[MAXN<<1|1];
int cnt=0,last[MAXN];
void adde(int u,int v){e[++cnt].v=v,e[cnt].nxt=last[u],last[u]=cnt;}
int fa[MAXN],dep[MAXN],size[MAXN],mson[MAXN],top[MAXN],dfn[MAXN],cur=0;
void dfs1(int u)
{
    size[u]=1;
    for(int i=last[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa[u])continue;
        fa[v]=u,dep[v]=dep[u]+1;
        dfs1(v);
        size[u]+=size[v];
        if(size[v]>size[mson[u]])mson[u]=v;
    }
}
void dfs2(int u,int now_top)
{
    top[u]=now_top,dfn[u]=++cur;
    if(mson[u])dfs2(mson[u],now_top);
    for(int i=last[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v!=mson[u]&&v!=fa[u])dfs2(v,v);
    }
}
int LCA(int u,int v)
{
    while(top[u]!=top[v])
        if(dep[top[u]]>=dep[top[v]])u=fa[top[u]];
        else v=fa[top[v]];
    return dep[u]>dep[v]?v:u;
}

int s[MAXN],a[MAXN],g[MAXN],sp[MAXN];
bool cmp(int x,int y){return dfn[x]<dfn[y];}
ll ans,fail=0;
void ctrb(int u,int p)
{
    if(g[u]>1)++ans,g[u]=0;
    if(sp[p]&&sp[u]&&dep[u]==dep[p]+1)fail=1;
    if(sp[p])ans+=g[u];
    else g[p]+=g[u];
}
void clear(int u){g[u]=sp[u]=0;}
int main()
{
    int n=read();
    for(int i=1;i<n;++i)
    {
        int u=read(),v=read();adde(u,v),adde(v,u);
    }
    dfs1(1),dfs2(1,1);
    int query=read();
    while(query--)
    {
        int m=read();
        for(int i=1;i<=m;++i)a[i]=read(),sp[a[i]]=1,g[a[i]]=1;
        std::sort(a+1,a+m+1,cmp);
        int top=0;
        fail=ans=0;
        for(int i=1;i<=m;++i)
        {
            int u=a[i];
            if(!top){s[++top]=u; continue;}
            int lca=LCA(s[top],u);
            if(s[top]==lca){s[++top]=u;continue;}
            while(top>1&&dfn[s[top-1]]>dfn[lca])ctrb(s[top],s[top-1]),clear(s[top--]);
            ctrb(s[top],lca),clear(s[top--]);
            if(s[top]!=lca)s[++top]=lca;
            s[++top]=u;
        }
        while(top>1)ctrb(s[top],s[top-1]),clear(s[top--]);
        if(g[s[1]]>1)++ans;
        clear(s[1]);
        printf("%lld\n",fail?-1ll:ans);
    }
    return 0;
}