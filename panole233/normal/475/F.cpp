#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;

int n,x[100001],y[100001],b[100001],nb,cntx,cnty,nw;
set<pair<int,int> > sx[4000001],sy[4000001];
set<pair<int,int> >::iterator it;

struct node
{
	int x,ord;
}A[100001];

struct node2
{
	int mi[800001],l[800001],r[800001],s[800001],po[800001];
	bool laz[800001];
	void build(int i,int L,int R)
	{
		l[i]=L; r[i]=R; laz[i]=0; s[i]=0; 
		po[i]=L; mi[i]=0;
		if (L==R) return;
		int mid=(L+R)>>1;
		build(i<<1,L,mid); build(i<<1|1,mid+1,R);
	}
	void pushdown(int i)
	{
		if (l[i]==r[i]||(!laz[i])) return;
		laz[i<<1]=laz[i<<1|1]=1; laz[i]=0;
		mi[i<<1]=mi[i<<1|1]=s[i<<1]=s[i<<1|1]=0;
		po[i<<1]=l[i<<1]; po[i<<1|1]=l[i<<1|1];
	}
	void pushup(int i)
	{
		s[i]=s[i<<1]+s[i<<1|1];
		if (mi[i<<1]<=mi[i<<1|1]) mi[i]=mi[i<<1],po[i]=po[i<<1];
		else mi[i]=mi[i<<1|1],po[i]=po[i<<1|1];
	}
	void add(int i,int x,int val)
	{
		pushdown(i);
		if (l[i]==r[i]) {mi[i]+=val,s[i]+=val; return;}
		int mid=(l[i]+r[i])>>1;
		if (x<=mid) add(i<<1,x,val);
		else add(i<<1|1,x,val);
		pushup(i);
	}
	int query(int i,int L,int R)
	{
		pushdown(i);
		if (L==l[i]&&R==r[i]) return s[i];
		int mid=(l[i]+r[i])>>1;
		if (R<=mid) return query(i<<1,L,R);
		if (L>mid) return query(i<<1|1,L,R);
		return query(i<<1,L,mid)+query(i<<1|1,mid+1,R);
	}
	pair<int,int> Query(int i,int L,int R)
	{
		pushdown(i);
		if (L==l[i]&&R==r[i]) return make_pair(mi[i],po[i]);
		int mid=(l[i]+r[i])>>1;
		if (R<=mid) return Query(i<<1,L,R);
		if (L>mid) return Query(i<<1|1,L,R);
		return min(Query(i<<1,L,mid),Query(i<<1|1,mid+1,R));
	}
	void change(int i,int L,int R)
	{
		pushdown(i);
		if (L==l[i]&&R==r[i]) {laz[i]=1,mi[i]=s[i]=0,po[i]=l[i]; return;}
		int mid=(l[i]+r[i])>>1;
		if (R<=mid) change(i<<1,L,R); else
		if (L>mid) change(i<<1|1,L,R); else
		change(i<<1,L,mid),change(i<<1|1,mid+1,R);
		pushup(i);
	}
}tx,ty;

bool cmp(node a,node b) {return a.x<b.x;}

void del(int i,int X)
{
	it=sx[i].lower_bound(make_pair(x[X],X)); sx[i].erase(it);
	it=sy[i].lower_bound(make_pair(y[X],X)); sy[i].erase(it);
}

int solve(int dep,int lx,int rx,int ly,int ry,int sz)
{
	if (lx>rx||ly>ry||(!sx[dep].size())) return 0;
	lx=(*sx[dep].begin()).first; ly=(*sy[dep].begin()).first;
	it=sx[dep].end(); it--; rx=(*it).first;
	it=sy[dep].end(); it--; ry=(*it).first;
	pair<int,int> pi=tx.Query(1,lx,rx);
	if (!pi.first)
	{
		int s=tx.query(1,lx,pi.second),l=nb+1;
		if (s<sz-s)
		{
			for (it=sx[dep].begin(); it!=sx[dep].end(); it++)
				if ((*it).first<pi.second) b[++nb]=(*it).second; else break;
			nw++; int Nw=nw;
			for (int i=l; i<=nb; i++) del(dep,b[i]),sx[Nw].insert(make_pair(x[b[i]],b[i])),sy[Nw].insert(make_pair(y[b[i]],b[i]));
			for (int i=l; i<=nb; i++) tx.add(1,x[b[i]],-1),ty.add(1,y[b[i]],-1);
			int ans=solve(dep,pi.second+1,rx,ly,ry,sz-s);
			tx.change(1,lx,rx); ty.change(1,ly,ry);
			for (int i=l; i<=nb; i++) tx.add(1,x[b[i]],1),ty.add(1,y[b[i]],1);
			ans+=solve(Nw,lx,pi.second-1,ly,ry,s);
			nb=l-1; return ans;
		} else
		{
			for (it=sx[dep].end(); it!=sx[dep].begin();)
			{
				it--;
				if ((*it).first>pi.second) b[++nb]=(*it).second; else break;
			}
			nw++; int Nw=nw;
			for (int i=l; i<=nb; i++) del(dep,b[i]),sx[Nw].insert(make_pair(x[b[i]],b[i])),sy[Nw].insert(make_pair(y[b[i]],b[i]));
			for (int i=l; i<=nb; i++) tx.add(1,x[b[i]],-1),ty.add(1,y[b[i]],-1);
			int ans=solve(dep,lx,pi.second-1,ly,ry,s);
			tx.change(1,lx,rx); ty.change(1,ly,ry);
			for (int i=l; i<=nb; i++) tx.add(1,x[b[i]],1),ty.add(1,y[b[i]],1);
			ans+=solve(Nw,pi.second+1,rx,ly,ry,sz-s);
			nb=l-1; return ans;
		}
	}
	pi=ty.Query(1,ly,ry);
	if (!pi.first)
	{
		int s=ty.query(1,ly,pi.second),l=nb+1;
		if (s<sz-s)
		{
			for (it=sy[dep].begin(); it!=sy[dep].end(); it++)
				if ((*it).first<pi.second) b[++nb]=(*it).second; else break;
			nw++; int Nw=nw;
			for (int i=l; i<=nb; i++) del(dep,b[i]),sx[Nw].insert(make_pair(x[b[i]],b[i])),sy[Nw].insert(make_pair(y[b[i]],b[i]));
			for (int i=l; i<=nb; i++) tx.add(1,x[b[i]],-1),ty.add(1,y[b[i]],-1);
			int ans=solve(dep,lx,rx,pi.second+1,ry,sz-s);
			tx.change(1,lx,rx); ty.change(1,ly,ry);
			for (int i=l; i<=nb; i++) tx.add(1,x[b[i]],1),ty.add(1,y[b[i]],1);
			ans+=solve(Nw,lx,rx,ly,pi.second-1,s);
			nb=l-1; return ans;
		} else
		{
			for (it=sy[dep].end(); it!=sy[dep].begin();)
			{
				it--;
				if ((*it).first>pi.second) b[++nb]=(*it).second; else break;
			}
			nw++; int Nw=nw;
			for (int i=l; i<=nb; i++) del(dep,b[i]),sx[Nw].insert(make_pair(x[b[i]],b[i])),sy[Nw].insert(make_pair(y[b[i]],b[i]));
			for (int i=l; i<=nb; i++) tx.add(1,x[b[i]],-1),ty.add(1,y[b[i]],-1);
			int ans=solve(dep,lx,rx,ly,pi.second-1,s);
			tx.change(1,lx,rx); ty.change(1,ly,ry);
			for (int i=l; i<=nb; i++) tx.add(1,x[b[i]],1),ty.add(1,y[b[i]],1);
			ans+=solve(Nw,lx,rx,pi.second+1,ry,sz-s);
			nb=l-1; return ans;
		}
	} 
	return 1;
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d%d",&x[i],&y[i]);
	for (int i=1; i<=n; i++) A[i].ord=i,A[i].x=x[i];
	sort(A+1,A+1+n,cmp); cntx=0; A[0].x=A[1].x-1;
	for (int i=1; i<=n; i++)
		if (A[i].x!=A[i-1].x)
		{
			if (A[i-1].x==A[i].x-1) x[A[i].ord]=(++cntx);
			else cntx+=2,x[A[i].ord]=cntx;
		} else x[A[i].ord]=cntx;
	for (int i=1; i<=n; i++) A[i].ord=i,A[i].x=y[i];
	sort(A+1,A+1+n,cmp); cnty=0; A[0].x=A[1].x-1;
	for (int i=1; i<=n; i++)
		if (A[i].x!=A[i-1].x)
		{
			if (A[i-1].x==A[i].x-1) y[A[i].ord]=(++cnty);
			else cnty+=2,y[A[i].ord]=cnty;
		} else y[A[i].ord]=cnty;
	tx.build(1,1,cntx); ty.build(1,1,cnty);
	for (int i=1; i<=n; i++) tx.add(1,x[i],1),ty.add(1,y[i],1);
	for (int i=0; i<=4000000; i++) sx[i].clear(),sy[i].clear();
	for (int i=1; i<=n; i++) sx[0].insert(make_pair(x[i],i)),sy[0].insert(make_pair(y[i],i));
	nw=nb=0; printf("%d\n",solve(0,1,cntx,1,cnty,n));
	return 0;
}