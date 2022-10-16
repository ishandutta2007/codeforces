#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<n/2;i++)
		{
			scanf("%lld%lld",&k,&l);
			printf("%lld %lld%c",l,-k," \n"[i==n/2-1]);
		}
	}
}