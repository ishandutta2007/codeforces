#include<bits/stdc++.h>
#define sz 1000020
using namespace std;
void file(){
    #ifndef ONLINE_JUDGE
    freopen("a.txt","r",stdin);
    #endif
}
inline int read(){int x=0,f=1,ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();} while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} return x*f;}
int n;
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
int size[sz],dep[sz],fa[sz],son[sz];
void dfs1(int x,int fa)
{
    size[x]=1;dep[x]=dep[fa]+1;
    go(x) if (v!=fa)
    {
        dfs1(v,x);
        size[x]+=size[v];
        if (size[v]>size[son[x]]) son[x]=v;
    }
}
int S;
int sum[sz],mx;
void add(int x,int t)
{
    sum[x]+=t;
    if (!mx||sum[x]>sum[mx]||(sum[x]==sum[mx]&&x<mx)) mx=x;
}
void add(int x,int fa,int t)
{
    add(dep[x],t);
    go(x) if (v!=fa&&v!=S) add(v,x,t);
}
int ans[sz];
void dfs2(int x,int fa,bool keep)
{
    go(x) if (v!=fa&&v!=son[x]) dfs2(v,x,0);
    if (son[x]) dfs2(son[x],x,1);
    S=son[x];
    add(x,fa,1);
    ans[x]=mx-dep[x];
    S=0;
    if (!keep) add(x,fa,-1),mx=0;
}
int main()
{
    file();
    int i,x,y;
    n=read();
    for (i=1;i<n;i++) make_edge(read(),read());
    dfs1(1,0);dfs2(1,0,1);
    for (i=1;i<=n;i++) printf("%d\n",ans[i]);
}