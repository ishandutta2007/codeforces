#include <bits/stdc++.h>

using namespace std;

long long n,fc[5069],ifc[5069],a[5069],fh[5069],dp[5069],pwk,dv=998244353;

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
	long long i,j;
	
	scanf("%lld",&n);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	sort(a+1,a+n+1);
	fh[0]=-1;
	for(j=0,i=1;i<=n;i++)
	{
		for(;a[j+1]*2<=a[i];j++);
		fh[i]=j;
	}
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=fh[i];j++)
		{
			dp[i]=(dp[i]+dp[j]*fc[fh[i]-fh[j]-1]%dv*cb(n-fh[j]-2,n-fh[i]-1))%dv;
		}
	}
	printf("%lld\n",dp[n]*(fh[n]==n-1));
}