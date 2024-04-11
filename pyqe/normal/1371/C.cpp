#include <bits/stdc++.h>

using namespace std;

long long n,n2,d,d2;

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&n2,&d,&d2);
		if(d2>min(n,n2)||d+d2>n+n2)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
}