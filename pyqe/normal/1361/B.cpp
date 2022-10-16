#include <bits/stdc++.h>

using namespace std;

long long n,d,a[1000069],fq[1000069],ls[1000069],pwk,dv=1e9+7;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

int main()
{
	long long t,rr,i,j,mx,z;
	
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		if(d==1)
		{
			printf("%lld\n",n%2);
			continue;
		}
		sort(a+1,a+n+1,greater<long long>());
		mx=-1;
		z=0;
		for(i=1;i<=n;i++)
		{
			if(mx==-1)
			{
				z=(z+pw(d,a[i]))%dv;
				mx=a[i];
			}
			else
			{
				z=(z+dv-pw(d,a[i]))%dv;
				for(j=a[i];1;j++)
				{
					if(ls[j]<rr)
					{
						ls[j]=rr;
						fq[j]=0;
					}
					fq[j]++;
					if(fq[j]<d)
					{
						break;
					}
					fq[j]=0;
				}
				if(j==mx)
				{
					fq[j]=0;
					mx=-1;
				}
			}
		}
		printf("%lld\n",z);
	}
}