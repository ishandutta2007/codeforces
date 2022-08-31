#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,ans,st[200005],tp;
ll sum[200005],b[200005],a[200005],mx[1000005];
bool cmp(const int x,const int y)
{
	return b[x]>b[y];
}
void upd(int l,int r)
{
	if(r-l>=2&&sum[r-1]-sum[l]==(a[r]^a[l])) ans++;
}
void pushup(int x)
{
	mx[x]=min(mx[x*2],mx[x*2+1]);
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		mx[x]=b[l];
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void query(int x,int l,int r,int ql,ll v)
{
	if(r<ql||mx[x]>v) return;
	if(l==r)
	{
		st[++tp]=l;
		return;
	}
	int mid=(l+r)/2;
	query(x*2,l,mid,ql,v);
	query(x*2+1,mid+1,r,ql,v);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
		b[i]=sum[i-1]-a[i];
/*	for(int i=1;i<=n;i++)
		printf("%lld ",b[i]);
	printf("\n");*/
	build(1,1,n);
	for(int i=n;i>0;i--)
	{
		int nw=lower_bound(sum+1,sum+n+1,sum[i]+a[i])-sum;
		upd(i,nw);
		tp=0;
		query(1,1,n,nw+1,sum[i]+a[i]);
		for(int j=1;j<=tp;j++)
			upd(i,st[j]);
	}
	printf("%d\n",ans);
	return 0;
}