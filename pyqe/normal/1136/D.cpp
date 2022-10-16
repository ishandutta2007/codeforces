#include <bits/stdc++.h>

using namespace std;

long long n,m,a[300069],pst[300069];
vector<long long> al[300069];
bitset<300069> vtd;

int main()
{
	long long i,j,k,l,sz,c,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		pst[a[i]]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
	}
	for(i=n-1;i;i--)
	{
		c=0;
		sz=al[a[i]].size();
		for(j=0;j<sz;j++)
		{
			l=al[a[i]][j];
			if(pst[l]>i&&!vtd[pst[l]])
			{
				c++;
			}
		}
		if(c==n-i-z)
		{
			z++;
			vtd[i]=1;
		}
	}
	printf("%lld\n",z);
}