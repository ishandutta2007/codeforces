#include <bits/stdc++.h>

using namespace std;

long long n;

long long tri(long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;1;i++)
		{
			k=tri((1ll<<i)-1);
			if(k>n)
			{
				i--;
				break;
			}
			n-=k;
		}
		printf("%lld\n",i);
	}
}