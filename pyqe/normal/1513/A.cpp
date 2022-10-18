#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,p,p2,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		if(d>(n-1)/2)
		{
			printf("-1\n");
			continue;
		}
		p=n+1-d;
		p2=1;
		for(i=1;i<=n;i++)
		{
			if(i%2==0&&d)
			{
				z=p;
				d--;
				p++;
			}
			else
			{
				z=p2;
				p2++;
			}
			printf("%lld%c",z," \n"[i==n]);
		}
	}
}