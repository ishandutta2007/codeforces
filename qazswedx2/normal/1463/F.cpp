#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x,y,f[2][5000005],m=22,c[105];
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=x+y;i++)
		c[i]=(n+x+y-i)/(x+y);
	for(int i=1;i<=x+y;i++)
	{
		int u=i%2;
		memset(f[u],0,sizeof(f[u]));
		for(int j=0;j<(1<<m);j++)
		{
			int k=(j<<1)&((1<<m)-1);
			f[u][k]=max(f[u][k],f[u^1][j]);
			if(!(j&(1<<(x-1)))&&!(j&(1<<(y-1)))) f[u][k+1]=max(f[u][k+1],f[u^1][j]+c[i]);
		}
	}
	int u=(x+y)%2,ans=0;
	for(int j=0;j<(1<<m);j++)
		if(f[u][j]>ans)
			ans=f[u][j];
	printf("%d\n",ans);
	return 0;
}