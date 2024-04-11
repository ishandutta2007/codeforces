#include <bits/stdc++.h>

using namespace std;

long long n,m,sq[1000069];

int main()
{
	long long t,rr,i,j,k,l,w,z;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		sq[k]=max(sq[k],l*w);
	}
	for(i=1;i<=m;i++)
	{
		for(j=i;j<=m;j+=i)
		{
			sq[j]=max(sq[j],sq[i]*(j/i));
		}
	}
	for(i=1;i<=m;i++)
	{
		sq[i]=max(sq[i],sq[i-1]);
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		z=-1;
		if(sq[m]>k*l)
		{
			z=upper_bound(sq+1,sq+m+1,k*l)-sq;
		}
		printf("%lld%c",z," \n"[rr==t-1]);
	}
}