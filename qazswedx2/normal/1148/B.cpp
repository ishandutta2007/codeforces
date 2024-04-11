#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,k,ta,tb,a[1000005],b[1000005];
int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&ta,&tb,&k);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%I64d",&b[i]);
	if(k>=n||k>=m)
	{
		printf("-1");
		return 0;
	}
	ll ans=0;
	for(int i=1;i<=k+1;i++)
	{
		ll tt=a[i]+ta;
		ll nw=lower_bound(b+1,b+m+1,tt)-b;
		if(nw+k-i+1>m)
		{
			printf("-1");
			return 0;
		}
		ans=max(ans,b[nw+k-i+1]+tb);
	}
	printf("%I64d",ans);
	return 0;
}