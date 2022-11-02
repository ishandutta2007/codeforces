#include<bits/stdc++.h>
#define sz 500020
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
int size[sz],dep[sz],son[sz],top[sz],dfn[sz],low[sz],fa[sz],T;
void dfs1(int x,int fa)
{
	dep[x]=dep[::fa[x]=fa]+1;
	size[x]=1;
	go(x) if (v!=fa)
	{
		dfs1(v,x);
		size[x]+=size[v];
		if (size[v]>size[son[x]]) son[x]=v;
	}
}
void dfs2(int x,int fa,int tp)
{
	dfn[x]=++T;top[x]=tp;
	if (son[x]) dfs2(son[x],x,tp);
	go(x) if (v!=fa&&v!=son[x]) dfs2(v,x,v);
	low[x]=T;
}
int tr[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void pushdown(int k){if (tr[k]!=-1) tr[ls]=tr[rs]=tr[k],tr[k]=-1;}
void modify(int k,int l,int r,int x,int y,int t)
{
	if (x<=l&&r<=y) return (void)(tr[k]=t);
	pushdown(k);
	int mid=(l+r)>>1;
	if (x<=mid) modify(lson,x,y,t);
	if (y>mid) modify(rson,x,y,t);
}
int query(int k,int l,int r,int x)
{
	if (l==r) return tr[k];
	pushdown(k);
	int mid=(l+r)>>1;
	return x<=mid?query(lson,x):query(rson,x);
}
void modify(int x)
{
	while (x)
	{
		modify(1,1,n,dfn[top[x]],dfn[x],0);
		x=fa[top[x]];
	}
}
int main()
{
	file();
	int i,j,k,x,y,z,Q;
	read>>n;
	for (i=1;i<n;i++) read>>x>>y,make_edge(x,y);
	dfs1(1,0);dfs2(1,0,1);
	read>>Q;
	while (Q--)
	{
		read>>x>>y;
		if (x==1) modify(1,1,n,dfn[y],low[y],1);
		else if (x==2) modify(y);
		else puts(query(1,1,n,dfn[y])?"1":"0");
	}
}