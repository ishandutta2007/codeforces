#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,d,fc[200069],ifc[200069],dp[200069],pwk;

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
	long long i,j,u,w,w2,sm;
	
	scanf("%lld%lld",&n,&d);
	if(d==1)
	{
		printf("1\n");
		return 0;
	}
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=d;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	for(i=n;i;i--)
	{
		w=(n-1)/i+1;
		w2=min(w,d);
		u=1;
		sm=0;
		for(j=0;j<=w2;j++)
		{
			sm=(sm+u*ifc[j])%dv;
			dp[i]=(dp[i]+pw(w2-j,w)*ifc[w2-j]%dv*sm)%dv;
			u=u*(dv-1)%dv;
		}
		for(j=i*2;j<=n;j+=i)
		{
			dp[i]=(dp[i]+dv-dp[j])%dv;
		}
		if(n%i)
		{
			dp[i]=(dp[i]+dv-dp[n])%dv;
		}
	}
	
	printf("%lld\n",dp[1]);
}