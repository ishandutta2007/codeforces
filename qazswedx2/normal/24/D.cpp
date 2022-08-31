#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
double g[1005][1005],f[1005][1005];
void gauss(int x)
{
	for(int i=1;i<m;i++)
	{
		g[i][i+1]/=g[i][i];
		g[i][m+1]/=g[i][i];
		g[i][i]=1;
		double mul=g[i+1][i];
		g[i+1][i]-=g[i][i]*mul;
		g[i+1][i+1]-=g[i][i+1]*mul;
		g[i+1][m+1]-=g[i][m+1]*mul;
	}
	f[x][m]=g[m][m+1]/g[m][m];
	for(int i=m-1;i>0;i--)
	{
		f[x][i]=g[i][m+1]-g[i][i+1]*f[x][i+1];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%.10lf",(double)(n-x)*2);
		return 0;
	}
	for(int i=n-1;i>0;i--)
	{
		g[1][1]=2.0/3;
		g[1][2]=-1.0/3;
		g[1][m+1]=1.0/3*f[i+1][1]+1;
		g[m][m]=2.0/3;
		g[m][m-1]=-1.0/3;
		g[m][m+1]=1.0/3*f[i+1][m]+1;
		for(int j=2;j<m;j++)
		{
			g[j][j]=3.0/4;
			g[j][j-1]=-1.0/4;
			g[j][j+1]=-1.0/4;
			g[j][m+1]=1.0/4*f[i+1][j]+1;
		}
		gauss(i);
	}
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%.10lf",f[x][y]);
	return 0;
}