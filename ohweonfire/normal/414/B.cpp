#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
LL c[40][2005];
LL f[40][2005];
const LL MOD=1000000007;
int main()
{
 	memset(c,0,sizeof(c));
 	memset(f,0,sizeof(f));
 	for(int i=0;i<2005;i++)c[0][i]=1;
 	for(int i=1;i<2005;i++)for(int j=1;j<=i&&j<=20;j++)c[j][i]=(c[j-1][i-1]+c[j][i-1])%MOD;
 	f[0][1]=1;
 	for(int i=0;i<=15;i++)for(int j=1;j<2005;j++)if(f[i][j])
 	{
	 		for(int t=j*2;t<2005;t+=j)f[i+1][t]=(f[i+1][t]+f[i][j])%MOD;
	}
	int n,k;
	scanf("%d%d",&n,&k);
	LL res=0;
	for(int i=0;i<=15;i++)for(int j=1;j<=n;j++)res=(res+c[i][k]*f[i][j]%MOD)%MOD;
	printf("%d\n",res);
	return 0;
}