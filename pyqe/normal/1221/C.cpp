#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,a,b,c,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		k=min(min(a,b),(a+b+c)/3);
		printf("%lld\n",min(k,a+b+c-2*k));
	}
}