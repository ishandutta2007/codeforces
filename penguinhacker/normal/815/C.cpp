#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5000;
const ll INF=1e18;
int n, b, c[mxN], d[mxN];
vector<int> adj[mxN];

vector<ar<ll, 2>> dfs(int u=0) {
	vector<ar<ll, 2>> r={{0, INF}, {c[u], c[u]-d[u]}};
	//cout << u << endl;
	for (int v : adj[u]) {
		vector<ar<ll, 2>> cur=dfs(v);
		vector<ar<ll, 2>> nr(r.size()+cur.size()-1, {INF, INF});
		for (int i=0; i<r.size(); ++i) {
			for (int j=0; j<cur.size(); ++j) {
				nr[i+j][0]=min(nr[i+j][0], r[i][0]+cur[j][0]);
				nr[i+j][1]=min(nr[i+j][1], r[i][1]+min(cur[j][0], cur[j][1]));
			}
		}
		swap(r, nr);
	}
	//cout << u << " " << r.size()-1 << endl;
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> b;
	for (int i=0; i<n; ++i) {
		cin >> c[i] >> d[i];
		if (i) {
			int p;
			cin >> p, --p;
			adj[p].push_back(i);
		}
	}
	vector<ar<ll, 2>> r=dfs();
	assert(r.size()==n+1);
	int ans=0;
	for (int i=1; i<=n; ++i)
		if (min(r[i][0], r[i][1])<=b)
			ans=i;
	cout << ans;
	return 0;
}