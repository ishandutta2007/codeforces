#include<bits/stdc++.h>
#define int long long
#define ll long long
#define fi first
#define se second
#define mk make_pair
#define ld long double
using namespace std;
const int N=2e5+5;
const int LOG=20;
const int inf=2e18;
const ld eps=1e-1;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int x[N],y[N],n,cntx,cnty;
struct point
{
	int x,y;
}a[N];
bool cmp1(const point &a,const point &b){return a.x==b.x?a.y<b.y:a.x<b.x;}
bool cmp2(const point &a,const point &b){return a.x==b.x?a.y>b.y:a.x<b.x;}
namespace Case1
{
	int l[N],r[N];
	int solve()
	{
		int ret=inf;
		for (int i=1,mn=a[1].y,mx=a[1].y;i<n;i++)
			l[i]=y[mn=min(mn,a[i].y)],
			r[i]=y[mx=max(mx,a[i].y)];
		for (int i=n,mn=a[n].y,mx=a[n].y;i>1;i--)
			mn=min(mn,a[i].y),
			mx=max(mx,a[i].y),
			ret=min(ret,(x[a[i-1].x]-x[1])*(r[i-1]-l[i-1])+(x[cntx]-x[a[i].x])*(y[mx]-y[mn]));
		return ret;
	}
}
namespace Case2
{
	ld X[N];
	int k[N],b[N],n1,n2;
	struct segment_tree
	{
		int t[N*4];
		#define mid ((l+r)/2)
		struct LiChao_Tree
		{
			ld calc(int u,int v){return k[u]*X[v]+b[u];}
			bool cmp(int u,int v,int w){return calc(u,w)<calc(v,w);}
			int cnt;
			struct node
			{
				int x,ls,rs;
			}t[N*LOG];
			void insert(int &w,int l,int r,int i)
			{
				if (!w) return t[w=++cnt].x=i,void();
				if (cmp(i,t[w].x,mid)) swap(i,t[w].x);
				if (l==r) return;
				if (cmp(i,t[w].x,l)) insert(t[w].ls,l,mid,i);
				if (cmp(i,t[w].x,r)) insert(t[w].rs,mid+1,r,i);
			}
			ld query(int w,int l,int r,int i)
			{
				if (!w) return inf;
				ld ret=calc(t[w].x,i);
				if (l==r) return ret;
				if (i<=mid) return min(ret,query(t[w].ls,l,mid,i));
					   else return min(ret,query(t[w].rs,mid+1,r,i));
			}
		}lct;
		#define ls (w*2)
		#define rs (w*2+1)
		void insert(int w,int l,int r,int x)
		{
			lct.insert(t[w],1,n1,x);
			if (l==r) return;
			if (x<=mid) insert(ls,l,mid,x);
				   else insert(rs,mid+1,r,x);
		}
		ld query(int w,int l,int r,int ql,int qr,int x)
		{
			if (qr<l||r<ql) return inf;
			if (ql<=l&&r<=qr) return lct.query(t[w],1,n1,x);
			return min(query(ls,l,mid,ql,qr,x),query(rs,mid+1,r,ql,qr,x));
		}
		#undef mid
		#undef rs
		#undef ls
	}t;
	pair<int,int>u[N],v[N],p[N],q[N];
	int st[N];
	int solve()
	{
		for (int i=1;i<=n*4;i++) t.t[i]=0;
		for (int i=1;i<=t.lct.cnt;i++) t.lct.t[i].x=t.lct.t[i].ls=t.lct.t[i].rs=0;
		t.lct.cnt=0;
		sort(a+1,a+1+n,cmp1);
		int top=0,ret=inf;
		for (int i=1;i<=n;i++)
		if (!top||a[st[top]].y>a[i].y) st[++top]=i;
		if (top==1) return inf;
		n1=top-1;
		for (int i=1;i<=n1;i++) u[i]=mk(x[a[st[i+1]].x],y[a[st[i]].y]);
		///////////////////////////////////////////////////////
		top=0;
		for (int i=n;i>=1;i--)
		if (!top||a[st[top]].y<a[i].y) st[++top]=i;
		if (top==1) return inf;
		reverse(st+1,st+1+top);
		n2=top-1;
		for (int i=1;i<=n2;i++) v[i]=mk(x[a[st[i]].x],y[a[st[i+1]].y]);
		///////////////////////////////////////////////////////
		for (int i=1;i<=n1;i++) p[i]=mk(x[cntx]-u[i].fi,y[cnty]-u[i].se);
		for (int i=1;i<=n2;i++) q[i]=mk(v[i].fi-x[1],v[i].se-y[1]);
		for (int i=1;i<=n2;i++) k[i]=q[i].fi,b[i]=q[i].se;
		for (int i=1;i<=n1;i++) X[i]=1.0L*p[i].se/p[i].fi;
		for (int i=1;i<=n2;i++) t.insert(1,1,n2,i);
//		print(p[1].fi,',');
//		print(p[1].se);
//		print(q[1].fi,',');
//		print(q[1].se);
//		print(n1,'_'),print(n2);
		for (int i=1;i<=n1;i++)
		{
			int l=lower_bound(v+1,v+1+n2,u[i],[&](const pair<int,int>&a,const pair<int,int>&b){
				return a.fi<b.fi;
			})-v;
			int r=upper_bound(v+1,v+1+n2,u[i],[&](const pair<int,int>&a,const pair<int,int>&b){
				return a.se>b.se;
			})-v-1;
			if (l>r) continue;
			int now=min(t.query(1,1,n2,l,r,i)*p[i].fi+eps,2e18L);
			ret=min(ret,now);
//			print(l,' '),print(r,':');
//			print(now);
		}
		return ret;
	}
}
namespace Case3
{
	struct segment_tree
	{
		#define ls (w*2)
		#define rs (w*2+1)
		#define mid ((l+r)/2)
		int t[N*4],tag[N*4];
		void update(int w,int x)
		{
			t[w]+=x;
			tag[w]+=x;
		}
		void push_down(int w)
		{
			if (!tag[w]) return;
			update(ls,tag[w]);
			update(rs,tag[w]);
			tag[w]=0;
		}
		void add(int w,int l,int r,int ql,int qr,int x)
		{
			if (qr<l||r<ql) return;
			if (ql<=l&&r<=qr) return update(w,x);
			push_down(w);
			add(ls,l,mid,ql,qr,x);
			add(rs,mid+1,r,ql,qr,x);
			t[w]=min(t[ls],t[rs]);
		}
		int query(int w,int l,int r,int ql,int qr)
		{
			if (qr<l||r<ql) return inf;
			if (ql<=l&&r<=qr) return t[w];
			push_down(w);
			return min(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
		}
		void clear(int n)
		{
			memset(t,0,sizeof(int)*n*4+1);
			memset(tag,0,sizeof(int)*n*4+1);
		}
		#undef mid
		#undef rs
		#undef ls
	}t;
	int L[N],R[N];
	int solve()
	{
		t.clear(n);
		int lenx=x[cntx]-x[1],leny=y[cnty]-y[1],ret=inf;
		for (int i=n,mn=y[a[n].y],mx=y[a[n].y];i>=1;i--)
			L[i-1]=mn=min(mn,y[a[i].y]),
			R[i-1]=mx=max(mx,y[a[i].y]);
		for (int i=2;i<n;i++) t.add(1,1,n,i,i,x[a[i].x]*leny+(R[i]-L[i])*lenx);
		for (int i=2,mn=y[a[1].y],mx=y[a[1].y],j=n-1,k=n-1,l=L[n-1],r=R[n-1];i<n;i++)
		{
			while (j>i&&R[j-1]<=mx) t.add(1,1,n,j,n-1,(R[j-1]-r)*lenx),r=R[--j];
			if (r<mx) t.add(1,1,n,j,n-1,(mx-r)*lenx),r=mx;
			while (k>i&&L[k-1]>=mn) t.add(1,1,n,k,n-1,(l-L[k-1])*lenx),l=L[--k];
			if (l>mn) t.add(1,1,n,k,n-1,(l-mn)*lenx),l=mn;
			
			int now=t.query(1,1,n,i,n-1)-x[a[i].x]*leny;
			ret=min(ret,now);
			
			mn=min(mn,y[a[i].y]);
			mx=max(mx,y[a[i].y]);
		}
		return ret;
	}
}
void Metallica()
{
	n=read();
	for (int i=1;i<=n;i++)
		x[i]=a[i].x=read(),
		y[i]=a[i].y=read();
	if (n==1) return print(0);
	sort(x+1,x+1+n),sort(y+1,y+1+n);
	cntx=unique(x+1,x+1+n)-x-1;
	cnty=unique(y+1,y+1+n)-y-1;
	for (int i=1;i<=n;i++)
		a[i].x=lower_bound(x+1,x+1+cntx,a[i].x)-x,
		a[i].y=lower_bound(y+1,y+1+cnty,a[i].y)-y;
	
	swap(cntx,cnty);
	for (int i=1;i<=n;i++) swap(x[i],y[i]);
	for (int i=1;i<=n;i++) swap(a[i].x,a[i].y);
	sort(a+1,a+1+n,cmp1);
	int ans=Case1::solve();
	sort(a+1,a+1+n,cmp2);
	ans=min(ans,Case1::solve());
	swap(cntx,cnty);
	for (int i=1;i<=n;i++) swap(x[i],y[i]);
	for (int i=1;i<=n;i++) swap(a[i].x,a[i].y);
	sort(a+1,a+1+n,cmp1);
	ans=min(ans,Case1::solve());
	sort(a+1,a+1+n,cmp2);
	ans=min(ans,Case1::solve());
	
	ans=min(ans,Case2::solve());
	for (int i=1;i<=cnty;i++) y[i]=1e9-y[i];
	reverse(y+1,y+1+cnty);
	for (int i=1;i<=n;i++) a[i].y=cnty-a[i].y+1;
	ans=min(ans,Case2::solve());
	for (int i=1;i<=cnty;i++) y[i]=1e9-y[i];
	reverse(y+1,y+1+cnty);
	for (int i=1;i<=n;i++) a[i].y=cnty-a[i].y+1;
	
	sort(a+1,a+1+n,cmp1);
	ans=min(ans,Case3::solve());
	print(ans);
}

signed main()
{
	int T=read();
	/*
	if (T==20)
	{
		for (int k=1;k<=6;k++)
		{
			n=read();
			for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();
		}
		print(n);
		for (int i=1;i<=n;i++) print(x[i],' '),print(y[i]);
	}
	else
	*/
	while (T--) Metallica();
	
	return 0;
}
/*
2
3
1 5
4 6
8 0
2
8 0
10 5

*/