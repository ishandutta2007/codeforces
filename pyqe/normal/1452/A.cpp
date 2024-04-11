#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(k>l)
		{
			swap(k,l);
		}
		printf("%lld\n",l+max(k,l-1));
	}
}