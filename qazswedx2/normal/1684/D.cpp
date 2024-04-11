#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int T,n,k,a[1000005];
bool cmp(const int x,const int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for(int i=1;i<=n;i++)
			a[i]-=(n-i);
		sort(a+1,a+n+1,cmp);
		ll ans=1e18;
		for(int i=1;i<=k;i++)
		{
			sum-=a[i];
			sum-=(i-1);
			ans=min(ans,sum);
		}
		printf("%lld\n",ans);
	}
}