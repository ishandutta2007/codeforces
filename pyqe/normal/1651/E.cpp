#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,nn,ca[3069];
vector<long long> al[3069];
bitset<3069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	nn++;
	ca[nn]=x;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
	}
}

int main()
{
	long long i,j,r,ii,k,l,p,e,e2,mn[2],mx[2],ml,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n*2;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			nn=0;
			dfs(i);
			for(j=1;j<=nn;j++)
			{
				k=(ca[j]-1)%n+1;
				e=ca[j]>n;
				for(ii=0;ii<2;ii++)
				{
					mn[ii]=inf;
					mx[ii]=-inf;
				}
				for(r=1;r<nn;r++)
				{
					p=(j+r-1)%nn+1;
					l=(ca[p]-1)%n+1;
					e2=ca[p]>n;
					mn[e2]=min(mn[e2],l);
					mx[e2]=max(mx[e2],l);
					if(r%2==0)
					{
						ml=0;
						if(k<mn[e])
						{
							ml=(mn[e]-k)*(n-mx[e]+1);
						}
						else if(k>mx[e])
						{
							ml=mn[e]*(k-mx[e]);
						}
						z+=ml*mn[!e]*(n-mx[!e]+1);
					}
				}
			}
			mn[e]=min(mn[e],k);
			mx[e]=max(mx[e],k);
			ml=nn/2;
			for(ii=0;ii<2;ii++)
			{
				ml*=mn[ii]*(n-mx[ii]+1);
			}
			z+=ml;
		}
	}
	printf("%lld\n",z);
}