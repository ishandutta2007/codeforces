#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(k-l==1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}