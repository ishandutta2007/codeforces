#include <bits/stdc++.h>

using namespace std;

long long n,sq[169][169];
bitset<169> a;

int main()
{
	long long t,rr,i,j,c,ft,l;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		c=0;
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'1';
			c+=a[i];
			for(j=1;j<=n;j++)
			{
				sq[i][j]=1;
			}
		}
		if(c==1||c==2)
		{
			printf("NO\n");
			continue;
		}
		if(c)
		{
			l=-1;
			for(i=1;i<=n;i++)
			{
				if(a[i])
				{
					if(l==-1)
					{
						ft=i;
					}
					else
					{
						sq[l][i]=0;
						sq[i][l]=2;
					}
					l=i;
				}
			}
			sq[l][ft]=0;
			sq[ft][l]=2;
		}
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)
				{
					printf("X");
				}
				else
				{
					printf("%c","-=+"[sq[i][j]]);
				}
			}
			printf("\n");
		}
	}
}