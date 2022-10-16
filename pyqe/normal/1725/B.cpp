#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long i,w,sm=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1,greater<long long>());
	for(i=1;i<=n;i++)
	{
		w=d/a[i]+1;
		sm+=w;
		if(sm>n)
		{
			break;
		}
	}
	printf("%lld\n",i-1);
}