#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<569> a[569];

int main()
{
	long long i,j,u,uu,c,z=0;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf(" %c",&ch);
			a[i][j]=ch=='X';
		}
	}
	for(i=2;i<n;i++)
	{
		for(j=2;j<n;j++)
		{
			c=a[i][j];
			for(u=-1;u<=1;u+=2)
			{
				for(uu=-1;uu<=1;uu+=2)
				{
					c+=a[i+u][j+uu];
				}
			}
			z+=c==5;
		}
	}
	printf("%lld\n",z);
}