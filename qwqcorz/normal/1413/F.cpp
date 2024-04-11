#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const int inf=N*10;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<pair<int,int>>e[N];
int u[N],v[N],w[N],deep[N],st[N],ed[N],cntdfn=0,a[N],b[N*2];
void dfs(int now,int father)
{
	b[st[now]=ed[now]=++cntdfn]=now;
	for (auto [to,w]:e[now])
	{
		if (to==father) continue;
		deep[to]=deep[now]+1;
		a[to]=a[now]^w;
		dfs(to,now);
		b[ed[now]=++cntdfn]=now;
	}
}
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	struct node
	{
		int a[2],b,l[2],r[2],ans,tag;
		node(){a[0]=a[1]=b=l[0]=l[1]=r[0]=r[1]=ans=-inf,tag=0;}
		node(int x,int d)
		{
			*this=node();
			a[x]=d,b=-d*2,l[x]=r[x]=-d,ans=0;
		}
		void update()
		{
			tag^=1;
			swap(a[0],a[1]);
			swap(l[0],l[1]);
			swap(r[0],r[1]);
		}
		friend node operator +(node a,node b)
		{
			node ret;
			ret.tag=0;
			ret.b=max(a.b,b.b);
			ret.ans=max(a.ans,b.ans);
			for (int i=0;i<=1;i++)
			{
				ret.a[i]=max(a.a[i],b.a[i]);
				ret.l[i]=max({a.l[i],b.l[i],a.a[i]+b.b});
				ret.r[i]=max({a.r[i],b.r[i],a.b+b.a[i]});
				ret.ans=max({ret.ans,a.l[i]+b.a[i],a.a[i]+b.r[i]});
			}
			return ret;
		}
	}t[N*4];
	void push_down(int w)
	{
		if (!t[w].tag) return;
		t[ls].update();
		t[rs].update();
		t[w].tag=0;
	}
	void change(int w,int l,int r,int ql,int qr)
	{
		if (ql<=l&&r<=qr) return t[w].update();
		push_down(w);
		if (ql<=mid) change(ls,l,mid,ql,qr);
		if (qr>mid) change(rs,mid+1,r,ql,qr);
		t[w]=t[ls]+t[rs];
	}
	void build(int w,int l,int r)
	{
		if (l==r) return t[w]=node(a[b[l]],deep[b[l]]),void();
		build(ls,l,mid);
		build(rs,mid+1,r);
		t[w]=t[ls]+t[rs];
	}
	#undef mid
	#undef rs
	#undef ls
}t;
signed main()
{
	int n=read();
	for (int i=1;i<n;i++)
	{
		u[i]=read(),v[i]=read(),w[i]=read();
		e[u[i]].push_back({v[i],w[i]});
		e[v[i]].push_back({u[i],w[i]});
	}
	dfs(1,0);
	for (int i=1;i<n;i++) if (deep[u[i]]>deep[v[i]]) swap(u[i],v[i]);
	t.build(1,1,cntdfn);
	int Q=read();
	while (Q--)
	{
		int i=read();
		t.change(1,1,cntdfn,st[v[i]],ed[v[i]]);
		print(t.t[1].ans);
	}
	
	return 0;
}