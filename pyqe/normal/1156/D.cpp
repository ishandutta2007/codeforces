#include <bits/stdc++.h>

using namespace std;

long long n,dsu[2][200069],cc[2][200069];

long long fd(long long x,long long y)
{
	if(dsu[x][y]!=y)
	{
		dsu[x][y]=fd(x,dsu[x][y]);
	}
	return dsu[x][y];
}

int main()
{
	long long i,ii,k,l,w,z=0;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			dsu[ii][i]=i;
			cc[ii][i]=1;
		}
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		cc[w][fd(w,k)]+=cc[w][fd(w,l)];
		dsu[w][fd(w,l)]=fd(w,k);
	}
	for(i=1;i<=n;i++)
	{
		z+=cc[0][fd(0,i)]*cc[1][fd(1,i)]-1;
	}
	printf("%lld\n",z);
}