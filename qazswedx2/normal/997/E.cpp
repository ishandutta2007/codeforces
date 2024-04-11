#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pt
{
	int l,r,id;
	bool operator<(const pt x) const
	{
		return r<x.r; 
	}
}q[200005];
int n,m,a[200005],st[200005],tp,st2[200005],tp2;
int sum[1000005],lazy[1000005],lazy2[1000005],ct[1000005],id=1e6;
ll sum2[1000005],qans[200005];
void pushup(int x)
{
	sum[x]=min(sum[x*2],sum[x*2+1]);
	sum2[x]=sum2[x*2]+sum2[x*2+1];
	ct[x]=0;
	if(sum[x]==sum[x*2]) ct[x]+=ct[x*2];
	if(sum[x]==sum[x*2+1]) ct[x]+=ct[x*2+1]; 
}
void col(int x,int fa)
{
	lazy[x]+=lazy[fa];
	sum[x]+=lazy[fa];
	if(sum[x]==sum[fa])
	{
		lazy2[x]+=lazy2[fa];
		sum2[x]+=1ll*ct[x]*lazy2[fa];
	}
}
void pushdown(int x)
{
	if(lazy[x]||lazy2[x])
	{
		col(x*2,x);
		col(x*2+1,x);
		lazy[x]=lazy2[x]=0;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		ct[x]=1;
		sum[x]=1;
		sum2[x]=0;
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
		lazy[id]=v,lazy2[id]=0;
		col(x,id);
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	modify(x*2,l,mid,ql,qr,v);
	modify(x*2+1,mid+1,r,ql,qr,v);
	pushup(x);
}
ll query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return 0;
	if(ql<=l&&r<=qr) return sum2[x];
	pushdown(x);
	int mid=(l+r)/2;
	return query(x*2,l,mid,ql,qr)+query(x*2+1,mid+1,r,ql,qr);
}
void print(int x,int l,int r)
{
	printf("x=%d,l=%d,r=%d,sum=%d,sum2=%lld\n",x,l,r,sum[x],sum2[x]);
	if(l==r) return;
	pushdown(x);
	int mid=(l+r)/2;
	print(x*2,l,mid);
	print(x*2+1,mid+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+m+1);
	int nw=1;
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		//printf("i=%d\n",i);
		while(tp&&a[st[tp]]>a[i])
		{
			modify(1,1,n,st[tp-1]+1,st[tp],a[st[tp]]);
			tp--;
		}
		modify(1,1,n,st[tp]+1,i,-a[i]);
		st[++tp]=i;
		while(tp2&&a[st2[tp2]]<a[i])
		{
			modify(1,1,n,st2[tp2-1]+1,st2[tp2],-a[st2[tp2]]);
			tp2--;
		}
		modify(1,1,n,st2[tp2]+1,i,a[i]);
		st2[++tp2]=i;
		modify(1,1,n,1,i,-1);
		//modify(1,1,n,i,i,-1);
		//print(1,1,n);
		if(!sum[1])
		{
			lazy[id]=0,lazy2[id]=1;
			sum[id]=0;
			col(1,id);
		}
		while(nw<=m&&q[nw].r==i)
		{
			qans[q[nw].id]=query(1,1,n,q[nw].l,q[nw].r);
			nw++;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%lld\n",qans[i]);
	return 0;
}