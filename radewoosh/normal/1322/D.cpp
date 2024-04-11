#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int nax=4017;

int n, m;

int agr[nax], kosz[nax], zys[nax];
ll dpn[nax][nax], sum[nax];

void maxi(ll &a, ll b)
{
	a=max(a, b);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d", &agr[i]);
	for (int i=1; i<=n; i++)
		scanf("%d", &kosz[i]);
	for (int i=1; i<=n+m; i++)
	{
		scanf("%d", &zys[i]);
		sum[i]=sum[i-1]+zys[i];
	}
	for (int i=1; i<nax; i++)
		for (int j=1; j<=n; j++)
			dpn[i][j]=-1e18;
	for (int i=n; i; i--)
	{
		int x=agr[i];
		for (int j=n-1; j>=0; j--)
			maxi(dpn[x][j+1], dpn[x][j]+sum[x+__builtin_ctz(j+1)]-sum[x-1]-kosz[i]);
		for (int j=x; j+1<nax; j++)
			for (int l=0; l<=(n>>min(12, j-x)); l++)
				maxi(dpn[j+1][l>>1], dpn[j][l]);
	}
	printf("%lld\n", dpn[nax-1][0]);
	return 0;
}