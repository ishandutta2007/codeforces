#include <bits/stdc++.h>

using namespace std;

long long n,m,d,z[2],ub=1e9;

void chk(long long x)
{
	long long sm[2]={x*n,((x-1)/m+1)*d};
	
	if(sm[0]!=sm[1])
	{
		z[sm[1]<sm[0]]=x;
	}
}

int main()
{
	long long t,rr,i,ii;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		for(ii=0;ii<2;ii++)
		{
			z[ii]=-1;
		}
		chk(1);
		chk(m);
		chk(ub);
		printf("%lld %lld\n",z[0],z[1]);
	}
}