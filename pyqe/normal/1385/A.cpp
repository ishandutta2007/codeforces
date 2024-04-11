#include <bits/stdc++.h>

using namespace std;

long long a[3],sq[3];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<3;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=0;i<3;i++)
		{
			sq[i]=min(a[(i+1)%3],a[(i+2)%3]);
		}
		for(i=0;i<3;i++)
		{
			if(a[i]!=max(sq[(i+1)%3],sq[(i+2)%3]))
			{
				i=-1;
				break;
			}
		}
		if(i==-1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			for(i=2;i+1;i--)
			{
				printf("%lld%c",sq[i]," \n"[!i]);
			}
		}
	}
}