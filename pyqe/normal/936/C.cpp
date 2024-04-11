#include <bits/stdc++.h>

using namespace std;

long long n,a[2][2069],ky[2069],sq[6069],zs=0;

inline void no()
{
	printf("-1\n");
	exit(0);
}

inline void op(long long x)
{
	long long i;
	
	zs++;
	sq[zs]=n-x;
	for(i=1;i<x+1-i;i++)
	{
		swap(a[0][i],a[0][x+1-i]);
	}
	for(i=1;i<n+1-i;i++)
	{
		swap(a[0][i],a[0][n+1-i]);
	}
}

int main()
{
	long long i,j,ii,k,l;
	char ch;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[ii][i]=ch-'a';
		}
	}
	k=(n+1)/2;
	l=k;
	for(i=1;i<=n;i++)
	{
		if(i%2)
		{
			ky[i]=a[1][k];
			l++;
		}
		else
		{
			ky[i]=a[1][l];
			k--;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n&&a[0][j]!=ky[i];j++);
		if(j>n)
		{
			no();
		}
		op(j-1);
		op(n-j+i);
		if(!(i==n&&i%2))
		{
			op(0);
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}