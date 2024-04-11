#include <bits/stdc++.h>

using namespace std;

long long n,d[2],m;

int main()
{
	long long t,rr,i,k,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,d,d+1,&m);
		z=0;
		for(i=0;i<n;i++)
		{
			scanf(" %c",&ch);
			k=ch-'0';
			z+=min(d[k],d[!k]+m);
		}
		printf("%lld\n",z);
	}
}