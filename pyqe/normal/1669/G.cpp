#include <bits/stdc++.h>

using namespace std;

long long n,m,a[1069][1069],sq[1069][1069];

int main()
{
	long long t,rr,i,j,r,l,c;
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
				a[i][j]=(ch=='*')+2*(ch=='o');
				sq[i][j]=a[i][j]/2*2;
			}
		}
		for(i=1;i<=m;i++)
		{
			l=n+1;
			c=0;
			for(j=n;j>=0;j--)
			{
				if(!j||a[j][i]==2)
				{
					for(r=l-1;r>=l-c;r--)
					{
						sq[r][i]=1;
					}
					l=j;
					c=0;
				}
				else
				{
					c+=a[j][i];
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				printf("%c",".*o"[sq[i][j]]);
			}
			printf("\n");
		}
	}
}