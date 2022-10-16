#include <bits/stdc++.h>

using namespace std;

long long a[2][2];

int main()
{
	long long t,rr,ii,iii;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			for(iii=0;iii<2;iii++)
			{
				scanf("%lld",&a[ii][iii]);
			}
		}
		for(ii=0;ii!=-1&&ii<2;ii++)
		{
			for(iii=0;iii<2;iii++)
			{
				if(a[0][ii]==a[1][iii]&&a[0][!ii]+a[1][!iii]==a[0][ii])
				{
					ii=-2;
					break;
				}
			}
		}
		if(ii==-1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}