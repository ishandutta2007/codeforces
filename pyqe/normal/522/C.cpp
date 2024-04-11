#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069],fq[2][100069],inf=1e18;

int main()
{
	long long t,rr,i,ii,k,l,c[2],mn;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		n--;
		for(i=1;i<=m;i++)
		{
			scanf("%lld",a+i);
			for(ii=0;ii<2;ii++)
			{
				fq[ii][i]=0;
			}
		}
		bad=0;
		for(ii=0;ii<2;ii++)
		{
			c[ii]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&k,&l);
			bad|=l;
			fq[bad][k]+=!!k;
			c[bad]+=!k;
		}
		mn=inf;
		for(i=1;i<=m;i++)
		{
			if(!fq[1][i])
			{
				mn=min(mn,a[i]-fq[0][i]);
			}
		}
		for(i=1;i<=m;i++)
		{
			printf("%c","NY"[(!fq[1][i]&&a[i]-fq[0][i]<=c[0])||(a[i]-fq[0][i]-fq[1][i]+mn<=c[0]+c[1])]);
		}
		printf("\n");
	}
}