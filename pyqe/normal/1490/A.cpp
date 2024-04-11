#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,l,mn,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(i-1)
			{
				mn=min(k,l);
				mx=max(k,l);
				for(;mn*2<mx;mn*=2,z++);
			}
			l=k;
		}
		printf("%lld\n",z);
	}
}