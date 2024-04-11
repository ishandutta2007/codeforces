#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,a[100005],d[100005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	if(m==0)
	{
		ll ans=0,nw=0;
		for(int i=n;i>=1;i--)
		{
			nw+=a[i];
			ans=max(ans,nw-d[i]);
		}
		printf("%lld\n",ans);
		return 0;
	}
	if(m>1)
	{
		ll ans=0,nw=0;
		ans=max(ans,(ll)a[n]-d[n]);
		for(int i=1;i<=n;i++)
			nw+=a[i];
		for(int i=1;i<n;i++)
			ans=max(ans,nw-d[i]);
		printf("%lld\n",ans);
		return 0;
	}
	ll ans=0,nw=0,sum=0;
	int mn=1e9,sd=1e9,mna=1e9;
	for(int i=1;i<=n;i++)
	{
		nw+=a[i];
		if(mn>d[i]) sd=mn,mn=d[i];
		else if(sd>d[i]) sd=d[i];
		if(i>1) mna=min(mna,a[i]);
	}
	ans=max(ans,nw-mn-sd);
	ans=max(ans,(ll)a[n]-d[n]);
	ans=max(ans,nw-d[1]-mna);
	sum=a[n];
	for(int i=n-1;i>1;i--)
	{
		ans=max(ans,nw-a[n]-d[i]);
		sum+=a[i];
		ans=max(ans,sum-d[i]);
	}
	printf("%lld",ans);
	return 0;
}