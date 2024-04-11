#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&d,&n,&m);
		for(i=0;i<n&&d>20;i++)
		{
			d=d/2+10;
		}
		d-=m*10;
		if(d<=0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}