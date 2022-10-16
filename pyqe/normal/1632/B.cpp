#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,e;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;1ll<<i+1<n;i++);
		e=i;
		for(i=0;i<1ll<<e;i++)
		{
			printf("%lld ",(1ll<<e)-1-i);
		}
		for(i=1ll<<e;i<n;i++)
		{
			printf("%lld%c",i," \n"[i==n-1]);
		}
	}
}