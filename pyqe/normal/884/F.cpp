#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long mm=26,inf=1e18;
long long n,nn=0,a[2][100069],wg[2][100069],fq[mm],as[100069];

int main()
{
	long long i,p,e,c=0,mx,z=0;
	pair<long long,long long> mxe={-inf,-1};
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		p=i;
		e=i>n/2;
		if(e)
		{
			p=n+1-i;
		}
		a[e][p]=ch-'a';
	}
	for(i=1;i<=n;i++)
	{
		p=i;
		e=i>n/2;
		if(e)
		{
			p=n+1-i;
		}
		scanf("%lld",&wg[e][p]);
		z+=wg[e][p];
	}
	for(i=1;i<=n/2;i++)
	{
		if(a[0][i]==a[1][i])
		{
			z-=min(wg[0][i],wg[1][i]);
			fq[a[0][i]]++;
			c++;
		}
	}
	for(i=0;i<mm;i++)
	{
		mxe=max(mxe,{fq[i],i});
	}
	mx=mxe.fr;
	e=mxe.sc;
	for(i=1;i<=n/2;i++)
	{
		if(a[0][i]!=a[1][i]&&a[0][i]!=e&&a[1][i]!=e)
		{
			nn++;
			as[nn]=min(wg[0][i],wg[1][i]);
		}
	}
	sort(as+1,as+nn+1);
	for(i=1;i<=mx-(c-mx);i++)
	{
		z-=as[i];
	}
	printf("%lld\n",z);
}