#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		k=d-(n-d)-1;
		for(i=1;i<=d;i++)
		{
			if(i<=k)
			{
				z=i;
			}
			else
			{
				z=d+1-(i-k);
			}
			printf("%lld%c",z," \n"[i==d]);
		}
	}
}