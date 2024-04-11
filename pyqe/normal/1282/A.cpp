#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,a,b,k,l,a2,b2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&k,&l);
		if(a>b)
		{
			swap(a,b);
		}
		a2=k-l;
		b2=k+l;
		printf("%lld\n",min(b-a,max(a2-a,0ll)+max(b-b2,0ll)));
	}
}