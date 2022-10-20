#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const ll inf=1e18+7;

int n,m;
ll f[N][N],g[N][N];
void work() {
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			f[i][j]=inf;
			g[i][j]=i==j?0:inf;
		}
	}
	for (int i=1;i<=m;i++) {
		ll u,v,w;
		cin>>u>>v>>w;
		f[u][v]=min(f[u][v],w);
		f[v][u]=min(f[v][u],w);
		g[u][v]=g[v][u]=1;
	}
	for (int k=1;k<=n;k++) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	ll ans=inf;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			if (f[i][j]<inf) {
				ans=min(ans,f[i][j]*(g[1][i]+g[n][j]+1));
				for (int k=1;k<=n;k++) {
					ans=min(ans,f[i][j]*(g[1][k]+g[k][n]+1+min(g[i][k],g[j][k])+1));
				}
			}
		}
	}
	cout<<ans<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin>>T;
	while (T--) {
		work();
	} 
	
	return 0;
}