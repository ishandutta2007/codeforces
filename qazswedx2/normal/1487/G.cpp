#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int n,a[26],f[405][205][205][3][3],g[405][405];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<26;i++)
		scanf("%d",&a[i]);
	f[0][0][0][0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j*2-2<=i;j++)
			for(int k=0;j+k<=i&&k*2-2<=i;k++)
				for(int u=0;u<=2;u++)
					for(int v=0;v<=2;v++)
						for(int w=0;w<=2;w++)
						{
							if(w==0)
							{
								f[i][j][k][v][w]=addmod(f[i][j][k][v][w]+1ll*f[i-1][j][k][u][v]*(24-(!u)+(i<=2))%mod);
							}
							if(w==1&&j&&u!=1)
								f[i][j][k][v][w]=addmod(f[i][j][k][v][w]+f[i-1][j-1][k][u][v]);
							if(w==2&&k&&u!=2)
								f[i][j][k][v][w]=addmod(f[i][j][k][v][w]+f[i-1][j][k-1][u][v]);
						}
	for(int i=0;i*2-2<=n;i++)
		for(int j=0;j*2-2<=n;j++)
			for(int u=0;u<=2;u++)
				for(int v=0;v<=2;v++)
					g[i][j]=addmod(g[i][j]+f[n][i][j][u][v]);
	for(int i=n;i>=0;i--)
		for(int j=n;j>=0;j--)
			g[i][j]=(1ll*g[i][j]+g[i][j+1]+g[i+1][j]-g[i+1][j+1]+mod)%mod;
	/*for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			printf("%d ",g[i][j]);
		printf("\n");
	}*/
	int ans=g[0][0];
	for(int i=0;i<26;i++)
		ans=submod(ans-g[a[i]+1][0]);
	for(int i=0;i<26;i++)
		for(int j=i+1;j<26;j++)
			ans=addmod(ans+g[a[i]+1][a[j]+1]);
	printf("%d\n",ans);
	return 0;
}