#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m=0,a[400069],fqq[400069];
map<long long,long long> fq;
vector<long long> v[400069],sq[400069];

int main()
{
	long long i,j,r,k,c=0,sm=0,mx,e,y=0,x=0;
	pair<long long,long long> mxe={-1e18,-1};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(!fq[k])
		{
			m++;
			a[m]=k;
		}
		fq[k]++;
	}
	for(i=1;i<=m;i++)
	{
		v[fq[a[i]]].push_back(a[i]);
		fqq[fq[a[i]]]++;
	}
	for(i=1;i<=n;i++)
	{
		k=(sm+i*(m-c))/i;
		if(k>=i)
		{
			mxe=max(mxe,{k*i,i});
		}
		c+=fqq[i];
		sm+=fqq[i]*i;
	}
	mx=mxe.fr;
	e=mxe.sc;
	for(i=0;i<e;i++)
	{
		for(j=0;j<mx/e;j++)
		{
			sq[i].push_back(0);
		}
	}
	c=0;
	for(i=n;i;i--)
	{
		for(j=0;j<fqq[i];j++)
		{
			for(r=0;c<mx&&r<min(i,e);r++,c++)
			{
				sq[y][x]=v[i][j];
				y=(y+1)%e;
				x=(x+1)%(mx/e);
				if(sq[y][x])
				{
					y++;
				}
			}
		}
	}
	printf("%lld\n%lld %lld\n",mx,e,mx/e);
	for(i=0;i<e;i++)
	{
		for(j=0;j<mx/e;j++)
		{
			printf("%lld%c",sq[i][j]," \n"[j==mx/e-1]);
		}
	}
}