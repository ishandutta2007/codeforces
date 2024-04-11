#include <bits/stdc++.h>

using namespace std;

long long n,m,sq[2][100069];
vector<long long> al[100069];
bitset<100069> vtd;

int main()
{
	long long i,ii,k,l,sz,c;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		sz=al[i].size();
		if(sz<n-1)
		{
			break;
		}
	}
	if(i>n)
	{
		printf("NO\n");
		return 0;
	}
	k=i;
	for(i=0;i<sz;i++)
	{
		l=al[k][i];
		vtd[l]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(i!=k&&!vtd[i])
		{
			l=i;
			break;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		c=0;
		for(i=1;i<=n;i++)
		{
			if(i!=k&&i!=l)
			{
				c++;
			}
			sq[ii][i]=c;
		}
		sq[ii][k]=n-1;
		sq[ii][l]=n-1+!ii;
	}
	printf("YES\n");
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[ii][i]," \n"[i==n]);
		}
	}
}