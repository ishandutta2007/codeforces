#include <bits/stdc++.h>

using namespace std;

long long n,d[2],nn=0,ttl=0,a[100069],ps[2][100069],fq[2],pc[2][100069],inf=1e18;

int main()
{
	long long i,ii,sm,z=inf;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=(s[i-1]=='1')-(s[i-1]=='?');
		for(ii=0;ii<2;ii++)
		{
			ps[ii][i]=ps[ii][i-1];
		}
		if(a[i]+1)
		{
			ps[a[i]][i]++;
		}
	}
	scanf("%lld%lld",d,d+1);
	for(i=1;i<=n;i++)
	{
		if(a[i]+1)
		{
			ttl+=fq[!a[i]]*d[!a[i]];
			fq[a[i]]++;
		}
		else
		{
			nn++;
			for(ii=0;ii<2;ii++)
			{
				pc[ii][nn]=(ps[!ii][i-1])*d[!ii]+(ps[!ii][n]-ps[!ii][i])*d[ii];
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		sm=0;
		for(i=1;i<=nn;i++)
		{
			sm+=pc[!ii][i];
		}
		for(i=0;i<=nn;i++)
		{
			sm+=pc[ii][i]-pc[!ii][i];
			z=min(z,sm+i*(nn-i)*d[ii]);
		}
	}
	printf("%lld\n",ttl+z);
}