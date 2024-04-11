#include <bits/stdc++.h>

using namespace std;

long long n,m;
bitset<1069> a[1069];

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
			for(j=1;j<=m;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=ch-'0';
			}
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<m;j++)
			{
				if(a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1]==3)
				{
					break;
				}
			}
			if(j<m)
			{
				break;
			}
		}
		if(i>=n)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}