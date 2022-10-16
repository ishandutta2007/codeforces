#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069],fq[200069],zs=0;
vector<pair<long long,pair<long long,long long>>> sq;

int main()
{
	long long i,ii,u,e;
	pair<long long,long long> mxe={-1e18,-1};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		fq[a[i]]++;
		mxe=max(mxe,{fq[a[i]],a[i]});
	}
	e=mxe.sc;
	for(ii=0;ii<2;ii++)
	{
		u=-ii*2+1;
		for(i=1+(n-1)*ii;i!=n+1-(n+1)*ii;i+=u)
		{
			if(a[i]!=e&&i-u&&i-u<=n&&a[i-u]==e)
			{
				sq.push_back({(a[i]>a[i-u])+1,{i,i-u}});
				zs++;
				a[i]=e;
			}
		}
	}
	printf("%lld\n",zs);
	for(i=0;i<zs;i++)
	{
		printf("%lld %lld %lld\n",sq[i].fr,sq[i].sc.fr,sq[i].sc.sc);
	}
}