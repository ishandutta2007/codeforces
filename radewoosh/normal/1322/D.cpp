#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int nax=4017;
const ll inf=1e18;
const int d=12;

int n, m;

int agr[nax];
int kosz[nax];
int zys[nax];

ll dpn[nax][nax];

void maxi(ll &a, ll b)
{
	a=max(a, b);
}

ll dodaj(int a, int b)
{
	b++;
	ll ret=0;
	for (int i=0; 1; i++)
	{
		ret+=zys[a+i];
		if (b&(1<<i))
			break;
	}
	return ret;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d", &agr[i]);
	for (int i=1; i<=n; i++)
		scanf("%d", &kosz[i]);
	for (int i=1; i<=n+m; i++)
		scanf("%d", &zys[i]);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			dpn[i][j]=-inf;
	for (int i=n; i; i--)
	{
		for (int j=n-1; j>=0; j--)
			maxi(dpn[agr[i]][j+1], dpn[agr[i]][j]+dodaj(agr[i], j)-kosz[i]);
		for (int j=agr[i]; j+1<nax; j++)
			for (int l=0; l<=(n>>min(d, j-agr[i])); l++)
				maxi(dpn[j+1][l>>1], dpn[j][l]);
	}
	printf("%lld\n", dpn[nax-1][0]);
	return 0;
}