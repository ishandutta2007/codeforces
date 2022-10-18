#include <bits/stdc++.h>

using namespace std;

long long n,sq[100069];
bitset<100069> vtd;

int main()
{
	long long i,j,k,l=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(k>l)
		{
			sq[i]=l;
			vtd[l]=1;
		}
		else
		{
			sq[i]=-1;
		}
		l=k;
	}
	vtd[l]=1;
	for(j=0,i=1;i<=n;i++)
	{
		if(sq[i]==-1)
		{
			for(;vtd[j];j++);
			sq[i]=j;
			vtd[j]=1;
		}
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}