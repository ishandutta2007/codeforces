#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[1005][1005],g[1005][1005],b[100005];
ll f[1005][1005],sum[1005][1005];
ll G(int x,int xx,int y,int yy)
{
	return sum[xx][yy]-sum[x-1][yy]-sum[xx][y-1]+sum[x-1][y-1];
}
ll F(int l,int r)
{
	return G(1,l-1,l,r)+G(r+1,n,l,r);
}
int build(int l,int r)
{
	if(l>r) return 0;
	int ls,rs,mid=g[l][r];
//	printf("build:l=%d,r=%d,mid=%d\n",l,r,mid);
	ls=build(l,mid-1);
	rs=build(mid+1,r);
	if(ls) b[ls]=mid;
	if(rs) b[rs]=mid;
	return mid;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]+a[i][j]-sum[i-1][j-1];
	for(int i=1;i<=n;i++)
		g[i][i]=i;
	for(int len=2;len<=n;len++)
		for(int l=1,r=l+len-1;r<=n;l++,r++)
		{
			f[l][r]=1e18;
			g[l][r]=-1;
			for(int k=l;k<=r;k++)
			{
				ll q=f[l][k-1]+f[k+1][r]+F(l,k-1)+F(k+1,r);
			//	printf("l=%d,r=%d,k=%d,q=%lld\n",l,r,k,q);
				if(f[l][r]>q)
				{
					f[l][r]=q;
					g[l][r]=k;
				}
			}
		//	printf("l=%d,r=%d,f=%lld,g=%d\n",l,r,f[l][r],g[l][r]);
		}
	build(1,n);
	for(int i=1;i<=n;i++)
		printf("%d ",b[i]);
	printf("\n");
//	printf("%lld\n",f[1][n]);
	return 0;
}