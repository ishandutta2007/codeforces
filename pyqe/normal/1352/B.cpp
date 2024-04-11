#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,ii,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(ii=0;ii<2;ii++)
		{
			k=n-(2-ii)*(d-1);
			if(k>0&&k%2==ii)
			{
				printf("YES\n");
				for(i=0;i<d-1;i++)
				{
					printf("%lld ",2ll-ii);
				}
				printf("%lld\n",k);
				ii=-1;
				break;
			}
		}
		if(ii!=-1)
		{
			printf("NO\n");
		}
	}
}