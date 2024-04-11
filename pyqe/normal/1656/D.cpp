#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,z;

inline long long tri(long long x)
{
	if(x<=inf*2/(x+1))
	{
		return x*(x+1)/2;
	}
	else
	{
		return inf+1;
	}
}

inline void chk(long long x)
{
	if(x>1&&tri(x)<=n)
	{
		z=x;
	}
}

int main()
{
	long long t,rr,e;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(e=0;n>>e+1<<e+1==n;e++);
		z=-1;
		chk(1ll<<e+1);
		chk(n>>e);
		printf("%lld\n",z);
	}
}