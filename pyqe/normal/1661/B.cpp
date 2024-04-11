#include <bits/stdc++.h>

using namespace std;

const long long d=15,inf=1e18;
long long n;

int main()
{
	long long i,j,k,z;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		z=inf;
		for(j=0;j<=d;j++)
		{
			z=min(z,((1ll<<j)-k%(1ll<<j))%(1ll<<j)+d-j);
		}
		printf("%lld%c",z," \n"[i==n-1]);
	}
}