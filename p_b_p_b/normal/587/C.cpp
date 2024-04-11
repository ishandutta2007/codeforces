#include<bits/stdc++.h>
#define sz 100020
#define mod 998244353
using namespace std;
typedef long long ll;
struct FastIO{
    inline FastIO& operator>>(int& x)
    {
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(ll& x)
    {
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(double& x)
    {
        x=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        if(ch=='.')
        {
        	ch=getchar();
            while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1,ch=getchar();
        }
        return x=(f?-x:x),*this;
    }
}read;
void file(){
    #ifndef ONLINE_JUDGE
    freopen("a.txt","r",stdin);
    #endif
}
unsigned int log2(int x){unsigned int ret;__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));return ret;}
inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int n,m;
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
    edge[++ecnt]=(hh){t,head[f]};
    head[f]=ecnt;
    edge[++ecnt]=(hh){f,head[t]};
    head[t]=ecnt;
}
#define go(x) for (int i=head[x];i;i=edge[i].nxt)
#define v edge[i].t
#define vec vector<int>
vec up[sz][20];
int fa[sz][20];
vec merge(vec x,vec y)
{
    vec ret;
    unsigned int p=0,q=0;
    for (int i=1;i<=10;i++)
    {
        if (p==x.size()&&q==y.size()) break;
        int a,b;a=b=2333333;
        if (p<x.size()) a=x[p];
        if (q<y.size()) b=y[q];
        if (a<b) p++,ret.push_back(a);
        else q++,ret.push_back(b);
    }
    return ret;
}
void upd(int x,int f)
{
    fa[x][0]=f;
    for (int i=1;i<18;i++) fa[x][i]=fa[fa[x][i-1]][i-1],up[x][i]=merge(up[x][i-1],up[fa[x][i-1]][i-1]);
}
int dep[sz];
void dfs(int x,int f)
{
    upd(x,f);dep[x]=dep[f]+1;
    go(x) if (v!=f) dfs(v,x);
}
vec query(int x,int y)
{
    vec ret;
    if (x==y) return up[x][0];
    if (dep[x]<dep[y]) swap(x,y);
    for (int i=18;i>=0;i--) 
        if (fa[x][i]&&dep[fa[x][i]]>=dep[y])
            { ret=merge(ret,up[x][i]); x=fa[x][i]; }
    if (x==y) return merge(ret,up[x][0]);
    for (int i=18;i>=0;i--)
        if (fa[x][i]!=fa[y][i])
            { ret=merge(ret,merge(up[x][i],up[y][i])); x=fa[x][i]; y=fa[y][i]; }
    ret=merge(ret,up[x][0]);
    if (x!=y) ret=merge(ret,up[y][1]);
    return ret;
}
int main()
{
    file();
    int i,x,y,z,Q;
    read>>n>>m>>Q;
    for (i=1;i<n;i++) read>>x>>y,make_edge(x,y);
    for (i=1;i<=m;i++) read>>x,up[x][0].push_back(i);
    dfs(1,0);
    while (Q--)
    {
        read>>x>>y>>z;
        vec ans=query(x,y);z=min(z,(int)ans.size());
        printf("%d ",z);
        for (i=0;i<z;i++) printf("%d ",ans[i]);
        puts("");
    }
}