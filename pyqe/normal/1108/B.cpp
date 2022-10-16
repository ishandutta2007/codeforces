#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];
bitset<100069> vtd;

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1,greater<long long>());
	for(i=1;i<=n;i++)
	{
		if(a[1]%a[i]||vtd[a[i]])
		{
			printf("%lld %lld\n",a[1],a[i]);
			return 0;
		}
		vtd[a[i]]=1;
	}
}