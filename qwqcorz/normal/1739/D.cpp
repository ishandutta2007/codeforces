#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

int n,k,d[N],tot=0;
vector<int>e[N];
void dfs(int now,int m) {
	d[now]=0;
	for (int to:e[now]) {
		dfs(to,m);
		if (d[to]+1==m) {
			tot+=now>1;
		} else {
			d[now]=max(d[now],d[to]+1);
		}
	}
}
bool check(int m) {
	tot=0;
	dfs(1,m);
	return tot<=k;
}
void work() {
	cin>>n>>k;
	for (int i=2;i<=n;i++) {
		int fa;
		cin>>fa;
		e[fa].emplace_back(i);
	}
	int l=1,r=n;
	while (l<=r) {
		int mid=(l+r)/2;
		if (check(mid)) {
			r=mid-1;
		} else {
			l=mid+1;
		}
	}
	cout<<l<<"\n";
	for (int i=1;i<=n;i++) {
		e[i].clear();
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