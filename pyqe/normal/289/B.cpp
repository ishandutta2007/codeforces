#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[100069];

int main()
{
	long long i,k,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	n*=m;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		k=abs(a[i]-a[(n+1)/2]);
		if(k%d)
		{
			printf("-1\n");
			return 0;
		}
		z+=k/d;
	}
	printf("%lld\n",z);
}