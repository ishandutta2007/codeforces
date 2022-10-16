#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i,gd,mm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		gd=__gcd(n,m);
		n/=gd;
		m/=gd;
		for(mm=m,i=2;i*i<=mm;i++)
		{
			if(mm%i==0)
			{
				m=m/i*(i-1);
				for(;mm%i==0;mm/=i);
			}
		}
		if(mm>1)
		{
			m=m/mm*(mm-1);
		}
		printf("%lld\n",m);
	}
}