#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, p[mxN], a[mxN], b[mxN], r, ans[mxN];
vector<int> adj[mxN];
ll d[mxN];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=0; i<n; ++i) {
		cin >> p[i], --p[i];
		if (p[i]==i)
			r=i;
		else
			adj[p[i]].push_back(i);
	}
	for (int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		b[a[i]]=i;
	}
	for (int i=0; i<n; ++i)
		if (i^r&&b[i]<b[p[i]]) {
			cout << "-1\n";
			return;
		}
	assert(a[0]==r);
	ll cur=0;
	ans[r]=0;
	memset(d, 0, 8*n);
	for (int i=1; i<n; ++i) {
		assert((++cur)>d[p[a[i]]]);
		ans[a[i]]=cur-d[p[a[i]]];
		d[a[i]]=cur;
	}
	for (int i=0; i<n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
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