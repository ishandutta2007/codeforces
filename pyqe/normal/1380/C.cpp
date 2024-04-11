#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long t,rr,i,ls,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1,greater<long long>());
		ls=0;
		z=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]*(i-ls)>=d)
			{
				ls=i;
				z++;
			}
		}
		printf("%lld\n",z);
	}
}