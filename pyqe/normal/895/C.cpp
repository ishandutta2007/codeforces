#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,ma=70,pc[71],fq[71],fc[100069],ifc[100069],dp[2][1ll<<19],pwk,dv=1e9+7;
bitset<71> vtd;

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
	long long i,j,ii,k,mk,sm[2];
	
	for(i=2;i<=ma;i++)
	{
		if(!vtd[i])
		{
			for(j=i;j<=ma;j+=i)
			{
				vtd[j]=1;
				for(k=j;k%i==0;k/=i,pc[j]^=1ll<<nn);
			}
			nn++;
		}
	}
	scanf("%lld",&n);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	dp[0][0]=1;
	for(i=1;i<=ma;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			sm[ii]=0;
		}
		for(j=0;j<=fq[i];j++)
		{
			sm[j%2]=(sm[j%2]+cb(fq[i],j))%dv;
		}
		for(mk=0;mk<1ll<<nn;mk++)
		{
			dp[1][mk]=(dp[1][mk]+dp[0][mk]*sm[0]+dp[0][mk^pc[i]]*sm[1])%dv;
		}
		for(mk=0;mk<1ll<<nn;mk++)
		{
			dp[0][mk]=dp[1][mk];
			dp[1][mk]=0;
		}
	}
	printf("%lld\n",(dp[0][0]+dv-1)%dv);
}