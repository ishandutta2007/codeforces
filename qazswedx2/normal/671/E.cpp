#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,st[100005],tp,pn=1e5+2;
ll a[100005],b[100005],c[100005],d[100005];
ll sum[1000005],sum2[1000005],nans[1000005],nans2[1000005],lazy[1000005];
void pushup(int x)
{
	sum[x]=max(sum[x*2],sum[x*2+1]);
}
void col(int x,ll v)
{
	sum[x]+=v;
	lazy[x]+=v;
}
void pushdown(int x)
{
	if(lazy[x])
	{
		col(x*2,lazy[x]);
		col(x*2+1,lazy[x]);
		lazy[x]=0;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sum[x]=sum2[x]=d[l];
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
	sum2[x]=max(sum2[x*2],sum2[x*2+1]);
}
void modify(int x,int l,int r,int ql,int qr,ll v)
{
//	if(x==1) printf("modify:ql=%d,qr=%d,v=%lld\n",ql,qr,v);
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col(x,v);
		return;
	}
	int mid=(l+r)/2;
	pushdown(x);
	modify(x*2,l,mid,ql,qr,v);
	modify(x*2+1,mid+1,r,ql,qr,v);
	pushup(x);
}
void query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql)
	{
		nans[x]=nans2[x]=-1e18;
		return;
	}
	if(ql<=l&&r<=qr)
	{
		nans[x]=sum[x];
		nans2[x]=sum2[x];
		return;
	}
	int mid=(l+r)/2;
	pushdown(x);
	query(x*2,l,mid,ql,qr);
	query(x*2+1,mid+1,r,ql,qr);
	nans[x]=max(nans[x*2],nans[x*2+1]);
	nans2[x]=max(nans2[x*2],nans2[x*2+1]);
}
int tquery(int x,int l,int r,int ql,int qr,ll qwq)
{
	if(l==r) return l;
	int mid=(l+r)/2;
	pushdown(x);
	ll q=nans[x*2],q2=nans2[x*2+1];
	if(ql<=l&&r<=qr) q=sum[x*2],q2=sum2[x*2+1];
	q=max(q,qwq);
	//printf("x=%d,l=%d,r=%d,ql=%d,qr=%d,q=%lld,q2=%lld\n",x,l,r,ql,qr,q,q2);
	if(q<=q2+m) return tquery(x*2+1,mid+1,r,ql,qr,q);
	return tquery(x*2,l,mid,ql,qr,qwq);
}
bool cmp(const int x,const int y)
{
	return c[x]>c[y];
}
int main()
{
	//freopen("CF671E.in","r",stdin);
	//freopen("CF671E.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
		b[i]+=b[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i]-b[i-1];
		d[i]=b[i]-a[i];
	//	printf("i=%d,a=%lld,b=%lld,c=%lld,d=%lld\n",i,a[i],b[i],c[i],d[i]);
	}
	build(1,1,n);
	int ans=0;
	st[0]=n+1;
	for(int i=n;i>0;i--)
	{
		while(tp&&c[i]>=c[st[tp]])
		{
			if(tp>1)
				modify(1,1,n,st[tp-1]-1,n,c[st[tp]]-c[st[tp-1]]);
			tp--;
		}
		if(tp) modify(1,1,n,st[tp]-1,n,c[st[tp]]-c[i]);
		st[++tp]=i;
		c[pn]=c[i]+m;
		int r=*(lower_bound(st+1,st+tp+1,pn,cmp)-1)-1,nw;
		query(1,1,n,i,r);
		nw=tquery(1,1,n,i,r,-1e18);
	/*	printf("i=%d,r=%d,nw=%d,tp=%d\n",i,r,nw,tp);
		for(int j=1;j<=tp;j++)
			printf("%d ",st[j]);
		printf("\n");*/
		ans=max(ans,nw-i+1);
	}
	printf("%d\n",ans);
	return 0;
}