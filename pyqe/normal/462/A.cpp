#include <bits/stdc++.h>

using namespace std;

const long long vy[4]={-1,0,1,0},vx[4]={0,1,0,-1};
long long n;
bitset<1069> a[1069];

int main()
{
	long long i,j,im,yy,xx,c;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf(" %c",&ch);
			a[i][j]=ch=='o';
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			c=0;
			for(im=0;im<4;im++)
			{
				yy=i+vy[im];
				xx=j+vx[im];
				c+=a[yy][xx];
			}
			if(c%2)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
}