#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,sqn;

inline long long slv(long long x)
{
	long long lb,rb,k,k2,k3;
	
	lb=(n+m)/(x+1)+1;
	rb=(n+m)/x;
	k=n/x*(x+1)-n;
	if(k<0)
	{
		return 0;
	}
	k2=rb-(n+m)%rb;
	k3=lb-(n+m)%lb;
	if((n+m)%rb<n%x)
	{
		rb--;
		k2-=x+1;
	}
	if(k3<k%(x+1))
	{
		lb++;
	}
	if(k2>=k)
	{
		return max(rb-lb+1,0ll);
	}
	else
	{
		return 0;
	}
}

int main()
{
	long long i,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i*i<=n+m;i++)
	{
		z+=slv((n+m)/i);
	}
	sqn=i-1;
	for(i=(n+m)/(sqn+1);i;i--)
	{
		z+=slv(i);
	}
	printf("%lld\n",z);
}