#include <bits/stdc++.h>

using namespace std;

const long long ma=1e5;
long long n,m;
vector<long long> vl[100069][2];

int main()
{
	long long i,j,ii,k,sz,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&k);
			for(ii=0;ii<2;ii++)
			{
				vl[k][ii].push_back(i);
				swap(i,j);
			}
		}
	}
	for(i=1;i<=ma;i++)
	{
		sz=vl[i][0].size();
		for(ii=0;ii<2;ii++)
		{
			sort(vl[i][ii].begin(),vl[i][ii].end());
			for(j=0;j<sz;j++)
			{
				k=vl[i][ii][j];
				z+=k*(j*2-(sz-1));
			}
		}
	}
	printf("%lld\n",z);
}