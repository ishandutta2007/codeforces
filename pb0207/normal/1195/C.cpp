#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int n;

ll a[2][N],f[2][N],g[2][N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[0][i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[1][i]);
	for(int i=1;i<=n;i++)
	{
		f[0][i]=g[1][i-1]+a[0][i];
		f[1][i]=g[0][i-1]+a[1][i];
		g[0][i]=max(g[0][i-1],f[0][i]);
		g[1][i]=max(g[1][i-1],f[1][i]);
	}
	printf("%lld",max(g[0][n],g[1][n]));
}