#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int a[4][210],now[4],n[4],ans,f[210][210][210];
void update(int&x,int y){if(y>x)x=y;}
int main()
{
	rep(i,3)scanf("%d",&n[i]);
	rep(i,3)rep(j,n[i])scanf("%d",&a[i][j]);
	rep(i,3)sort(a[i]+1,a[i]+n[i]+1,greater<int>());
	for(int i=0;i<=n[1];i++)
	for(int j=0;j<=n[2];j++)
	for(int k=0;k<=n[3];k++)
	{
		if(i&&j)update(f[i][j][k],f[i-1][j-1][k]+a[1][i]*a[2][j]);
		if(i&&k)update(f[i][j][k],f[i-1][j][k-1]+a[1][i]*a[3][k]);
		if(j&&k)update(f[i][j][k],f[i][j-1][k-1]+a[2][j]*a[3][k]);
		ans=max(ans,f[i][j][k]);
	}
	printf("%d\n",ans);
    return 0;
}