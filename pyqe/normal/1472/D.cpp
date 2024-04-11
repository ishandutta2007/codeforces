#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long t,rr,i,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		sm=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			sm+=a[i]*!(a[i]%2);
		}
		sort(a+1,a+n+1,greater<long long>());
		for(i=2;i<=n;i+=2)
		{
			sm-=a[i];
		}
		if(sm>0)
		{
			printf("Alice\n");
		}
		else if(!sm)
		{
			printf("Tie\n");
		}
		else
		{
			printf("Bob\n");
		}
	}
}