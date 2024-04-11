#include <bits/stdc++.h>

using namespace std;

long long n,m;
bitset<2000069> sq;

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&m);
	m+=n;
	for(i=1;i<=m;i++)
	{
		sq[i]=1;
	}
	for(i=3;i<=m;i+=3)
	{
		sq[i]=0;
		n--;
	}
	if(n<0)
	{
		printf("-1\n");
		return 0;
	}
	for(i=0;i<=m+1;i+=6)
	{
		if(n)
		{
			if(i&&i<=m)
			{
				sq[i]=1;
				n++;
			}
			if(i>1)
			{
				sq[i-1]=0;
				n--;
			}
			if(i<m)
			{
				sq[i+1]=0;
				n--;
			}
		}
	}
	if(n)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=m;i++)
	{
		printf("%lld",(long long)sq[i]);
	}
	printf("\n");
}