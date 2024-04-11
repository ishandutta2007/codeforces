#include <bits/stdc++.h>

using namespace std;

long long n,ma=1e5,fq[100069],dp[100069],pwk,dv=998244353;

long long pw(long long x,long long y)
{
	if(y<0)
	{
		return 0;
	}
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
	long long i,j,k,l,c,sm,sm2,w;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k,&l);
		fq[k]+=l;
	}
	for(i=ma;i;i--)
	{
		c=0;
		sm=0;
		sm2=0;
		w=0;
		for(j=i;j<=ma;j+=i)
		{
			c+=fq[j];
			sm=(sm+j*j%dv*fq[j])%dv;
			sm2=(sm2+j*fq[j]%dv*w*2+j*j%dv*fq[j]%dv*(fq[j]-1))%dv;
			w=(w+j*fq[j])%dv;
			dp[i]=(dp[i]+dv-dp[j]);
		}
		dp[i]=(dp[i]+(c-1)%dv*sm%dv*pw(2,c-2)+sm2*((c-2)%dv*pw(2,c-3)%dv+pw(2,c-2)))%dv;
	}
	printf("%lld\n",dp[1]);
}