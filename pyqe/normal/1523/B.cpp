#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,j,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
		}
		printf("%lld\n",n*3);
		for(i=1;i<=n;i+=2)
		{
			for(j=0;j<6;j++)
			{
				printf("%lld %lld %lld\n",1ll+(j==1||j==4),i,i+1);
			}
		}
	}
}