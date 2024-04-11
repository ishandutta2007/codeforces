#include <bits/stdc++.h>

using namespace std;

long long n,m,ls[1069];
bitset<1069> a[1069];

int main()
{
	long long i,j,e;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		e=0;
		for(j=1;j<=m;j++)
		{
			scanf(" %c",&ch);
			a[i][j]=ch=='#';
			if(a[i][j])
			{
				if(ls[j])
				{
					e=ls[j];
				}
				ls[j]=i;
			}
		}
		if(e)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i][j]!=a[e][j])
				{
					printf("No\n");
					return 0;
				}
			}
		}
	}
	printf("Yes\n");
}