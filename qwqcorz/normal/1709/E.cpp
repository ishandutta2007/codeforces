#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

int n,a[N],s[N],ans=0;
vector<int>e[N];
set<int>F[N];
bool merge(set<int>&a,set<int>&b,int x) {
	if (a.size()<b.size()) {
		swap(a,b);
	}
	for (int i:b) {
		if (a.find(i^x)!=a.end()) {
			return false;
		}
	}
	for (int i:b) {
		a.insert(i);
	}
	b=set<int>();
	return true;
}
void dfs(int now,int father) {
	s[now]=s[father]^a[now];
	F[now].insert(s[now]);
	bool flag=0;
	for (int to:e[now]) {
		if (to==father) {
			continue;
		}
		dfs(to,now);
		if (flag) {
			continue;
		}
		if (!merge(F[now],F[to],a[now])) {
			flag=1;
			ans++;
		}
	}
	if (flag) {
		F[now]=set<int>();
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int i=1;i<n;i++) {
		int x,y;
		cin>>x>>y;
		e[x].emplace_back(y);
		e[y].emplace_back(x);
	}
	dfs(1,0);
	cout<<ans<<"\n";
	
	return 0;
}