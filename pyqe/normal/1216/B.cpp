#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,z=0;
pair<long long,long long> a[1069];

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].fr);
		a[i].sc=i;
	}
	sort(a+1,a+n+1,greater<pair<long long,long long>>());
	for(i=1;i<=n;i++)
	{
		z+=(i-1)*a[i].fr+1;
	}
	printf("%lld\n",z);
	for(i=1;i<=n;i++)
	{
		if(i>1)
		{
			printf(" ");
		}
		printf("%lld",a[i].sc);
	}
	printf("\n");
}