// Author: Little09
// Problem: CF1464F My Beautiful Madness
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1464F
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+5;
int dfn[N],rk[N],top,siz[N],deth[N],fa[N][21];
namespace tree
{
	const int M=N*2;
	int t[M],h[N],nxt[M],cnt;
	inline void add(int x,int y)
	{
		t[++cnt]=y;
		nxt[cnt]=h[x];
		h[x]=cnt;
	}
	struct point
	{
		int id,x;
		bool operator < (const point &o) const
		{
			return x<o.x;
		}
	}g[M][21];
	int tot,w[N];
	void dfs(int x,int f)
	{
		dfn[x]=++top,rk[top]=x,siz[x]=1;
		deth[x]=deth[f]+1,fa[x][0]=f,w[x]=++tot,g[tot][0]={x,deth[x]};
		for (int i=1;i<=20;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
		for (int i=h[x];i;i=nxt[i])
		{
			if (t[i]==f) continue;
			dfs(t[i],x);
			siz[x]+=siz[t[i]];
			g[++tot][0]={x,deth[x]};
		}
	}
	void STwork()
	{
		int t=log(tot)/log(2);
		for (int i=1;i<=t;i++)
		{
			for (int j=1;j<=tot-(1<<i)+1;j++)
			{
				g[j][i]=min(g[j][i-1],g[j+(1<<(i-1))][i-1]);
			}
		}
	}
	inline int LCA(int x,int y)
	{
		x=w[x],y=w[y];
		if (x>y) swap(x,y);
		int t=log(y-x+1)/log(2);
		return min(g[x][t],g[y-(1<<t)+1][t]).id;
	}
	inline int dis(int x,int y)
	{
		return deth[x]+deth[y]-2*deth[LCA(x,y)];
	}
	inline int K_ancestor(int x,int k)
	{
		for (int i=0;i<=20;i++) if (k&(1<<i)) x=fa[x][i];
		if (x==0) return 1;
		return x;
	}
}
struct point
{
	int x,y,w;
};
namespace seg
{
	const int M=N*4;
	point s[M];
	point operator + (const point &a,const point &b)
	{
		if (a.w==-1) return b;
		if (b.w==-1) return a;
		point res=a;
		if (b.w>a.w) res=b;
		int v=tree::dis(a.x,b.x);
		if (v>res.w) res={a.x,b.x,v};
		v=tree::dis(a.x,b.y);
		if (v>res.w) res={a.x,b.y,v};
		v=tree::dis(a.y,b.y);
		if (v>res.w) res={a.y,b.y,v};
		v=tree::dis(a.y,b.x);
		if (v>res.w) res={a.y,b.x,v};
		return res;
	}
	void build(int u,int l,int r)
	{
		if (l==r)
		{
			s[u].x=rk[l],s[u].y=rk[l],s[u].w=-1;
			return;
		}
		int mid=(l+r)>>1;
		build(u*2,l,mid);
		build(u*2+1,mid+1,r);
		s[u]=s[u*2]+s[u*2+1];
	}
	void update(int u,int l,int r,int x)
	{
		if (l==r)
		{
			if (s[u].w==-1) s[u].w=0;
			else s[u].w=-1;
			return;
		}
		int mid=(l+r)>>1;
		if (x<=mid) update(u*2,l,mid,x);
		else update(u*2+1,mid+1,r,x);
		s[u]=s[u*2]+s[u*2+1];
	}
	point ask(int u,int L,int R,int l,int r)
	{
		if (l<=L&&R<=r) return s[u];
		point res={1,1,-1};
		int mid=(L+R)>>1;
		if (l<=mid) res=res+ask(u*2,L,mid,l,r);
		if (mid<r) res=res+ask(u*2+1,mid+1,R,l,r);
		return res;
	}
}
namespace bit
{
	#define lowbit(x) (x&(-x))
	int tr[N];
	inline void add(int x,int k)
	{
		if (x==0) return;
		//cout << "add " << x << " " << dfn[x] << " " << k << endl; 
		x=dfn[x];
		for (;x<=n;x+=lowbit(x)) tr[x]+=k;
	}
	inline int ask(int x)
	{
		int res=0;
		for (;x;x-=lowbit(x)) res+=tr[x];
		return res;
	}	
	inline int query(int x)
	{
		//cout << "query " << x << " " << dfn[x] << " " << siz[x] << endl;
		return ask(dfn[x]+siz[x]-1)-ask(dfn[x]-1);
	}
}
struct node
{
	int x,deth;
	bool operator < (const node &o) const
	{
		if (deth!=o.deth) return deth>o.deth;
		return x<o.x;
	}
};
multiset<node>s;
int p[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		tree::add(x,y),tree::add(y,x);
	}
	tree::dfs(1,0);
	tree::STwork();
	seg::build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int tp;
		cin >> tp;
		if (tp==1)
		{
			int x,y;
			cin >> x >> y;
			int z=tree::LCA(x,y);
			s.insert({z,deth[z]});
			bit::add(x,1),bit::add(y,1),bit::add(z,-1);
			if (p[z]==0) seg::update(1,1,n,dfn[z]);
			p[z]++;
		}
		else if (tp==2)
		{
			int x,y;
			cin >> x >> y;
			int z=tree::LCA(x,y);
			s.erase(s.find({z,deth[z]}));
			bit::add(x,-1),bit::add(y,-1),bit::add(z,1);
			p[z]--;
			if (p[z]==0) seg::update(1,1,n,dfn[z]);
		}
		else
		{
			int x;
			cin >> x;
			int u=s.begin()->x;
			int y=tree::K_ancestor(u,x),z=tree::K_ancestor(y,x);
			if (bit::query(z)!=s.size())
			{
				//cout << z << endl;
				//cout << bit::query(z) << endl;
				cout << "No\n";
			}
			else
			{
				point res=seg::ask(1,1,n,dfn[z],dfn[z]+siz[z]-1);
				if (tree::dis(res.x,y)<=x&&tree::dis(res.y,y)<=x) cout << "Yes\n";
				else cout << "No\n";
			}
		}
	}
	return 0;
}