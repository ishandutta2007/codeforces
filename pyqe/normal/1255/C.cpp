#include <bits/stdc++.h>

using namespace std;

long long n,fq[100069],z[100069];
map<pair<long long,long long>,vector<long long>> al;
bitset<100069> vtd;

int main()
{
	long long i,j,sz,l,u[3];
	
	scanf("%lld",&n);
	for(i=0;i<n-2;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%lld",u+j);
			fq[u[j]]++;
		}
		for(j=0;j<3;j++)
		{
			al[{u[j],u[(j+1)%3]}].push_back(u[(j+2)%3]);
			al[{u[j],u[(j+2)%3]}].push_back(u[(j+1)%3]);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(fq[i]==1)
		{
			z[1]=i;
			vtd[i]=1;
			break;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(fq[i]==2&&!al[{z[1],i}].empty())
		{
			z[2]=i;
			vtd[i]=1;
			break;
		}
	}
	for(i=3;i<=n;i++)
	{
		sz=al[{z[i-2],z[i-1]}].size();
		for(j=0;j<sz;j++)
		{
			l=al[{z[i-2],z[i-1]}][j];
			if(!vtd[l])
			{
				z[i]=l;
				vtd[l]=1;
				break;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",z[i]," \n"[i==n]);
	}
}