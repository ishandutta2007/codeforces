#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;

struct dsu {
	int fa[30];
	void send(int n) {
		for (int i=0;i<n;i++) {
			fa[i]=i;
		}
	}
	int find(int x) {
		return x==fa[x]?x:fa[x]=find(fa[x]);
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
int n,a[N],preOR[N],sufOR[N];
vector<pair<int,int>>pre[N],suf[N];
void work() {
	int ans=0;
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]==0) {
			ans++;
			a[i]++;
		}
	}
	d.send(30);
	pre[0]=vector<pair<int,int>>(),preOR[0]=0;
	for (int i=1;i<=n;i++) {
		pre[i]=pre[i-1];
		preOR[i]=preOR[i-1]|a[i];
		for (int j=0,lst=-1;j<30;j++) {
			if (a[i]>>j&1) {
				if (~lst) {
					if (d.merge(lst,j)) {
						pre[i].emplace_back(lst,j);
					}
				}
				lst=j;
			}
		}
	}
	d.send(30);
	suf[n+1]=vector<pair<int,int>>(),sufOR[n+1]=0;
	for (int i=n;i>=1;i--) {
		suf[i]=suf[i+1];
		sufOR[i]=sufOR[i+1]|a[i];
		for (int j=0,lst=-1;j<30;j++) {
			if (a[i]>>j&1) {
				if (~lst) {
					if (d.merge(lst,j)) {
						suf[i].emplace_back(lst,j);
					}
				}
				lst=j;
			}
		}
	}
	vector<int>tmp;
	for (int i=0;i<30;i++) {
		if (preOR[n]>>i&1) {
			tmp.emplace_back(d.find(i));
		}
	}
	bool ok=1;
	for (int i:tmp) {
		ok&=i==tmp[0];
	}
	if (ok) {
		cout<<ans<<"\n";
		for (int i=1;i<=n;i++) {
			cout<<a[i]<<" \n"[i==n];
		}
		return;
	}
	auto check=[&](int x,int y) {
		vector<vector<int>>e(30);
		for (auto [u,v]:pre[x-1]) {
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		for (auto [u,v]:suf[x+1]) {
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		for (int i=0,lst=-1;i<30;i++) {
			if (y>>i&1) {
				if (~lst) {
					e[lst].emplace_back(i);
					e[i].emplace_back(lst);
				}
				lst=i;
			}
		}
		int OR=preOR[x-1]|sufOR[x+1]|y,siz=__builtin_popcount(OR);
		vector<bool>vis(30);
		auto dfs=[&](auto &self,int x) {
			if (vis[x]) {
				return;
			}
			siz--;
			vis[x]=1;
			for (int to:e[x]) {
				self(self,to);
			}
		};
		for (int i=0;i<30;i++) {
			if (OR>>i&1) {
				dfs(dfs,i);
				return siz==0;
			}
		}
		assert(false);
	};
	for (int i=1;i<=n;i++) {
		if (a[i]>1&&check(i,a[i]-1)) {
			a[i]--;
			cout<<ans+1<<"\n";
			for (int i=1;i<=n;i++) {
				cout<<a[i]<<" \n"[i==n];
			}
			return;
		}
		if (check(i,a[i]+1)) {
			a[i]++;
			cout<<ans+1<<"\n";
			for (int i=1;i<=n;i++) {
				cout<<a[i]<<" \n"[i==n];
			}
			return;
		}
	}
	int mx=0,id=0;
	for (int i=1;i<=n;i++) {
		if (mx<(a[i]&-a[i])) {
			mx=a[i]&-a[i];
			id=i;
		}
	}
	a[id]--;
	int mx0=0,id0=0;
	for (int i=1;i<=n;i++) {
		if (i!=id&&mx0<(a[i]&-a[i])) {
			mx0=a[i]&-a[i];
			id0=i;
		}
	}
	a[id0]++;
	cout<<ans+2<<"\n";
	for (int i=1;i<=n;i++) {
		cout<<a[i]<<" \n"[i==n];
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