#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

bool vis[N];
int n,m,deep[N],fa[N],ID[N],u[N],v[N],tot[N];
vector<pair<int,int>>e[N];
vector<int>T;
void dfs(int now,int father) {
	vis[now]=1;
	deep[now]=deep[fa[now]=father]+1;
	for (auto [to,id]:e[now]) {
		if (to==father) {
			continue;
		}
		if (vis[to]) {
			if (deep[to]<deep[now]) {
				T.emplace_back(id);
			}
			continue;
		}
		ID[to]=id;
		dfs(to,now);
	}
}
void work() {
	cin>>n>>m;
	T.clear();
	for (int i=1;i<=n;i++) {
		e[i].clear();
		tot[i]=vis[i]=0;
	}
	for (int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		e[u].emplace_back(v,i);
		e[v].emplace_back(u,i);
		::u[i]=u,::v[i]=v;
	}
	dfs(1,0);
	vector<int>ans(m);
	for (int i:T) {
		ans[i]=1;
		tot[u[i]]++,tot[v[i]]++;
	}
	int cnt=0;
	for (int i=1;i<=n;i++) {
		cnt+=tot[i]==2;
	}
	if (cnt==3) {
		sort(T.begin(),T.end(),[&](int x,int y){
			return abs(deep[u[x]]-deep[v[x]])>abs(deep[u[y]]-deep[v[y]]);
		});
		int x=u[T[0]],y=v[T[0]];
		if (deep[x]<deep[y]) {
			swap(x,y);
		}
		ans[T[0]]=0;
		ans[ID[x]]=1;
		while (fa[x]!=y) {
			x=fa[x];
		}
		ans[ID[x]]=1;
	}
	for (int i:ans) {
		cout<<i;
	}
	cout<<"\n";
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