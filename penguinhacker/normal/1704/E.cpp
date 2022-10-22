#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1000, M=998244353;
int n, m, a[mxN], in[mxN], a2[mxN];
long double actual[mxN], actual2[mxN];
vector<int> adj[mxN];
bool vis[mxN];

void solve() {
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		actual[i]=a[i];
		adj[i].clear();
		vis[i]=in[i]=0;
	}
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		++in[v];
	}
	for (int rep=0; rep<n+1; ++rep) {
		if (*max_element(a, a+n)==0) {
			cout << rep << "\n";
			return;
		}
		for (int i=0; i<n; ++i)
			a2[i]=max(a[i]-1, 0);
		for (int i=0; i<n; ++i)
			if (a[i])
				for (int j : adj[i])
					++a2[j];
		memcpy(a, a2, 4*n);
	}
	int ans=n+1;
	for (int rep=0; rep<n; ++rep) {
		int ind=-1;
		for (int i=0; i<n; ++i)
			if (!vis[i]&&!in[i]&&(ind==-1||actual[i]<actual[ind]))
				ind=i;
		for (int i=0; i<n; ++i) {
			a2[i]=(a[i]-a[ind]+M)%M;
			actual2[i]=actual[i]-actual[ind];
		}
		for (int i=0; i<n; ++i)
			if (!vis[i])
				for (int j : adj[i]) {
					a2[j]=(a2[j]+a[ind])%M;
					actual2[j]+=actual[ind];
				}
		vis[ind]=1;
		ans=(ans+a[ind])%M;
		for (int i : adj[ind])
			--in[i];
		for (int i=0; i<n; ++i) {
			a[i]=a2[i];
			actual[i]=actual2[i];
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}