#include <bits/stdc++.h>

using namespace std;

long long n,m,z=1;
bitset<1000069> vtd;

void rk(long long x,long long y,long long ub,long long lm,long long u)
{
	if(lm>ub)
	{
		return;
	}
	if(x<=y)
	{
		rk(x+1,y,ub,lm,u);
		rk(x+1,y,ub,lm/__gcd(x,lm)*x,-u);
	}
	else
	{
		z+=ub/lm*u;
	}
}

int main()
{
	long long i,j,c;
	
	scanf("%lld%lld",&n,&m);
	for(i=2;i<=n;i++)
	{
		if(!vtd[i])
		{
			for(c=0,j=i;j<=n;j*=i,c++)
			{
				vtd[j]=1;
			}
			for(j=c;j;j--)
			{
				rk(j+1,c,m*j,j,1);
			}
		}
	}
	printf("%lld\n",z);
}