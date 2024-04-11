#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pr[100069],ed[100069],sq[100069];
vector<pair<long long,long long>> al[100069];
queue<long long> q;
bitset<100069> vtd;

int main()
{
	long long i,j,ii,k,l,p,sz,fh;
	
	scanf("%lld",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,i});
		al[l].push_back({k,i});
	}
	fh=1;
	for(ii=0;ii<2;ii++)
	{
		vtd.reset();
		q.push(fh);
		vtd[fh]=1;
		pr[fh]=0;
		for(;!q.empty();)
		{
			k=q.front();
			q.pop();
			sz=al[k].size();
			for(i=0;i<sz;i++)
			{
				l=al[k][i].fr;
				p=al[k][i].sc;
				if(!vtd[l])
				{
					q.push(l);
					vtd[l]=1;
					pr[l]=k;
					ed[l]=p;
				}
			}
		}
		fh=k;
	}
	for(i=1;i<=n-1;i++)
	{
		sq[i]=-1;
	}
	vtd.reset();
	for(i=0,p=fh;pr[p];p=pr[p],i++)
	{
		if(!i)
		{
			k=0;
		}
		else if(pr[pr[p]])
		{
			k=n-1-i;
		}
		else
		{
			k=1;
		}
		sq[ed[p]]=k;
		vtd[k]=1;
	}
	for(j=0,i=1;i<=n-1;i++)
	{
		if(sq[i]==-1)
		{
			for(;vtd[j];j++);
			sq[i]=j;
			vtd[j]=1;
		}
	}
	for(i=1;i<=n-1;i++)
	{
		printf("%lld\n",sq[i]);
	}
}