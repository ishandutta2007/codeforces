#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,m,d,nn=0,dsu[300069],cc[300069],ce[300069],dg[2][300069],cdg[2][300069],fq[300069],dp[300069],ex[300069];
map<long long,long long> ve[300069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,j,ii,k,l,sz;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=d;i++)
	{
		dsu[i]=i;
		cc[i]=1;
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&sz);
		for(j=0;j<sz;j++)
		{
			scanf("%lld",&k);
			if(j&&!ve[l][k])
			{
				ve[l][k]=1;
				if(fd(k)!=fd(l))
				{
					cc[fd(l)]+=cc[fd(k)];
					ce[fd(l)]+=ce[fd(k)];
					for(ii=0;ii<2;ii++)
					{
						cdg[ii][fd(l)]+=cdg[ii][fd(k)];
					}
					dsu[fd(k)]=l;
				}
				ce[fd(k)]++;
				for(ii=0;ii<2;ii++)
				{
					cdg[ii][fd(k)]-=dg[ii][k]==1;
					dg[ii][k]++;
					cdg[ii][fd(k)]+=dg[ii][k]==1;
					swap(k,l);
				}
			}
			l=k;
		}
	}
	for(i=1;i<=d;i++)
	{
		if(fd(i)==i&&ce[i]==cc[i]-1&&cdg[0][i]==cc[i]-1&&cdg[1][i]==cc[i]-1)
		{
			fq[cc[i]]++;
		}
	}
	for(i=1;i<=d;i++)
	{
		if(fq[i])
		{
			nn++;
			ex[nn]=i;
		}
	}
	dp[0]=1;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=nn;j++)
		{
			if(i>=ex[j])
			{
				dp[i]=(dp[i]+dp[i-ex[j]]*fq[ex[j]])%dv;
			}
		}
	}
	printf("%lld\n",dp[m]);
}