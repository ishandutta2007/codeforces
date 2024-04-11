#include <bits/stdc++.h>

using namespace std;

long long n[2];

int main()
{
	long long t,rr,ky[2],k[2],gd,it,z[2];
	
	scanf("%lld%lld%lld",n,n+1,&t);
	gd=__gcd(n[0],n[1]);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",ky,k,ky+1,k+1);
		for(it=0;it<2;it++)
		{
			ky[it]=n[ky[it]-1]/gd;
			z[it]=(k[it]-1)/ky[it]+1;
		}
		if(z[0]==z[1])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}