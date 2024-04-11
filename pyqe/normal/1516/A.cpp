#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,k,w,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		sm=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(i<n)
			{
				w=min(k,d);
				k-=w;
				d-=w;
				sm+=w;
			}
			else
			{
				k+=sm;
			}
			printf("%lld%c",k," \n"[i==n]);
		}
	}
}