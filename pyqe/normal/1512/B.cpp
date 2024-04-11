#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<1069> a[1069];

int main()
{
	long long t,rr,i,j,y,x,y2,x2;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		y=-1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=ch=='*';
				if(a[i][j])
				{
					if(y==-1)
					{
						y=i;
						x=j;
					}
					else
					{
						y2=i;
						x2=j;
					}
				}
			}
		}
		if(y==y2)
		{
			a[1+(y==1)][x]=1;
			a[1+(y==1)][x2]=1;
		}
		else if(x==x2)
		{
			a[y][1+(x==1)]=1;
			a[y2][1+(x==1)]=1;
		}
		else
		{
			a[y][x2]=1;
			a[y2][x]=1;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%c",".*"[a[i][j]]);
			}
			printf("\n");
		}
	}
}