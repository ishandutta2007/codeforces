#include <bits/stdc++.h>

using namespace std;

long long n,m,a[569][569];

int main()
{
	long long i,j;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf(" %c",&ch);
			a[i][j]=(ch=='S')+2*(ch=='W');
			if(a[i][j]+a[i-1][j]==3||a[i][j]+a[i][j-1]==3)
			{
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%c","DSW"[a[i][j]]);
		}
		printf("\n");
	}
}