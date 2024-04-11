#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const long long inf=1000000000000000ll;
int n,m,cnt,a[100001],nw,L,Cnt,po;
long long ans[100001],t,l,r,c;

struct node
{
	int x,ord;
	long long k;
}q[100001],Q[100001];

struct node2
{
	long long val[400001];
	int siz[400001],l[400001],r[400001];
	void build(int i,int L,int R)
	{
		l[i]=L; r[i]=R; siz[i]=R-L+1;
		if (L==R) {val[i]=1ll*L+inf; return;}
		int mid=(L+R)>>1; val[i]=0;
		build(i<<1,L,mid); build(i<<1|1,mid+1,R);
	}
	void pushdown(int i)
	{
		if (!val[i]||l[i]==r[i]) return;
		val[i<<1]+=val[i]; val[i<<1|1]+=val[i]; val[i]=0;
	}
	long long query(int i,int x)
	{
		pushdown(i);
		if (l[i]==r[i]) return val[i];
		int mid=(l[i]+r[i])>>1;
		if (x<=mid) return query(i<<1,x);
		return query(i<<1|1,x);
	}
	int find(int i,int x)
	{
		pushdown(i);
		if (l[i]==r[i]) return l[i];
		if (siz[i<<1]>=x) return find(i<<1,x);
		return find(i<<1|1,x-siz[i<<1]);
	}
	void dec(int i,int L,int R,long long v)
	{
		if (L>R) return;
		pushdown(i);
		if (l[i]==L&&r[i]==R) {val[i]-=v; return;}
		int mid=(l[i]+r[i])>>1;
		if (R<=mid) dec(i<<1,L,R,v); else
		if (L>mid) dec(i<<1|1,L,R,v); else
		dec(i<<1,L,mid,v),dec(i<<1|1,mid+1,R,v);
	}
	void del(int i,int x)
	{
		pushdown(i);
		if (l[i]==r[i]) {val[i]=-1,siz[i]=0; return;}
		int mid=(l[i]+r[i])>>1;
		if (x<=mid) del(i<<1,x); else del(i<<1|1,x);
		siz[i]=siz[i<<1]+siz[i<<1|1];
	}
}T;

bool cmpx(node a,node b) {return a.x>b.x;}
bool cmpk(node a,node b) {return a.k<b.k;}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=1; i<=m; i++) 
	{
		cnt++;
		scanf("%d%I64d",&q[cnt].x,&q[cnt].k),q[cnt].ord=i;
		if (q[cnt].x<a[1]||q[cnt].k==0) ans[i]=q[cnt].x,cnt--;
	}
	sort(q+1,q+1+cnt,cmpx); L=1; t=0;
	T.build(1,1,n); Cnt=0; nw=n;
	while (L<=cnt)
	{
		l=T.query(1,T.find(1,1)); r=T.query(1,T.find(1,T.siz[1]));
		while (L<=cnt&&q[L].x>=l&&q[L].x<=r) 
			Q[++Cnt].x=T.find(1,q[L].x-l+1),Q[Cnt].k=t-q[L].k,Q[Cnt].ord=q[L].ord,L++;
		if (L>cnt) break;
		while (nw&&a[nw]>=l&&a[nw]<=r) 
			po=T.find(1,a[nw]-l+1),T.del(1,po),T.dec(1,po+1,n,1),nw--,r--;
		if (nw&&a[nw]>q[L].x) po=a[nw]; else po=q[L].x;
		c=(l-po)/nw; l-=c*nw; r-=c*nw; t+=c; T.dec(1,1,n,c*nw);
		if (po<l) l-=nw,r-=nw,t++,T.dec(1,1,n,nw);
	}
	sort(Q+1,Q+1+Cnt,cmpk);
	L=1; t=0; T.build(1,1,n); nw=n;
	while (L<=Cnt)
	{
		l=T.query(1,T.find(1,1)); r=T.query(1,T.find(1,T.siz[1]));
		while (L<=Cnt&&Q[L].k==t) ans[Q[L].ord]=T.query(1,Q[L].x),L++;
		if (L>Cnt) break;
		while (nw&&a[nw]>=l&&a[nw]<=r)
			po=T.find(1,a[nw]-l+1),T.del(1,po),T.dec(1,po+1,n,1),nw--,r--;
		if (l-(Q[L].k-t)*nw<=a[nw])
		{
			c=(l-a[nw])/nw; l-=c*nw; r-=c*nw; t+=c; T.dec(1,1,n,c*nw);
			if (a[nw]<l) l-=nw,r-=nw,t++,T.dec(1,1,n,nw);
		} else c=Q[L].k-t,l-=c*nw,r-=c*nw,t+=c,T.dec(1,1,n,c*nw);
	}
	for (int i=1; i<=m; i++) printf("%I64d\n",ans[i]);
	return 0;
}