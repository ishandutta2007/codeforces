#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=2;i*i<=n+m;i++)
		{
			if((n+m)%i==0)
			{
				i=-1;
				break;
			}
		}
		if(n-m==1&&i!=-1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}