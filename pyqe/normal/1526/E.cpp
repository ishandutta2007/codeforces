#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,d,a[200069],pst[200069],fc[400069],ifc[400069],pwk;

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

long long cb(long long x,long long y)
{
	if(x<y||y<0)
	{
		return 0;
	}
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

int main()
{
	long long i,c=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		a[i]++;
		pst[a[i]]=i;
	}
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n+d;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	for(i=1;i<=n;i++)
	{
		c+=i==1||pst[a[i]+1]<pst[a[i-1]+1];
	}
	printf("%lld\n",cb(d-c+n,n));
}