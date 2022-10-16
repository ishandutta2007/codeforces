#include <bits/stdc++.h>

using namespace std;

long long n,m,a[4];
bool bad;

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		bad=1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<4;j++)
			{
				scanf("%lld",a+j);
			}
			bad&=a[1]!=a[2];
		}
		if(!bad&&m%2==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}