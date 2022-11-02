#include<bits/stdc++.h>
#define sz 100010
#define mod (int)(1e9+7)
using namespace std;
typedef long long ll;
struct FastIO
{
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
void file()
{
    #ifndef ONLINE_JUDGE
    freopen("a.txt","r",stdin);
    #endif
}
unsigned int log2(int x){unsigned int ret;__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));return ret;}
inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int n,m;
struct hh{int t;ll w;int nxt;}edge[sz*30];
int head[sz<<5],ecnt;
void make_edge(int f,int t,ll w){edge[++ecnt]=(hh){t,w,head[f]};head[f]=ecnt;}
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
int In[sz<<2],Out[sz<<2],cnt;
void build(int k,int l,int r)
{
	if (l==r) return (void)(In[k]=Out[k]=l);
	In[k]=++cnt;Out[k]=++cnt;
	int mid=(l+r)>>1;
	build(lson);build(rson);
	make_edge(In[k],In[ls],0);make_edge(In[k],In[rs],0);
	make_edge(Out[ls],Out[k],0);make_edge(Out[rs],Out[k],0);
}
void updateIn(int k,int l,int r,int L,int R,int x,ll w)
{
	if (L<=l&&r<=R) return make_edge(x,In[k],w);
	int mid=(l+r)>>1;
	if (L<=mid) updateIn(lson,L,R,x,w);
	if (R>mid) updateIn(rson,L,R,x,w);
}
void updateOut(int k,int l,int r,int L,int R,int x,ll w)
{
	if (L<=l&&r<=R) return make_edge(Out[k],x,w);
	int mid=(l+r)>>1;
	if (L<=mid) updateOut(lson,L,R,x,w);
	if (R>mid) updateOut(rson,L,R,x,w);
}
ll dis[sz<<5];
struct hhh{int x;ll d;};
struct cmp{const bool operator () (const hhh &x,const hhh &y){return x.d>y.d;}};
void dijkstra(int S)
{
    memset(dis,0x3f,sizeof(dis));
    dis[S]=0;
    priority_queue<hhh,vector<hhh>,cmp>q;
    q.push((hhh){S,0});
    while (!q.empty())
    {
        hhh x=q.top();q.pop();
        if (dis[x.x]!=x.d) continue;
        #define o edge[i].t
        for (int i=head[x.x];i;i=edge[i].nxt) 
            if (dis[o]>dis[x.x]+edge[i].w) 
                {dis[o]=dis[x.x]+edge[i].w;q.push((hhh){o,dis[o]});}
    }
}
int main()
{
	file();
	int i,k,x,y,z;
	ll w;
	read>>n>>m>>k;
	cnt=n;build(1,1,n);
	while (m--)
	{
		read>>x;
		if (x==1) read>>x>>y>>w,make_edge(x,y,w);
		else if (x==2) read>>x>>y>>z>>w,updateIn(1,1,n,y,z,x,w);
		else read>>x>>y>>z>>w,updateOut(1,1,n,y,z,x,w);
	}
	dijkstra(k);
	for (i=1;i<=n;i++) printf("%I64d ",dis[i]>1e16?-1:dis[i]);
}