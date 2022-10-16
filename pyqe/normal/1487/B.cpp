#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		printf("%lld\n",(l+(l-1)/(k/2)*(k%2)-1)%k+1);
	}
}