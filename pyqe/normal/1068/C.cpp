#include <bits/stdc++.h>

using namespace std;

long long n,m;
vector<long long> sq[169];

int main()
{
	long long i,j,k,l,sz;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		sq[i].push_back(i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		sq[k].push_back(n+i);
		sq[l].push_back(n+i);
	}
	for(i=1;i<=n;i++)
	{
		sz=sq[i].size();
		printf("%lld\n",sz);
		for(j=0;j<sz;j++)
		{
			printf("%lld %lld\n",i,sq[i][j]);
		}
	}
}