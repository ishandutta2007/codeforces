#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,a[100069],ps[100069],as[100069],fq[100069][2],fc[100069],ifc[100069],pwk;

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

inline long long cb(long long x,long long y)
{
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

int main()
{
	long long t,rr,i,j,ii,p,e,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		fc[0]=1;
		ifc[0]=1;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			ps[i]=ps[i-1]+a[i];
			fc[i]=fc[i-1]*i%dv;
			ifc[i]=pw(fc[i],dv-2);
		}
		for(i=1;i<n;i++)
		{
			as[i]=min(ps[i],ps[n]-ps[i]);
			for(ii=0;ii<2;ii++)
			{
				fq[i][ii]=0;
			}
		}
		sort(as+1,as+n);
		for(i=1;i<n;i++)
		{
			e=ps[i]<=ps[n]-ps[i];
			p=lower_bound(as+1,as+n,min(ps[i],ps[n]-ps[i]))-as;
			fq[p][e]++;
		}
		z=1;
		for(i=1;i<n;i++)
		{
			if(fq[i][0]+fq[i][1])
			{
				if(as[i]*2!=ps[n])
				{
					sm=0;
					for(j=0;j<=min(fq[i][0],fq[i][1]);j++)
					{
						sm=(sm+cb(fq[i][0],j)*cb(fq[i][1],j))%dv;
					}
					z=z*sm%dv;
				}
				else
				{
					z=z*pw(2,fq[i][1])%dv;
				}
			}
		}
		printf("%lld\n",z);
	}
}