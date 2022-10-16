#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[100069];

int main()
{
	long long i,sm=0,c=0,k;
	double mx=-1e18;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		sm+=a[i];
	}
	sort(a+1,a+n+1);
	for(i=0;i<n&&i<=d;i++)
	{
		c+=a[i];
		k=sm-c+min(d-i,(n-i)*m);
		mx=max(mx,(double)k/(n-i));
	}
	printf("%.20lf\n",mx);
}