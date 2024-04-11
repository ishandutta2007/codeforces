#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int mod=1e9+7;
int n,m,f[15][1005][1005],g[15][1005][1005],tans;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int main()
{
	scanf("%d%d",&n,&m);
	f[0][1][n]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			for(int k=n;k>=j;k--)
				f[i][j][k]=addmod(submod(f[i-1][j][k]-f[i][j-1][k+1])+addmod(f[i][j-1][k]+f[i][j][k+1]));
	}
	for(int j=1;j<=n;j++)
		for(int k=n;k>=j;k--)
			tans=addmod(tans+f[m][j][k]);
	printf("%d",tans);
	return 0;
}