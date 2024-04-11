#include <bits/stdc++.h>

using namespace std;

long long n,sq[100069],zs=0;
vector<long long> al[100069];
bitset<100069> a;

int main()
{
	long long i,j,k,l,sz,c;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(k!=-1)
		{
			al[k].push_back(i);
		}
		a[i]=l;
	}
	for(i=1;i<=n;i++)
	{
		c=0;
		sz=al[i].size();
		for(j=0;j<sz;j++)
		{
			l=al[i][j];
			c+=a[l];
		}
		if(a[i]&&c==sz)
		{
			zs++;
			sq[zs]=i;
		}
	}
	if(!zs)
	{
		printf("-1\n");
	}
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}