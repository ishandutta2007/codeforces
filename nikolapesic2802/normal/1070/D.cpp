#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
int a[N],b[N];
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	ll ans=0;
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++)
	{
		ans+=(a[i]+b[i])/k;
		if(a[i]+b[i]<k && b[i]>0) ans++;
		else b[i+1]+=(a[i]+b[i])%k;
	}
	if(b[n+1]>0) ans++;
	printf("%lld\n",ans);
	return 0;
}