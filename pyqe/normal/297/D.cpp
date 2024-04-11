#include <bits/stdc++.h>

using namespace std;

long long n,m,d,ttl=0;
bitset<1069> a[2][1069],sq[1069];

int main()
{
	long long i,j,ii,k,e,yy,xx,c;
	char ch;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			for(j=1;j<=m;j++)
			{
				if(!(!ii&&j==m||ii&&i==n))
				{
					scanf(" %c",&ch);
					a[ii][i][j]=ch=='N';
					ttl+=!a[ii][i][j];
				}
			}
		}
	}
	if(d==1)
	{
		if(ttl*4>=(n*(m-1)+(n-1)*m)*3)
		{
			printf("YES\n");
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				{
					printf("1%c"," \n"[j==m]);
				}
			}
		}
		else
		{
			printf("NO\n");
		}
	}
	else
	{
		e=(n-1)*m>n*(m-1);
		if(e)
		{
			swap(n,m);
		}
		for(i=1;i<=n;i++)
		{
			k=0;
			c=0;
			for(j=1;j<=m;j++)
			{
				yy=i-1;
				xx=j;
				if(e)
				{
					swap(i,j);
					swap(yy,xx);
				}
				c+=!yy||k==(sq[yy][xx]^a[!e][yy][xx]);
				sq[i][j]=k;
				k^=a[e][i][j];
				if(e)
				{
					swap(i,j);
				}
			}
			if(m-c>c)
			{
				for(j=1;j<=m;j++)
				{
					if(e)
					{
						swap(i,j);
					}
					sq[i][j]=!sq[i][j];
					if(e)
					{
						swap(i,j);
					}
				}
			}
		}
		if(e)
		{
			swap(n,m);
		}
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				printf("%lld%c",1ll+sq[i][j]," \n"[j==m]);
			}
		}
	}
}