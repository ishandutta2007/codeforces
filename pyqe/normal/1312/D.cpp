#include <bits/stdc++.h>

using namespace std;

long long n,m,fc[200069],ifc[200069],pwk,dv=998244353;

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
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&m);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=m;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	printf("%lld\n",cb(m,n-1)*(n-2)%dv*pw(2,n-3)%dv);
}