#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		printf("%lld\n",max(k+k%2,4ll)-k);
	}
}