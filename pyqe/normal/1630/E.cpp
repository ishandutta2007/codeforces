#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,nn=0,fq[1000069],ex[1000069],fc[1000069],ifc[1000069],dp[1000069][2],pwk;

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
	long long t,rr,i,j,ii,k,z[2];
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		fc[0]=1;
		ifc[0]=1;
		for(i=1;i<=n;i++)
		{
			fq[i]=0;
			fc[i]=fc[i-1]*i%dv;
			ifc[i]=pw(fc[i],dv-2);
		}
		nn=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(!fq[k])
			{
				nn++;
				ex[nn]=k;
			}
			fq[k]++;
		}
		for(ii=0;ii<2;ii++)
		{
			z[ii]=0;
		}
		for(i=n/nn;i;i--)
		{
			for(ii=0;ii<2;ii++)
			{
				dp[i][ii]=0;
			}
			if(n%i)
			{
				continue;
			}
			for(j=1;j<=nn;j++)
			{
				if(fq[ex[j]]%i)
				{
					break;
				}
			}
			if(j<=nn)
			{
				continue;
			}
			dp[i][0]=1;
			for(j=1;j<=nn;j++)
			{
				dp[i][0]=dp[i][0]*ifc[fq[ex[j]]/i]%dv;
			}
			for(j=1;j<=nn;j++)
			{
				if(fq[ex[j]]>=min(i*2,n))
				{
					dp[i][1]=(dp[i][1]+n/i*fc[max(n/i-2,0ll)]%dv*dp[i][0]%dv*fc[fq[ex[j]]/i]%dv*ifc[max(fq[ex[j]]/i-2,0ll)]%dv*i)%dv;
				}
			}
			dp[i][0]=dp[i][0]*fc[n/i]%dv;
			for(j=i*2;j<=n/nn;j+=i)
			{
				for(ii=0;ii<2;ii++)
				{
					dp[i][ii]=(dp[i][ii]+dv-dp[j][ii])%dv;
				}
			}
			z[0]=(z[0]+dp[i][0]*pw(n/i,dv-2))%dv;
			z[1]=(z[1]+(n*dp[i][0]+dv-dp[i][1]+(i==n))%dv*pw(n/i,dv-2))%dv;
		}
		printf("%lld\n",z[1]*pw(z[0],dv-2)%dv);
	}
}