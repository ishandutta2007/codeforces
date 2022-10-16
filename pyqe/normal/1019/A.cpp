#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,fq[3069],inf=1e18;
pair<long long,long long> a[3069],vl[3069][3069];
bitset<3069> vtd;

int main()
{
	long long i,j,r,k,w,sm,z=inf;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&w);
		a[i]={w+inf*(k==1),i};
		fq[k]++;
		vl[k][fq[k]]=a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=m;i++)
	{
		sort(vl[i]+1,vl[i]+fq[i]+1);
	}
	for(i=1;i<=n;i++)
	{
		sm=0;
		w=fq[1];
		vtd.reset();
		for(j=2;j<=m;j++)
		{
			for(r=1;r<=fq[j]-i+1;r++)
			{
				sm+=vl[j][r].fr;
				w++;
				vtd[vl[j][r].sc]=1;
			}
		}
		for(j=1;j<=n;j++)
		{
			if(!vtd[a[j].sc]&&w<i)
			{
				sm+=a[j].fr;
				w++;
			}
		}
		z=min(z,sm);
	}
	printf("%lld\n",z);
}