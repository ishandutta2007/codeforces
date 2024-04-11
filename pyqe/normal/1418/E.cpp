#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],ps[200069],fc[200069],ifc[200069],pwk,dv=998244353;

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
	long long t,rr,i,ii,k,l,p,sm,z;
	
	scanf("%lld%lld",&n,&t);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		ps[i]=(ps[i-1]+a[i])%dv;
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		p=lower_bound(a+1,a+n+1,l)-a-1;
		sm=ps[p];
		z=0;
		for(ii=0;ii<2;ii++)
		{
			if(n-p-ii>=0&&n-p-ii+1-k>0&&p-!ii>=0)
			{
				z=(z+sm*fc[n-p-ii]%dv*(n-p-ii+1-k)%dv*fc[n]%dv*ifc[n-p-ii+1])%dv;
			}
			sm=(ps[n]+dv-sm)%dv;
		}
		z=z*ifc[n]%dv;
		printf("%lld\n",z);
	}
}