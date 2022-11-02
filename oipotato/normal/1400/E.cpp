#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int a[5010],f[5010][5010],n;
void update(int&x,int y){if(y<x)x=y;}
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n+1)rep(j,n+1)f[i-1][j-1]=n;
	f[0][0]=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<=n;j++)
	if(j>=a[i+1])update(f[i+1][a[i+1]],f[i][j]);
	else
	{
		update(f[i+1][j],f[i][j]+1);
		if(a[i+1]<=n)update(f[i+1][a[i+1]],f[i][j]+a[i+1]-j);
	}
	int ans=n;
	rep(i,n+1)ans=min(ans,f[n][i-1]);
	printf("%d\n",ans);
    return 0;
}