#include <bits/stdc++.h>

using namespace std;

long long n,d,ln=0,a[200069],pwk,inf=1e18;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	if(pwk<=inf/pwk)
	{
		pwk*=pwk;
	}
	else
	{
		pwk=inf;
	}
	if(y%2)
	{
		if(pwk<=inf/x)
		{
			pwk*=x;
		}
		else
		{
			pwk=inf;
		}
	}
	return pwk;
}

int main()
{
	long long i,k,w,lh,rh,md,zz,sm,ml,gd;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if(a[i]>=d)
		{
			printf("0\n");
			return 0;
		}
		if(!ln&&a[i])
		{
			ln=n+1-i;
		}
	}
	for(lh=1,rh=inf;lh<=rh;)
	{
		md=(lh+rh)/2;
		if(pw(md/(ln-1),ln-1)>=inf)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	for(lh=1,rh=zz;lh<=rh;)
	{
		md=(lh+rh)/2;
		sm=0;
		ml=1;
		for(i=0;i<ln;i++)
		{
			if(i)
			{
				k=(md-1+i);
				w=i;
				gd=__gcd(ml,w);
				ml/=gd;
				w/=gd;
				gd=__gcd(k,w);
				k/=gd;
				w/=gd;
				if(w==1&&ml<=inf/k)
				{
					ml*=k;
				}
				else
				{
					ml=inf;
				}
			}
			if(a[n-i]<=inf/ml)
			{
				k=a[n-i]*ml;
			}
			else
			{
				k=inf;
			}
			sm+=k;
			if(sm>inf)
			{
				sm=inf;
			}
		}
		if(sm>=d)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",zz);
}