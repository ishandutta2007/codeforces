#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, q, ans[mxN], self[mxN];
vector<ar<int, 2>> adj[mxN];
ar<int, 3> qry[mxN];
bool zero[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(self, -1, sizeof(self));
	cin >> n >> q;
	for (int i=0; i<q; ++i) {
		int a, b, c;
		cin >> a >> b >> c, --a, --b;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
		qry[i]={a, b, c};
		if (a==b)
			self[a]=c;
	}
	for (int j=0; j<30; ++j) {
		memset(zero, 0, sizeof(zero));
		for (int i=0; i<q; ++i)
			if (!(qry[i][2]&1<<j))
				zero[qry[i][0]]=zero[qry[i][1]]=1;
		for (int i=0; i<n; ++i) {
			if (zero[i])
				continue;
			if (self[i]!=-1) {
				ans[i]=self[i];
				continue;
			}
			bool b=1;
			for (auto [j, x] : adj[i])
				if (zero[j]) {
					b=0;
					break;
				}
			if (b)
				zero[i]=1;
			else
				ans[i]|=1<<j;
		}
	}
	for (int i=0; i<n; ++i)
		cout << ans[i] << " ";
	return 0;
}