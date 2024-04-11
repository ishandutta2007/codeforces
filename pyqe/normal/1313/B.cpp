#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&k,&l);
		if(k>l)
		{
			swap(k,l);
		}
		;
		printf("%lld %lld\n",max(min(k+l+1-n,n),1ll),n-max(n-l-(k-1),0ll));
	}
}