#include<bits/stdc++.h>
using namespace std;

int n,m,a[501][501],x;

int main()
{
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) scanf("%d",&a[i][j]);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) scanf("%d",&x),a[i][j]^=x;
	for (int i=1; i<n; i++)
		for (int j=1; j<m; j++)
			if (a[i][j]) a[i+1][j]^=1,a[i][j+1]^=1,a[i+1][j+1]^=1;
	for (int i=1; i<=n; i++) if (a[i][m]) return puts("No"),0;
	for (int i=1; i<=m; i++) if (a[n][i]) return puts("No"),0;
	return puts("Yes"),0;
}