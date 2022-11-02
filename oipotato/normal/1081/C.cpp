#include<cstdio>
using namespace std;
const int MOD=998244353;
int f[2010][2010],n,m,k;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	f[1][0]=m;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=k;j++)f[i][j]=f[i-1][j];
		for(int j=1;j<=k;j++)f[i][j]=(f[i][j]+1ll*(m-1)*f[i-1][j-1])%MOD;
	}
	printf("%d\n",f[n][k]);
	return 0;
}