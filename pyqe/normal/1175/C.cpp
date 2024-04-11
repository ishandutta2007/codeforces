#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069];

int main()
{
	long long t,rr,i,lh,rh,md,e,ze,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		for(lh=0,rh=1e9;lh<=rh;)
		{
			md=(lh+rh)/2;
			e=-1;
			for(i=1;i<=n;i++)
			{
				p=upper_bound(a+1,a+n+1,a[i]+md*2)-a-i;
				if(p>d)
				{
					e=a[i]+md;
					break;
				}
			}
			if(e!=-1)
			{
				ze=e;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		printf("%lld\n",ze);
	}
}