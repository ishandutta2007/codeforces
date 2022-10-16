#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(k==l)
		{
			printf("0\n");
		}
		else
		{
			printf("%lld\n",1ll+(k>l^k%2==l%2));
		}
	}
}