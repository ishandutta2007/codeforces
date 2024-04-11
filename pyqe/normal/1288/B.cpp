#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,k,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(c=0,k=9;k<=m;c++)
		{
			k=k*10+9;
		}
		printf("%lld\n",n*c);
	}
}