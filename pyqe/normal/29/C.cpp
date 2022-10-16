#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,ex[100069];
map<long long,vector<long long>> al;
map<long long,long long> dg;
map<long long,bool> vtd;

int main()
{
	long long i,ii,k,l,sz;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k,&l);
		for(ii=0;ii<2;ii++)
		{
			if(!dg[k])
			{
				nn++;
				ex[nn]=k;
			}
			al[k].push_back(l);
			dg[k]++;
			swap(k,l);
		}
	}
	for(i=1;i<=nn;i++)
	{
		if(dg[ex[i]]==1)
		{
			break;
		}
	}
	for(k=ex[i];l;k=l)
	{
		printf("%lld",k);
		vtd[k]=1;
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			if(!vtd[l])
			{
				break;
			}
			l=0;
		}
		printf("%c"," \n"[!l]);
	}
}