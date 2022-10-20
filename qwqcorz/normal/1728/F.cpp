#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;

int n,a[N],cnt=0,y[N];
ll b[N*N];
bool vis[N*N];
vector<int>e[N*N];
bool dfs(int now) {
	if (vis[now]) {
		return 0;
	}
	vis[now]=1;
	for (int to:e[now]) {
		if (!y[to]||dfs(y[to])) {
			y[to]=now;
			return 1;
		}
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		for (int j=1;j<=n;j++) {
			b[++cnt]=1LL*a[i]*j;
		}
	}
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			int k=lower_bound(b+1,b+1+cnt,1LL*a[i]*j)-b;
			e[k].push_back(i);
		}
	}
	ll ans=0;
	for (int i=1;i<=cnt;i++) {
		if (dfs(i)) {
			ans+=b[i];
			memset(vis,0,sizeof(vis));
		}
	}
	cout<<ans<<"\n";
	
	return 0;
}