#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069];

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	a[0]=1;
	if(a[d]==a[d+1])
	{
		a[d]=-1;
	}
	printf("%lld\n",a[d]);
}