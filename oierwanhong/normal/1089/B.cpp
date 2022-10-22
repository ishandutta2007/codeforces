#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef unsigned un;
//typedef std::string str;
typedef std::pair<ll,ll> pll;
typedef std::pair<int,int> pii;
typedef std::pair<double,double> pd;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
const ll INF=1ll<<58;
#define MAXN 511
struct DSU
{
    int fa[MAXN];
    void build(int n){for(int i=1;i<=n;++i)fa[i]=i;}
    int find(int x)
    {
        if(fa[x]==x)return x;
        return fa[x]=find(fa[x]);
    }
    bool is_root(int x){return find(x)==x;}
    void uni(int x,int y)
    {
        x=find(x),y=find(y);
        fa[x]=y;
    }
}s;
struct edge
{
    int v,nxt;
}e[200011];
int cnt=0,last[MAXN];
void adde(int u,int v){e[++cnt].v=v,e[cnt].nxt=last[u],last[u]=cnt;}
char str[MAXN];
int match[MAXN],pre[MAXN], f[MAXN],q[MAXN],ti[MAXN],cur=0;
int h,t;
int LCA(int x,int y)
{
    ++cur;
    x=s.find(x),y=s.find(y);
    while(ti[x]!=cur)
    {
        ti[x]=cur;
        x=s.find(pre[match[x]]);
        if(y)std::swap(x,y);
    }
    return x;
}
void flower(int x,int y,int rt)
{
    while(s.find(x)!=rt)
    {
        pre[x]=y,y=match[x];
        if(f[y]==2)f[y]=1,q[t++]=y;
        if(s.is_root(x))s.uni(x,rt);
        if(s.is_root(y))s.uni(y,rt);
        x=pre[y];
    }
}
bool bfs(int sou)
{
    s.build(500);
    memset(pre,0,sizeof pre),memset(f,0,sizeof f);
    h=t=0;
    q[t++]=sou,f[sou]=1;
    while(h<t)
    {
        int u=q[h++];
        for(int i=last[u];i;i=e[i].nxt)
        {
            int v=e[i].v;
            if(s.find(u)==s.find(v)||f[v]==2)continue;
            if(!f[v])
            {
                f[v]=2,pre[v]=u;
                if(!match[v])
                {
                    while(v)u=match[pre[v]],match[v]=pre[v],match[pre[v]]=v,v=u;
                    return 1;
                }
                f[match[v]]=1,q[t++]=match[v];
            }
            else
            {
                int lca=LCA(u,v);
                flower(u,v,lca),flower(v,u,lca);
            }
        }
    }
    return 0;
}
int main()
{
    int task=read();
    while(task--)
    {
        memset(last,0,sizeof last),memset(match,0,sizeof match),memset(ti,0,sizeof ti);
        cnt=0;
        int n=read(),m=read();
        for(int i=1;i<=n;++i)
        {
            adde(i,n+i),adde(n+i,i);
            scanf("%s",str+1);
            for(int j=1;j<=m;++j)
                if(str[j]=='1')adde(i,n+n+j),adde(n+n+j,i),adde(n+i,n+n+j),adde(n+n+j,n+i);
        }
        int ans=0;
        for(int i=1;i<=n+n+m;++i)
            if(!match[i]) ans+=bfs(i);
        printf("%d\n",ans-n);
    }
}