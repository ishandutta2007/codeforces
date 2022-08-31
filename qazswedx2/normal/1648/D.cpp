#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
struct pt
{
	int l,r,k;
	bool operator<(const pt p) const
	{
		return r<p.r; 
	}
}p[1000005];
int n,m,st[1000005],tp;
ll a[3][1000005],f[1000005],g[1000005];
ll sum[3000005];
ll val[22][500005];
void build(int x,int l,int r,int dep)
{
	if(l==r)
	{
		sum[x]=f[l]+g[l];
		return;
	}
	int mid=(l+r)/2;
	val[dep][mid]=f[mid];
	for(int i=mid-1;i>=l;i--)
		val[dep][i]=max(val[dep][i+1],f[i]);
	val[dep][mid+1]=g[mid+1];
	for(int i=mid+2;i<=r;i++)
		val[dep][i]=max(val[dep][i-1],g[i]);
	build(x*2,l,mid,dep+1);
	build(x*2+1,mid+1,r,dep+1);
	sum[x]=max(max(sum[x*2],sum[x*2+1]),val[dep][l]+val[dep][r]);
//	printf("x=%d,l=%d,r=%d,sum=%lld\n",x,l,r,sum[x]);
}
ll query(int x,int l,int r,int dep,int ql,int qr)
{
	if(l>qr||r<ql) return -1e18;
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2;
	ll q1,q2,q3=-1e18;
	q1=query(x*2,l,mid,dep+1,ql,qr);
	q2=query(x*2+1,mid+1,r,dep+1,ql,qr);
	if(ql<=mid&&qr>mid) q3=val[dep][max(ql,l)]+val[dep][min(r,qr)];
//	printf("query:x=%d,l=%d,r=%d,dep=%d,ql=%d,qr=%d,q=%lld,%lld,%lld\n",x,l,r,dep,ql,qr,q1,q2,q3);
	return max(max(q1,q2),q3);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<3;i++)
	{
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
		for(int j=1;j<=n;j++)
			a[i][j]+=a[i][j-1];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&p[i].l,&p[i].r,&p[i].k);
	}
	sort(p+1,p+m+1);
	int nw=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=a[0][i]-a[1][i-1];
		while(p[nw].r==i-1)
		{
			int u=lower_bound(st+1,st+tp+1,p[nw].l)-st;
			if(u<=tp)
				f[i]=max(f[i],f[st[u]]-p[nw].k);
			nw++;
		}
	//	printf("i=%d,f=%lld\n",i,f[i]);
		while(tp&&f[st[tp]]<f[i]) tp--;
		st[++tp]=i;
	}
	for(int i=1;i<=n;i++)
	{
		g[i]=a[1][i]+a[2][n]-a[2][i-1];
	//	printf("i=%d,g=%lld\n",i,g[i]);
	}
	build(1,1,n,1);
	ll ans=-1e18;
	for(int i=1;i<=m;i++)
	{
		ll qq=query(1,1,n,1,p[i].l,p[i].r);
		ans=max(ans,qq-p[i].k);
	//	printf("i=%d,l=%d,r=%d,k=%d,qq=%lld,ans=%lld\n",i,p[i].l,p[i].r,p[i].k,qq,ans);
	}
	printf("%lld\n",ans);
	return 0;
}