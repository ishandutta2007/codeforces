#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,k,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		mn=1e18;
		for(i=0;i<=d;)
		{
			k=i+(d-1)/(i+1)+1;
			mn=min(mn,k);
			if((d-1)/(i+1)+1==1)
			{
				break;
			}
			i=max(i+1,(d-1)/((d-1)/(i+1)));
		}
		if(mn<=n)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}