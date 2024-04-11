#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

bool vis[N];
int n,m,p[N],id[N],deg[N];
vector<pair<int,int>>e[N];
vector<int>g[N],ans;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>p[i];
	}
	for (int i=1;i<=n;i++) {
		if (vis[i]) {
			continue;
		}
		int cnt=0;
		for (int j=i;!vis[j];j=p[j]) {
			vis[j]=1;
			id[j]=++cnt;
		}
	}
	for (int i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		e[u].emplace_back(v,i);
		e[v].emplace_back(u,i);
	}
	for (int i=1;i<=n;i++) {
		sort(e[i].begin(),e[i].end(),[&](pair<int,int>x,pair<int,int>y) {
			return (id[x.first]-id[i]+n)%n<(id[y.first]-id[i]+n)%n;
		});
		for (int j=0;j+1<(int)e[i].size();j++) {
			g[e[i][j].second].emplace_back(e[i][j+1].second);
			deg[e[i][j+1].second]++;
		}
	}
	queue<int>q;
	for (int i=1;i<=m;i++) {
		if (!deg[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int now=q.front(); q.pop();
		ans.emplace_back(now);
		for (int to:g[now]) {
			if (!--deg[to]) {
				q.push(to);
			}
		}
	}
	for (int i:ans) {
		cout<<i<<" ";
	}
	
	return 0;
}