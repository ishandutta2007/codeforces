#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long t,rr,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&d,&n,&m);
		z=(d/m+2)/2*(d%m+1)+(d/m+1)/2*(m-1-d%m);
		if(d==m||n+1>z)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}