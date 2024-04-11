#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[200069],df[200069];

int main()
{
	long long i,k;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<n;i++)
	{
		df[i]=a[i+1]-a[i];
	}
	sort(df+1,df+n);
	for(i=1;i<n;i++)
	{
		k=max(df[i]-1,0ll)/d;
		if(k>m)
		{
			break;
		}
		m-=k;
	}
	i--;
	printf("%lld\n",n-i);
}