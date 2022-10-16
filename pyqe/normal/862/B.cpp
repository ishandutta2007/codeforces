#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];
vector<long long> al[100069];
bitset<100069> vtd,a;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	fq[a[x]]++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			a[l]=!a[x];
			dfs(l);
		}
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	printf("%lld\n",fq[0]*fq[1]-(n-1));
}