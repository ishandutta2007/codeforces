#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
int f1[1010][1010],f2[1010][1010],from1[1010][1010],from2[1010][1010],a[1010][1010],b[1010][1010],c[1010][1010],n,posx,posy,x;
bool zero;
void print1(int x,int y)
{
	if(x==1&&y==1)
		return;
	print1(x-from1[x][y],y-(from1[x][y]^1));
	putchar(from1[x][y]?'D':'R');
}
void print2(int x,int y)
{
	if(x==1&&y==1)
		return;
	print2(x-from2[x][y],y-(from2[x][y]^1));
	putchar(from2[x][y]?'D':'R');
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(!a[i][j])
			{
				zero=1;
				posx=i;
				posy=j;
			}
			for(x=a[i][j];x&&x%2==0;x/=2)
				b[i][j]++;
			for(x=a[i][j];x&&x%5==0;x/=5)
				c[i][j]++;
		}
	memset(f1,0x7f,sizeof(f1));
	memset(f2,0x7f,sizeof(f2));
	f1[1][1]=b[1][1];
	f2[1][1]=c[1][1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=1||j!=1)
			{
				if(f1[i][j-1]<f1[i-1][j])
				{
					f1[i][j]=f1[i][j-1]+b[i][j];
					from1[i][j]=0;
				}
				else
				{
					f1[i][j]=f1[i-1][j]+b[i][j];
					from1[i][j]=1;
				}
				if(f2[i][j-1]<f2[i-1][j])
				{
					f2[i][j]=f2[i][j-1]+c[i][j];
					from2[i][j]=0;
				}
				else
				{
					f2[i][j]=f2[i-1][j]+c[i][j];
					from2[i][j]=1;
				}
			}
	if(zero&&min(f1[n][n],f2[n][n]))
	{
		printf("1\n");
		for(int i=1;i<posx;i++)
			putchar('D');
		for(int i=1;i<n;i++)
			putchar('R');
		for(int i=posx;i<n;i++)
			putchar('D');
		puts("");
	}
	else
	{
		printf("%d\n",min(f1[n][n],f2[n][n]));
		if(f1[n][n]<f2[n][n])
			print1(n,n);
		else
			print2(n,n);
		puts("");
	}
	return 0;
}