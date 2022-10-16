#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long i,k,sm=0,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k<=m)
		{
			sm+=k;
			if(sm>d)
			{
				z++;
				sm=0;
			}
		}
	}
	printf("%lld\n",z);
}