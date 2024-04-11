#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,j,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		l=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			z=0;
			for(j=0;j<30;j++)
			{
				z|=(!(k>>j&1)&&(l>>j&1))<<j;
				l|=(k>>j&1)<<j;
			}
			printf("%lld%c",z," \n"[i==n]);
		}
	}
}