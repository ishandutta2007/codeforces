#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,sum0[1000005],sum1[1000005],lazy[1000005];
int q[500005][2];
char s[500005],ss[500005];
void pushup(int x)
{
	sum0[x]=sum0[x*2]+sum0[x*2+1];
	sum1[x]=sum1[x*2]+sum1[x*2+1];
}
void col(int x,int l,int r,int v)
{
	if(v==0) sum0[x]=r-l+1,sum1[x]=0,lazy[x]=0;
	else sum1[x]=r-l+1,sum0[x]=0,lazy[x]=1;
}
void pushdown(int x,int l,int r)
{
	if(lazy[x]!=-1)
	{
		int mid=(l+r)/2;
		col(x*2,l,mid,lazy[x]);
		col(x*2+1,mid+1,r,lazy[x]);
		lazy[x]=-1;
	}
}
void build(int x,int l,int r)
{
	lazy[x]=-1;
	if(l==r)
	{
		if(s[l]=='0') sum0[x]=1,sum1[x]=0;
		else sum0[x]=0,sum1[x]=1;
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int ql,int qr,int v)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col(x,l,r,v);
		return;
	}
	pushdown(x,l,r);
	int mid=(l+r)/2;
	modify(x*2,l,mid,ql,qr,v);
	modify(x*2+1,mid+1,r,ql,qr,v);
	pushup(x);
}
int query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return 0;
	if(ql<=l&&r<=qr) return sum1[x];
	pushdown(x,l,r);
	int mid=(l+r)/2;
	return query(x*2,l,mid,ql,qr)+query(x*2+1,mid+1,r,ql,qr);
}
int fl;
void check(int x,int l,int r)
{
	if(l==r)
	{
		if(ss[l]=='0'&&sum1[x]==1) fl=0;
		if(ss[l]=='1'&&sum1[x]==0) fl=0;
	//	printf("x=%d,l=%d,r=%d,s=%c,sum=%d\n",x,l,r,ss[l],sum1[x]);
		return;
	}
	pushdown(x,l,r);
	int mid=(l+r)/2;
	check(x*2,l,mid);
	check(x*2+1,mid+1,r);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s%s",ss+1,s+1);
		build(1,1,n);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&q[i][0],&q[i][1]);
		fl=1;
		for(int i=m;i>0;i--)
		{
			int l=q[i][0],r=q[i][1];
			int nw=query(1,1,n,l,r),len=r-l+1;
			if(nw*2<len) modify(1,1,n,l,r,0);
			else if(nw*2>len) modify(1,1,n,l,r,1);
			else fl=0;
		//	printf("i=%d,l=%d,r=%d,nw=%d,fl=%d\n",i,l,r,nw,fl);
		}
		check(1,1,n);
		if(fl) printf("YES\n");
		else printf("NO\n");
	}
}