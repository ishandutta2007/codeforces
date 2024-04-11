#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1,greater<long long>());
	for(i=0;d>0;)
	{
		i++;
		d-=a[i];
	}
	printf("%lld\n",i);
}