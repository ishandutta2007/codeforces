#include <bits/stdc++.h>

using namespace std;

long long n,m,ps[100069],inf=1e18;
vector<long long> vl[100069];

int main()
{
	long long i,j,k,w,sz,sm,z=-inf;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k,&w);
		vl[k].push_back(w);
	}
	for(i=1;i<=m;i++)
	{
		sort(vl[i].begin(),vl[i].end(),greater<long long>());
		sz=vl[i].size();
		sm=0;
		for(j=1;j<=sz;j++)
		{
			sm+=vl[i][j-1];
			ps[j]+=max(sm,0ll);
		}
	}
	for(i=0;i<=n;i++)
	{
		z=max(z,ps[i]);
	}
	printf("%lld\n",z);
}