#include<bits/stdc++.h>

using namespace std;

#define N 1050

int n,m,a[N][N],b[N],f[N][N],g[N][N],F[N],G[N];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j) scanf("%d",a[i]+j);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j) b[j]=a[i][j];
		sort(b+1,b+m+1);
		int k; b[k=1]=b[1];
		for (int j=2;j<=m;++j) if (b[j]!=b[j-1]) b[++k]=b[j];
		for (int j=1;j<=m;++j) f[i][j]=lower_bound(b+1,b+k+1,a[i][j])-b;
		F[i]=k;
	}
	for (int i=1;i<=m;++i){
		for (int j=1;j<=n;++j) b[j]=a[j][i];
		sort(b+1,b+n+1);
		int k; b[k=1]=b[1];
		for (int j=2;j<=n;++j) if (b[j]!=b[j-1]) b[++k]=b[j];
		for (int j=1;j<=n;++j) g[j][i]=lower_bound(b+1,b+k+1,a[j][i])-b;
		G[i]=k;
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			printf(j==m?"%d\n":"%d ",max(F[i]-f[i][j],G[j]-g[i][j])+max(f[i][j],g[i][j]));
	
	return 0;
}