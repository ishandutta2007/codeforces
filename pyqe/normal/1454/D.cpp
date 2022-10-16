#include <bits/stdc++.h>

using namespace std;

long long n,sq[100069],zs;

void chk(long long x)
{
	long long i,c=0;
	
	for(;n%x==0;n/=x,c++);
	for(;zs<c;zs++,sq[zs]=1);
	for(i=1;i<=c;i++)
	{
		sq[i]*=x;
	}
}

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		zs=0;
		for(i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				chk(i);
			}
		}
		if(n>1)
		{
			chk(n);
		}
		printf("%lld\n",zs);
		for(i=zs;i;i--)
		{
			printf("%lld%c",sq[i]," \n"[i==1]);
		}
	}
}