#include <bits/stdc++.h>

using namespace std;

long long n,vy[4]={1,2,0,0},vx[4]={2,1,0,0};
bitset<269> a[269];
bitset<4> ex;

int main()
{
	long long t,rr,i,j,ii,c;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=ch=='1';
			}
		}
		vy[2]=n-1;
		vx[2]=n;
		vy[3]=n;
		vx[3]=n-1;
		for(i=0;i<4;i++)
		{
			ex[i]=a[vy[i]][vx[i]];
		}
		for(ii=0;ii<2;ii++)
		{
			c=0;
			for(i=0;i<4;i++)
			{
				c+=ex[i]!=(i/2^ii);
			}
			if(c<=2)
			{
				printf("%lld\n",c);
				for(i=0;i<4;i++)
				{
					if(ex[i]!=(i/2^ii))
					{
						printf("%lld %lld\n",vy[i],vx[i]);
					}
				}
				break;
			}
		}
	}
}