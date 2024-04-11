#include <bits/stdc++.h>

using namespace std;

const long long ma=1e9;
long long n,sq[1069];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		sq[1]=1;
		for(i=2;i<=n;i++)
		{
			sq[i]=sq[i-1]*3;
			if(sq[i]>ma)
			{
				break;
			}
		}
		if(i>n)
		{
			printf("YES\n");
			for(i=1;i<=n;i++)
			{
				printf("%lld%c",sq[i]," \n"[i==n]);
			}
		}
		else
		{
			printf("NO\n");
		}
	}
}