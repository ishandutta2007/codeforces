#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a,b,c,d,e,f,i,mx=-1e18;
	
	scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);
	for(i=0;i<=d;i++)
	{
		mx=max(mx,min(a,i)*e+min(min(b,c),d-i)*f);
	}
	printf("%lld\n",mx);
}