// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

namespace segtree
{
	struct node
	{
		int ls,rs,sum;
		node(){ls=rs=sum=0;}
	};
	node a[3000111];int tot;
	int copy(int t){a[++tot]=a[t];return tot;}
	int query(int ql,int qr,int l,int r,int t)
	{
		if(!t||ql>qr)return 0;
		if(ql<=l&&r<=qr)return a[t].sum;
		int mid=(l+r)>>1,ret=0;
		if(ql<=mid)ret+=query(ql,qr,l,mid,a[t].ls);
		if(qr>mid)ret+=query(ql,qr,mid+1,r,a[t].rs);
		return ret;
	}
	void modify(int p,int l,int r,int t)
	{
		if(l==r)
		{
			a[t].sum=1;
			return;
		}
		int mid=(l+r)>>1;
		if(p<=mid)
		{
			a[t].ls=copy(a[t].ls);
			modify(p,l,mid,a[t].ls);
		}
		else
		{
			a[t].rs=copy(a[t].rs);
			modify(p,mid+1,r,a[t].rs);
		}
		a[t].sum=a[a[t].ls].sum+a[a[t].rs].sum;
	}
};

int dfn[100111],timer,sz[100111],son[100111],fa[100111],dep[100111],top[100111],ord[100111];
vector<int> g[100111];
void dfs(int x)
{
	sz[x]=1;
	for(auto v:g[x])if(v!=fa[x])
	{
		fa[v]=x;
		dep[v]=dep[x]+1;
		dfs(v);
		sz[x]+=sz[v];
		if(sz[son[x]]<sz[v])son[x]=v;
	}
}
void dfs2(int x,int tp)
{
	top[x]=tp;dfn[x]=++timer;ord[timer]=x;
	if(son[x])dfs2(son[x],tp);
	for(auto v:g[x])if(v!=fa[x]&&v!=son[x])
		dfs2(v,v);
}

int n,m,rt[100111];
int query2(int a,int b,int k,int tl,int tr)
{
	int l=a-1,r=b,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		int now=segtree::query(a,mid,1,n,rt[tr])-segtree::query(a,mid,1,n,rt[tl]);
		now=mid-a+1-now;
		if(now<k)l=mid;
		else r=mid;
	}
	return ord[r];
}
int query(int a,int b,int k,int tl,int tr)
{
	vector<pii>t,t2;
	while(true)
	{
		if(top[a]==top[b])
		{
			t.pb(mp(dfn[a],dfn[b]));
			break;
		}
		else if(dep[top[a]]>dep[top[b]])
		{
			t.pb(mp(dfn[a],dfn[top[a]]));
			a=fa[top[a]];
		}
		else
		{
			t2.pb(mp(dfn[top[b]],dfn[b]));
			b=fa[top[b]];
		}
	}
	for(int i=(int)t2.size()-1;i>=0;i--)t.pb(t2[i]);
	for(auto&v:t)
	{
		bool rev=(v.ff>v.ss);if(rev)swap(v.ff,v.ss);
		int now=segtree::query(v.ff,v.ss,1,n,rt[tr])-segtree::query(v.ff,v.ss,1,n,rt[tl]);
		now=v.ss-v.ff+1-now;
//		printf("%d %d now= %d\n",v.ff,v.ss,now);
		if(now<k)k-=now;
		else return query2(v.ff,v.ss,rev?now-k+1:k,tl,tr);
	}
	return -1;
}
int main()
{
	get1(n);
	for(int i=1,x;i<=n;i++)
	{
		get1(x);if(!x)continue;
		g[x].pb(i);g[i].pb(x);
	}
	dfs(1);
	dfs2(1,1);
	rt[0]=++segtree::tot;
	get1(m);
	for(int i=1,tp,x,y,a,b;i<=m;i++)
	{
		get1(tp);
		rt[i]=segtree::copy(rt[i-1]);
		if(tp==1)
		{
			get1(x);
			segtree::modify(dfn[x],1,n,rt[i]);
		}
		else
		{
			get2(a,b);get2(x,y);
			int tmp=segtree::query(dfn[a],dfn[a],1,n,rt[i])-segtree::query(dfn[a],dfn[a],1,n,rt[y]);tmp=1-tmp;
			int t=query(a,b,x+tmp,y,i);
			if(t==b)t=-1;
			printf("%d\n",t);
		}
	}
	return 0;
}