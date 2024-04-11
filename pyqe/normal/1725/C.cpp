#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,m,ps[300069],fc[300069],ifc[300069],pwk;

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
	long long i,j,c,c2=0,w,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",ps+i);
		ps[i]+=ps[i-1];
	}
	for(j=0,i=1;i<n;i++)
	{
		for(;j<i&&(ps[i]-ps[j])*2>ps[n];j++);
		c2+=(ps[i]-ps[j])*2==ps[n];
	}
	c=n-c2*2;
	fc[0]=1;
	for(i=1;i<=max(m,c2);i++)
	{
		fc[i]=fc[i-1]*i%dv;
	}
	ifc[max(m,c2)]=pw(fc[max(m,c2)],dv-2);
	for(i=max(m,c2);i;i--)
	{
		ifc[i-1]=ifc[i]*i%dv;
	}
	for(i=0;i<=min(m,c2);i++)
	{
		w=cb(m,i)*cb(c2,i)%dv*fc[i]%dv*pw((m-i)*(m-i-1)%dv,c2-i)%dv*pw(m-i,c)%dv;
		z=(z+w)%dv;
	}
	printf("%lld\n",z);
}