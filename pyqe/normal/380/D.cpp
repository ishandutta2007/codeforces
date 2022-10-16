#include <bits/stdc++.h>

using namespace std;

long long n,pst[100069],fc[100069],ifc[100069],a[2],rg[2][2],dp[2][2],pwk,dv=1e9+7;

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
	if(y<0||x-y<0)
	{
		return 0;
	}
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

void trn(long long x,long long w1,long long w2)
{
	long long ii,iii;
	
	a[1]=x;
	rg[1][0]=w1;
	rg[1][1]=w2;
	for(ii=0;ii<2;ii++)
	{
		dp[1][ii]=0;
		for(iii=0;iii<=(rg[0][0]!=rg[0][1]);iii++)
		{
			dp[1][ii]=(dp[1][ii]+dp[0][iii]*cb(a[0]-a[1],rg[1][ii]-rg[0][iii]))%dv;
		}
	}
	a[0]=a[1];
	for(ii=0;ii<2;ii++)
	{
		rg[0][ii]=rg[1][ii];
		dp[0][ii]=dp[1][ii];
	}
}

int main()
{
	long long i,ii,k,z=0;
	
	scanf("%lld",&n);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		pst[k]=i;
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	a[0]=n;
	for(ii=0;ii<2;ii++)
	{
		rg[0][ii]=1;
		dp[0][ii]=1;
	}
	for(i=n;i;i--)
	{
		if(pst[i])
		{
			trn(i,pst[i]-i+1,pst[i]);
			if(i-1)
			{
				trn(i-1,pst[i]-i+1,pst[i]+1);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<=(rg[0][0]!=rg[0][1]);ii++)
		{
			z=(z+dp[0][ii]*cb(a[0]-1,i-rg[0][ii]))%dv;
		}
	}
	printf("%lld\n",z);
}