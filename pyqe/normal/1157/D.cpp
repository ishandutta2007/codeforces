#include <bits/stdc++.h>

using namespace std;

long long n,d,sq[100069];

long long tri(long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long i,j,k,rm,lh,rh,md,zz=-1;
	
	scanf("%lld%lld",&d,&n);
	lh=1;
	rh=d;
	for(;lh<=rh;)
	{
		md=(lh+rh)/2;
		if(d<tri(md-1+n)-tri(md-1))
		{
			rh=md-1;
		}
		else if((n<32&&d>md*((1ll<<n)-1)))
		{
			lh=md+1;
		}
		else
		{
			zz=md;
			break;
		}
	}
	if(zz==-1)
	{
		printf("NO\n");
		return 0;
	}
	sq[1]=zz;
	d-=(tri(zz-1+n)-tri(zz-1));
	for(i=2;i<=n;i++)
	{
		k=(sq[i-1]-1)*(n+1-i);
		if(d>=k)
		{
			sq[i]=sq[i-1]*2;
			d-=k;
		}
		else
		{
			rm=d%(n+1-i);
			d/=n+1-i;
			for(j=i;j<=n;j++)
			{
				sq[j]=sq[i-1]+j-i+1+d+(j>n-rm);
			}
			break;
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}