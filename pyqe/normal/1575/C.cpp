#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,m,d,ps[200069],fq[200069],pr[200069][18],dp[200069][18];

int main()
{
	long long i,j,p,sm,z;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",ps+i);
		ps[i]+=ps[i-1];
	}
	z=ps[n]*m%d==0;
	fq[0]++;
	for(i=1;i<n;i++)
	{
		z=(z+(fq[ps[i]%d]+fq[(ps[i]+d-ps[n]*m%d)%d])*m)%dv;
		fq[ps[i]%d]++;
	}
	for(j=0;j<d;j++)
	{
		pr[j][0]=(j+ps[n])%d;
		dp[j][0]=fq[j];
	}
	for(i=1;i<18;i++)
	{
		for(j=0;j<d;j++)
		{
			pr[j][i]=pr[pr[j][i-1]][i-1];
			dp[j][i]=(dp[j][i-1]+dp[pr[j][i-1]][i-1])%dv;
		}
	}
	for(i=0;i<d;i++)
	{
		p=i;
		sm=0;
		for(j=0;j<18;j++)
		{
			if(m-1>>j&1)
			{
				sm=(sm+dp[p][j])%dv;
				p=pr[p][j];
			}
		}
		z=(z+sm*fq[p]%dv*m)%dv;
	}
	printf("%lld\n",z);
}