#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005];
double f[100005],g[100005];
int c[15][15],h[15][15];
int main()
{
	int ct=0;
	for(int i=10;i>=1;i--)
	{
		if(i%2==0)
		{
			for(int j=1;j<=10;j++)
				c[i][j]=++ct;
		}
		else
		{
			for(int j=10;j>0;j--)
				c[i][j]=++ct;
		}
	}
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
		{
			scanf("%d",&h[i][j]);
			if(h[i][j])
			{
				a[c[i][j]]=c[i-h[i][j]][j];
			}
		}
	f[100]=g[100]=0;
	for(int i=99;i>=1;i--)
	{
		int nw=6;
		for(int j=6;j>0;j--)
		{
			if(i+j>100) nw--;
			f[i]+=g[i+j]/nw;
		}
		f[i]+=6.0/nw;
		g[i]=f[i];
		//printf("i=%d,f=%Lf\n",i,f[i]);
		if(a[i]&&g[i]>f[a[i]]) g[i]=f[a[i]];
	}
	printf("%.10lf",f[1]);
	return 0;
}