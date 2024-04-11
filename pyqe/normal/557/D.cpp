#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[2],sq[4];
vector<long long> al[100069];
bitset<100069> vtd,nr;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	fq[nr[x]]++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			nr[l]=!nr[x];
			dfs(l);
		}
		else if(nr[l]==nr[x])
		{
			printf("0 1\n");
			exit(0);
		}
		
	}
}

int main()
{
	long long i,ii,k,l;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			for(ii=0;ii<2;ii++)
			{
				fq[ii]=0;
			}
			dfs(i);
			if(max(fq[0],fq[1])>=2)
			{
				for(ii=0;ii<2;ii++)
				{
					sq[1]+=fq[ii]*(fq[ii]-1)/2;
				}
			}
			else if(min(fq[0],fq[1]))
			{
				sq[2]+=n-2;
			}
		}
	}
	sq[3]=n*(n-1)*(n-2)/6;
	for(i=1;i<=3;i++)
	{
		if(sq[i])
		{
			printf("%lld %lld\n",i,sq[i]);
			break;
		}
	}
}