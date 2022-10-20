#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e4+5;
const int K=15;
const int V=N*K*2;

vector<int>e[V];
int n,m,k,geq[N][K],les[N][K];
void add_edge(int u,int v) {
	e[u].emplace_back(v);
}
bool vis[V];
int low[V],dfn[V],cntdfn,st[V],top,col[V],cntcol;
void tarjan(int now) {
	low[now]=dfn[now]=++cntdfn;
	st[++top]=now;
	vis[now]=1;
	for (int to:e[now]) {
		if (!dfn[to]) {
			tarjan(to);
			low[now]=min(low[now],low[to]);
		} else {
			if (vis[to]) {
				low[now]=min(low[now],dfn[to]);
			}
		}
	}
	if (low[now]==dfn[now]) {
		int x,c=++cntcol;
		do {
			x=st[top--];
			col[x]=c;
			vis[x]=0;
		}while (x!=now);
	}
}
int ans[N];
void work() {
	int cnt=0;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++) {
		for (int j=2;j<=k;j++) {
			geq[i][j]=++cnt;
			les[i][j]=++cnt;
		}
		geq[i][1]=geq[i][k+1]=0;
		les[i][1]=les[i][k+1]=0;
	}
	for (int i=0;i<=cnt;i++) {
		e[i].clear();
		low[i]=dfn[i]=col[i]=vis[i]=0;
	}
	cntcol=cntdfn=top=0;
	for (int i=1;i<=cnt;i++) {
		add_edge(0,i);
	}
	for (int i=1;i<=n;i++) {
		for (int j=3;j<=k;j++) {
			add_edge(geq[i][j],geq[i][j-1]);
			add_edge(les[i][j-1],les[i][j]);
		}
	}
	for (int i=1;i<n;i++) {
		for (int j=2;j<=k;j++) {
			add_edge(geq[i][j],geq[i+1][j]);
			add_edge(les[i+1][j],les[i][j]);
		}
	}
	for (int i=1;i<=m;i++) {
		int opt;
		cin>>opt;
		if (opt==1) {
			int x,y;
			cin>>x>>y;
			add_edge(geq[x][y],geq[x][y+1]);
			add_edge(les[x][y+1],les[x][y]);
		}
		if (opt==2) {
			int x,y,w;
			cin>>x>>y>>w;
			for (int i=2;i<=k;i++) {
				if (i+1>w) {
					add_edge(geq[x][i],0);
					add_edge(geq[y][i],0);
				} else {
					if (i+k<=w) {
						continue;
					}
					add_edge(geq[x][i],les[y][w-i+1]);
					add_edge(geq[y][i],les[x][w-i+1]);
				}
			}
		}
		if (opt==3) {
			int x,y,w;
			cin>>x>>y>>w;
			for (int i=2;i<=k;i++) {
				if (i-1+k<w) {
					add_edge(les[x][i],0);
					add_edge(les[y][i],0);
				} else {
					if (i-1+1>=w) {
						continue;
					}
					add_edge(les[x][i],geq[y][w-(i-1)]);
					add_edge(les[y][i],geq[x][w-(i-1)]);
				}
			}
		}
	}
	tarjan(0);
	for (int i=1;i<=n;i++) {
		for (int j=k;j>=2;j--) {
			if (col[geq[i][j]]==col[les[i][j]]) {
				cout<<"-1\n";
				return;
			}
		}
		for (int j=k;j>=1;j--) {
			if (j==1||col[geq[i][j]]<col[les[i][j]]) {
				ans[i]=j;
				break;
			}
		}
	}
	for (int i=1;i<=n;i++) {
		cout<<ans[i]<<" \n"[i==n];
	}
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