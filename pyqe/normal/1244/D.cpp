#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[3][100069],dg[100069],sq[100069];
vector<long long> al[100069];
bitset<100069> vtd;

int main()
{
	long long i,j,k,l,p,ii,sz,e,ee,mn=1e18,z,c,ll;
	
	scanf("%lld",&n);
	for(i=0;i<3;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
		dg[k]++;
		dg[l]++;
		if(dg[k]>2||dg[l]>2)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(dg[i]==1)
		{
			p=i;
			break;
		}
	}
	for(ii=1;ii<=2;ii++)
	{
		for(i=0;i<3;i++)
		{
			vtd.reset();
			z=0;
			c=i;
			ll=0;
			for(k=p;ll!=-1;k=ll)
			{
				z+=a[c][k];
				c=(c+ii)%3;
				vtd[k]=1;
				ll=-1;
				sz=al[k].size();
				for(j=0;j<sz;j++)
				{
					l=al[k][j];
					if(!vtd[l])
					{
						ll=l;
						break;
					}
				}
			}
			if(z<mn)
			{
				mn=z;
				ee=ii;
				e=i;
			}
		}
	}
	printf("%lld\n",mn);
	vtd.reset();
	c=e;
	ll=0;
	for(k=p;ll!=-1;k=ll)
	{
		sq[k]=c+1;
		c=(c+ee)%3;
		vtd[k]=1;
		ll=-1;
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			if(!vtd[l])
			{
				ll=l;
				break;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}