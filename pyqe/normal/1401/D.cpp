#include <bits/stdc++.h>

using namespace std;

long long n,m,nn,a[100069],sbt[100069],fq[100069],dv=1e9+7;
vector<long long> al[100069];
bitset<100069> vtd;

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			bd(l);
			nn++;
			fq[nn]=sbt[l]*(n-sbt[l]);
			sbt[x]+=sbt[l];
		}
	}
}

int main()
{
	long long t,rr,i,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			vtd[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		scanf("%lld",&m);
		for(i=1;i<=m;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+m+1);
		nn=0;
		bd(1);
		sort(fq+1,fq+nn+1);
		for(;m>nn;m--)
		{
			a[m-1]=a[m-1]*a[m]%dv;
		}
		if(m<nn)
		{
			for(i=nn;i;i--)
			{
				if(i>nn-m)
				{
					a[i]=a[i-nn+m];
				}
				else
				{
					a[i]=1;
				}
			}
		}
		z=0;
		for(i=1;i<=nn;i++)
		{
			z=(z+fq[i]%dv*a[i])%dv;
		}
		printf("%lld\n",z);
	}
}