#include <bits/stdc++.h>

using namespace std;

long long n,m;

inline long long tri(long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",tri(n)*m+tri(m-1));
	}
}