#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;

struct dsu {
	int fa[N+N];
	void send(int n) {
		for (int i=1;i<=n+n;i++) {
			fa[i]=i;
		}
	}
	int find(int x) {
		return x==fa[x]?x:fa[x]=find(fa[x]);
	}
	bool check(int x,int y) {
		return find(x)==find(y);
	}
	void merge(int x,int y) {
		fa[find(x)]=find(y);
	}
}d;
int n,a[N][N],col[N];
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			cin>>a[i][j];
		}
	}
	d.send(n);
	for (int i=1;i<=n;i++) {
		for (int j=i+1;j<=n;j++) {
			if (a[i][j]>a[j][i]&&!d.check(i,j)) {
				d.merge(i,j+n);
				d.merge(i+n,j);
			}
			if (a[i][j]<a[j][i]&&!d.check(i,j+n)) {
				d.merge(i,j);
				d.merge(i+n,j+n);
			}
		}
	}
	for (int i=1;i<=n;i++) {
		int x=d.find(i);
		if (i!=x) {
			col[i]=x<=n?col[x]:!col[x-n];
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			cout<<(col[i]^col[j]?a[j][i]:a[i][j])<<" \n"[j==n];
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}