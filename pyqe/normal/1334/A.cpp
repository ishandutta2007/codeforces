#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,k2,l,l2;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		l=0;
		l2=0;
		bad=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&k,&k2);
			if(k<l||k2<l2||k2-k>l2-l)
			{
				bad=1;
			}
			l=k;
			l2=k2;
		}
		if(!bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}