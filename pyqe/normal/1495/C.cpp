#include <bits/stdc++.h>

using namespace std;

long long n,m;
bitset<569> a[569];

int main()
{
	long long t,rr,i,j,e;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=ch=='X';
			}
		}
		for(i=1+(n%3==0);i<=n;i+=3)
		{
			e=1;
			for(j=1;j<=m;j++)
			{
				a[i][j]=1;
				if(i>3&&(a[i-1][j]||a[i-2][j]))
				{
					e=j;
				}
			}
			if(i>3)
			{
				a[i-1][e]=1;
				a[i-2][e]=1;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				printf("%c",".X"[a[i][j]]);
			}
			printf("\n");
		}
	}
}