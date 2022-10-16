#include <bits/stdc++.h>

using namespace std;

long long n,m;
vector<long long> al[2][1000069];

int main()
{
	long long i,ii,k,l,sz,c,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		for(ii=0;ii<2;ii++)
		{
			al[ii][k].push_back(l);
			al[ii][l].push_back(k);
		}
	}
	for(i=1;i<=n;i++)
	{
		al[1][i].push_back(i);
		for(ii=0;ii<2;ii++)
		{
			sort(al[ii][i].begin(),al[ii][i].end());
		}
	}
	for(ii=0;ii<2;ii++)
	{
		sort(al[ii]+1,al[ii]+n+1);
		for(i=1;i<=n;i++)
		{
			if(i==1||al[ii][i]!=al[ii][i-1])
			{
				c=0;
			}
			z+=c;
			c++;
		}
	}
	printf("%lld\n",z);
}