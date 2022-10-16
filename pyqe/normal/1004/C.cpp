#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],ls[100069];
bitset<100069> vtd;

int main()
{
	long long i,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ls[a[i]]=i;
	}
	sort(ls,ls+100001);
	for(i=1;i<=n;i++)
	{
		if(vtd[a[i]])
		{
			continue;
		}
		vtd[a[i]]=1;
		z+=100001-(upper_bound(ls,ls+100001,i)-ls);
	}
	printf("%lld\n",z);
}