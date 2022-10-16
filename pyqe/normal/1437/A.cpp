#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(l<k*2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}