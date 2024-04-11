#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,k,z;
	bool bad=0;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(k*2<d)
			{
				z=0;
			}
			else if(k*2>d)
			{
				z=1;
			}
			else
			{
				z=bad;
				bad^=1;
			}
			printf("%lld%c",z," \n"[i==n]);
		}
	}
}