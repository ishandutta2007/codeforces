#include <bits/stdc++.h>

using namespace std;

long long n,d1,d2,m,a[200069];

int main()
{
	long long i,k;
	
	scanf("%lld%lld%lld%lld",&n,&d1,&d2,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=(max((k-1)%(d1+d2)+1-d1,0ll)+d1-1)/d1;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n&&m>=a[i];i++)
	{
		m-=a[i];
	}
	printf("%lld\n",i-1);
}