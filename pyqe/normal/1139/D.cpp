#include <bits/stdc++.h>

using namespace std;

long long n,fq[100069],dp[100069],pwk,dv=1e9+7;
bitset<100069> vtd;
vector<long long> fz[100069];

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
	long long i,j,r,l,sz,szz,ll,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j+=i)
		{
			fz[j].push_back(i);
		}
	}
	for(i=1;i<=n;i++)
	{
		sz=fz[i].size();
		for(j=sz-1;j+1;j--)
		{
			l=fz[i][j];
			fq[l]=n/l;
			szz=fz[i/l].size();
			for(r=1;r<szz;r++)
			{
				ll=fz[i/l][r];
				fq[l]-=fq[l*ll];
			}
			if(l!=i)
			{
				dp[i]=(dp[i]+dp[l]*fq[l])%dv;
			}
		}
		dp[i]=(dp[i]*pw(n,dv-2)+1)%dv*n%dv*pw(n-fq[i],dv-2)%dv;
		z=(z+dp[i])%dv;
	}
	z=(z*pw(n,dv-2)+1)%dv;
	printf("%lld\n",z);
}