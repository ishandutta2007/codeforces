#include<bits/stdc++.h>

using namespace std;

#define N 3200

int n,m;
long double a[N][N],g[N],h[N][N],ans;

void calc(int x){
	for (int i=n;i>=1;--i)
		h[x][i]=h[x][i-1]*a[i][x];
	h[x][0]=0;
	for (int i=1;i<=n;++i)
		h[x][i]+=h[x][i-1]*(1-a[i][x]);
	g[x]=h[x][n];
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j){
			scanf("%Lf",&a[i][j]);
			a[i][j]/=1000;
		}
	for (int i=1;i<=m;++i){
		for (int j=0;j<=n;++j) h[i][j]=1;
		calc(i);
	}
	for (int i=1;i<=n;++i){
		int mx=0;
		for (int j=1;j<=m;++j) if (g[j]>g[mx]) mx=j;
		ans+=g[mx]; calc(mx);
	}
	printf("%.12Lf\n",ans);
	
	return 0;
}