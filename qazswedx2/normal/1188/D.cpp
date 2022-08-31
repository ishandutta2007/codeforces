#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,sum[100005],m=62,p[100005],nw;
ll a[100005],f[105][100005];
bool cmp(const int x,const int y)
{
	return (a[x]&((1ll<<nw)-1))>(a[y]&((1ll<<nw)-1));
}
int main()
{
	memset(f,0x3f,sizeof(f));
	scanf("%d",&n);
	ll mx=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		p[i]=i;
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=n;i++)
		a[i]=mx-a[i];
	f[0][0]=0;
	for(int i=0;i<m;i++)
	{
		for(int j=1;j<=n;j++)
			sum[j]=((a[p[j]]>>i)&1)+sum[j-1];
		for(int j=0;j<=n;j++)
		{
			int q=(j-sum[j])+(sum[n]-sum[j]),u=sum[j];
			f[i+1][u]=min(f[i+1][u],f[i][j]+q);
			q=n-q;
			u=j+(sum[n]-sum[j]);
			f[i+1][u]=min(f[i+1][u],f[i][j]+q);
		}
		nw=i+1;
		sort(p+1,p+n+1,cmp);
	}
	printf("%lld\n",f[m][0]);
	return 0;
}