#include <bits/stdc++.h>

using namespace std;

long long n,m;
bitset<1069> a[2];

int main()
{
	long long t,rr,i,j;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[0][i]=ch-'0';
		}
		a[0][n+1]=0;
		for(i=0;i<min(n,m);i++)
		{
			for(j=1;j<=n;j++)
			{
				a[1][j]=a[0][j]||(a[0][j-1]^a[0][j+1]);
			}
			for(j=1;j<=n;j++)
			{
				a[0][j]=a[1][j];
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld",(long long)a[0][i]);
		}
		printf("\n");
	}
}