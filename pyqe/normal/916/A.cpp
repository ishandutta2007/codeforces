#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,l,sm;
	
	scanf("%lld%lld%lld",&n,&k,&l);
	sm=k*60+l;
	for(i=0;1;i++)
	{
		k=sm/60;
		l=sm%60;
		if(k%10==7||l%10==7)
		{
			break;
		}
		sm=(sm+24*60-n)%(24*60);
	}
	printf("%lld\n",i);
}