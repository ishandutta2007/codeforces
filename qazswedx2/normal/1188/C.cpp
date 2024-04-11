#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
int n,m,a[100005],f[1005][1005],g[1005][1005],pn=1e5;
int solve(int x)
{
	int nw=0;
	for(int i=1;i<=n;i++)
	{
		while(nw+1<i&&a[i]-a[nw+1]>=x) nw++;
		for(int j=1;j<=m;j++)
		{
			f[i][j]=addmod((j==1)+g[nw][j-1]);
			g[i][j]=addmod(f[i][j]+g[i-1][j]);
		}
	}
	return g[n][m];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i*(m-1)<=pn;i++)
		ans=addmod(ans+solve(i));
	printf("%d\n",ans);
	return 0;
}