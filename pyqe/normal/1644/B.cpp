#include <bits/stdc++.h>

using namespace std;

long long n,sq[1069];

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			sq[i]=n+1-i;
		}
		for(i=1;i<=n;i++)
		{
			if(i>1)
			{
				swap(sq[i],sq[i-1]);
			}
			for(j=1;j<=n;j++)
			{
				printf("%lld%c",sq[j]," \n"[j==n]);
			}
			if(i>1)
			{
				swap(sq[i],sq[i-1]);
			}
		}
	}
}