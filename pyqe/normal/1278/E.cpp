#include <bits/stdc++.h>

using namespace std;

long long n,a[500069][2],cr=1;
vector<long long> al[500069];
bitset<500069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,c=0;
	
	vtd[x]=1;
	a[x][1]=cr+sz+(x==1);
	cr=a[x][1];
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			c++;
			a[l][0]=a[x][1]-c;
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
	a[1][0]=1;
	dfs(1);
	for(i=1;i<=n;i++)
	{
		printf("%lld %lld\n",a[i][0],a[i][1]);
	}
}