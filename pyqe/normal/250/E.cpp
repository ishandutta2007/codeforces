#include <bits/stdc++.h>

using namespace std;

long long n,m,a[169][10069];

int main()
{
	long long i,j,u,p[2]={1,1},e=0,z=0;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf(" %c",&ch);
			a[i][j]=(ch=='+')+2ll*(ch=='#');
		}
		a[i][0]=2;
		a[i][m+1]=2;
	}
	for(i=1;i<n;i++)
	{
		for(;1;e^=1)
		{
			u=!e*2-1;
			for(;!a[i][p[e]+u]&&a[i+1][p[e]];p[e]+=u);
			z+=p[0]-p[1]+1;
			a[i][p[e]+u]-=a[i][p[e]+u]==1;
			if(!a[i+1][p[e]])
			{
				p[!e]=p[e];
				break;
			}
			if(a[i][p[0]+1]==2&&a[i][p[1]-1]==2)
			{
				printf("Never\n");
				return 0;
			}
		}
	}
	printf("%lld\n",z);
}