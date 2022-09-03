// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
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

#define ls (t<<1)
#define rs ((t<<1)|1)
struct SGT
{
	int mn[1100111];
	SGT(){memset(mn,63,sizeof(mn));}
	void modify(int p,int v,int tl,int tr,int t)
	{
		if(tl==tr)
		{
			mn[t]=min(mn[t],v);
			return;
		}
		int mid=(tl+tr)>>1;
		if(p<=mid)modify(p,v,tl,mid,ls);
		else modify(p,v,mid+1,tr,rs);
		mn[t]=min(mn[ls],mn[rs]);
	}
	int query(int l,int r,int tl,int tr,int t)
	{
		if(l<=tl&&tr<=r)return mn[t];
		int mid=(tl+tr)>>1,ret=inf;
		if(l<=mid)ret=min(ret,query(l,r,tl,mid,ls));
		if(r>mid)ret=min(ret,query(l,r,mid+1,tr,rs));
		return ret;
	}
};
SGT m1,m2;

vector<int> g[300111];

int n,q;
pii a[300111];
int getid(int x,int y)
{
	int ret=lower_bound(a+1,a+n+1,mp(x,y))-a;
	if(a[ret]==mp(x,y))return ret;
	return 0;
}

int tot,row[300111],l[300111],r[300111],fa[300111],d[300111],idl[300111],idr[300111];
int pos[20][300111],dist[20][300111];
namespace centroid
{
	int sz[300111],tot,vs[300111],mx[300111];
	bool use[300111];
	void dfs(int x,int f=0)
	{
		vs[++tot]=x;sz[x]=1;mx[x]=0;
		for(auto&v:g[x])if(v!=f&&!use[v])
		{
			dfs(v,x);
			sz[x]+=sz[v];
			mx[x]=max(mx[x],sz[v]);
		}
	}
	int getroot(int x)
	{
		tot=0;
		dfs(x);
		int ret=0,now=inf;
		for(int _=1,x;_<=tot;_++)
		{
			x=vs[_];
			int tmp=max(tot-sz[x],mx[x]);
			if(now>=tmp)
			{
				ret=x;
				now=tmp;
			}
		}
		return ret;
	}
	void dfs2(int x,int f,int rd)
	{
//		printf("dfs %d dep= %d\n",x,rd);
		if(f)
		{
			for(int i=idl[x];i<=idr[x];i++)
			{
				int ny=a[i].ss;ny=max(ny,l[f]);ny=min(ny,r[f]);
				dist[rd][i]=abs(a[i].ss-ny)+1;
				ny=getid(a[idl[f]].ff,ny);
				dist[rd][i]+=dist[rd][ny];
				pos[rd][i]=pos[rd][ny];
			}
		}
		for(auto&v:g[x])if(!use[v]&&v!=f)
			dfs2(v,x,rd);
	}
	void build(int x,int dep=0,int f=0)
	{
		x=getroot(x);
		use[x]=1;fa[x]=f;d[x]=dep;
		
//		printf("build %d l= %d r= %d fa= %d\n",x,idl[x],idr[x],fa[x]);
		for(int i=idl[x];i<=idr[x];i++)pos[dep][i]=a[i].ss;
		dfs2(x,0,dep);
		
		for(auto&v:g[x])if(!use[v])
			build(v,dep+1,x);
	}
};

int main()
{
	get1(n);
	for(int i=1;i<=n;i++)get2(a[i].ff,a[i].ss);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i==1||a[i].ff!=a[i-1].ff||a[i].ss!=a[i-1].ss+1)tot++;
//		printf("x= %d y= %d id= %d\n",a[i].ff,a[i].ss,tot);
		row[i]=tot;
		if(!l[tot])l[tot]=a[i].ss;r[tot]=a[i].ss;
		if(!idl[tot])idl[tot]=i;idr[tot]=i;
		int tmp=getid(a[i].ff-1,a[i].ss);
		if(tmp)
		{
			g[row[tmp]].pb(row[i]);
			g[row[i]].pb(row[tmp]);
		}
	}
	for(int i=1;i<=tot;i++)
	{
		sort(g[i].begin(),g[i].end());
		g[i].erase(unique(g[i].begin(),g[i].end()),g[i].end());
	}
	centroid::build(1);
		
	get1(q);
	for(int i=1,tp,x,y;i<=q;i++)
	{
		get3(tp,x,y);
		x=getid(x,y);
		int cur=row[x],ans=inf;
		for(int j=d[cur];j>=0;j--)
		{
			int p=pos[j][x]-l[cur]+idl[cur],&d=dist[j][x];
			if(tp==1)
			{
				m1.modify(p,d-p,1,n,1);
				m2.modify(p,d+p,1,n,1);
			}
			else
			{
				ans=min(ans,m1.query(idl[cur],p,1,n,1)+p+d);
				ans=min(ans,m2.query(p,idr[cur],1,n,1)-p+d);
			}
			cur=fa[cur];
		}
		if(tp==2)printf("%d\n",ans>n?-1:ans);
	}
	return 0;
}