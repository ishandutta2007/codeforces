#include <bits/stdc++.h>

using namespace std;

long long n,d,dv=998244353;

int main()
{
	long long i,k,ls=0,mx=0,z=1;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(k>n-d)
		{
			mx+=k;
			if(ls)
			{
				z=z*(i-ls)%dv;
			}
			ls=i;
		}
	}
	printf("%lld %lld\n",mx,z);
}