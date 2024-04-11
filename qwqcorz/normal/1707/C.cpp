#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

struct dsu {
	int fa[N];
	void send(int n) {
		for (int i=1;i<=n;i++) {
			fa[i]=i;
		}
	}
	int find(int x) {
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	bool merge(int x,int y) {
		x=find(x),y=find(y);
		if (x==y) {
			return 0;
		}
		fa[x]=y;
		return 1;
	}
}d;
int n,m,st[N],ed[N],cntdfn=0,c[N],fa[N][17];
vector<int>e[N];
void dfs(int now,int father) {
	fa[now][0]=father;
	for (int i=1;i<17;i++) {
		fa[now][i]=fa[fa[now][i-1]][i-1];
		if (fa[now][i]==0) {
			break;
		}
	}
	st[now]=++cntdfn;
	for (int to:e[now]) {
		if (to==father) {
			continue;
		}
		dfs(to,now);
	}
	ed[now]=cntdfn;
}
bool have(int x,int y) {
	return st[x]<=st[y]&&ed[y]<=ed[x];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	d.send(n);
	vector<pair<int,int>>g;
	for (int i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		if (d.merge(u,v)) {
			e[u].push_back(v);
			e[v].push_back(u);
		} else {
			g.emplace_back(u,v);
		}
	}
	dfs(1,0);
	for (auto [x,y]:g) {
		if (st[x]>st[y]) {
			swap(x,y);
		}
		if (have(x,y)) {
			int k=y;
			for (int i=16;i>=0;i--) {
				if (st[x]<st[fa[k][i]]) {
					k=fa[k][i];
				}
			}
			c[1]++;
			c[st[k]]--;
			c[st[y]]++;
			c[ed[y]+1]--;
			c[ed[k]+1]++;
		} else {
			c[st[x]]++,c[ed[x]+1]--;
			c[st[y]]++,c[ed[y]+1]--;
		}
	}
	for (int i=1;i<=n;i++) {
		c[i]+=c[i-1];
	}
	for (int i=1;i<=n;i++) {
		cout<<"01"[c[st[i]]==(int)g.size()];
	}
	
	return 0;
}