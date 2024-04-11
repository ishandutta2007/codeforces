#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			m-=k;
		}
		if(!m)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}