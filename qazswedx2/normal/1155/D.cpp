#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,x,a[500005],f[500005],g[500005],sum[500005],ans=0;
int main()
{
	scanf("%I64d%I64d",&n,&x);
	if(x>0)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%I64d",&a[i]);
			f[i]=max(0ll,f[i-1]+a[i]);
			ans=max(ans,f[i]);
		}
		printf("%I64d",ans*x);
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%I64d",&a[i]);
			f[i]=max(0ll,f[i-1]+a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=n;i>0;i--)
			g[i]=max(0ll,g[i+1]+a[i]);
		//for(int i=1;i<=n;i++)
		//	printf("i=%d,f=%I64d,g=%I64d,sum=%I64d\n",i,f[i],g[i],sum[i]);
		ll maxn=0;
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,g[i]+x*sum[i-1]+maxn);
			maxn=max(maxn,f[i]-x*sum[i]);
		}
		ans=max(ans,x*sum[n]+maxn);
		printf("%I64d",ans);
		return 0;
	}
}