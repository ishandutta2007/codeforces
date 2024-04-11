#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=205;

struct dsu {
	int fa[N];
	void send(int n) {
		for (int i=1;i<=n;i++) {
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
bool vis[N];
int n,p[N],np[N],to[N],from[N],col[N];
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>p[i];
		from[i]=to[i]=vis[i]=0;
	}
	int cntcol=0;
	for (int i=1;i<=n;i++) {
		if (vis[i]) {
			continue;
		}
		cntcol++;
		vector<int>tmp;
		for (int j=i;!vis[j];j=p[j]) {
			vis[j]=1;
			col[j]=cntcol;
			tmp.emplace_back(j);
		}
		for (int i=0;i<(int)tmp.size();i++) {
			to[tmp[i]]=tmp[(i+1)%tmp.size()];
			from[tmp[(i+1)%tmp.size()]]=tmp[i];
		}
	}
	d.send(cntcol);
	for (int i=1;i<n;i++) {
		if (d.merge(col[i],col[i+1])) {
			int f0=from[i],f1=from[i+1];
			to[f1]=i,from[i]=f1;
			to[f0]=i+1,from[i+1]=f0;
		}
	}
	vector<int>res;
	for (int i=1;(int)res.size()<n;i=from[i]) {
		res.emplace_back(i);
	}
	for (int i:res) {
		cout<<i<<" ";
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