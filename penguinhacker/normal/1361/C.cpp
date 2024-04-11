#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1<<20;
int n, a[mxN], eu[mxN], ev[mxN];
vector<int> adj[mxN];
bool vis[mxN];
vector<int> ans;

//bool flag = 0;

void dfs(int u) {
	while(adj[u].size()) {
		int e=adj[u].back();
		adj[u].pop_back();
		if (vis[e])
			continue;
		vis[e]=1;
		dfs(eu[e]^ev[e]^u);
		ans.push_back(u==eu[e]?2*e+1:2*e);
		ans.push_back(u==eu[e]?2*e:2*e+1);
		//if (flag) cout << u << " " << (eu[e]^ev[e]^u) << " " << e << endl;
	}
}

bool ok(int x) {
	for (int i=0; i<1<<x; ++i)
		adj[i].clear();
	for (int i=0; i<n; ++i) {
		eu[i]=a[2*i]&(1<<x)-1;
		ev[i]=a[2*i+1]&(1<<x)-1;
		adj[eu[i]].push_back(i);
		adj[ev[i]].push_back(i);
		vis[i]=0;
	}
	int s=-1;
	for (int i=0; i<1<<x; ++i) {
		if (adj[i].size()%2)
			return 0;
		if (adj[i].size())
			s=i;
	}
	assert(s!=-1);
	ans.clear();
	dfs(s);
	return ans.size()==2*n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<2*n; ++i)
		cin >> a[i];
	int lb=0, rb=20;
	while(lb<rb) {
		int mid=(lb+rb+1)/2;
		if (ok(mid))
			lb=mid;
		else
			rb=mid-1;
	}
	//flag = 1;
	assert(ok(lb));
	cout << lb << "\n";
	for (int i=0; i<n; ++i) {
		assert(abs(ans[2*i]-ans[2*i+1])==1);
		assert((a[ans[2*i+1]]&1<<lb-1)==(a[ans[(2*i+2)%(2*n)]]&1<<lb-1));
	}
	for (int i : ans)
		cout << i+1 << " ";
	return 0;
}