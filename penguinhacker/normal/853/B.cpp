#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const ll INF=1e12;
const int mxN=1e6+1;
int n, m, k;
ll cost[mxN], pre[mxN], suf[mxN], cur=0, ans=INF;
vector<ar<int, 3>> event[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<m; ++i) {
		int d, s, f, c; cin >> d >> s >> f >> c;
		event[d].push_back({s, f, c});
	}
	for (int i=1; i<=n; ++i) cost[i]=INF, cur+=cost[i];
	for (int i=1; i<=1e6; ++i) {
		for (auto x : event[i]) {
			if (x[0]==0) continue;
			if (x[2]<cost[x[0]]) {
				cur-=cost[x[0]]-x[2];
				cost[x[0]]=x[2];
			}
		}
		pre[i]=cur;
	}
	cur=0;
	for (int i=1; i<=n; ++i) cost[i]=INF, cur+=cost[i];
	for (int i=1e6; i>=1; --i) {
		for (auto x : event[i]) {
			if (x[1]==0) continue;
			if (x[2]<cost[x[1]]) {
				cur-=cost[x[1]]-x[2];
				cost[x[1]]=x[2];
			}
		}
		suf[i]=cur;
	}
	for (int i=2; i+k<=1000000; ++i)
		ans=min(ans, pre[i-1]+suf[i+k]);
	//for (int i=1; i<=15; ++i)
	//	cout << pre[i] << ' ' << suf[i] << '\n';
	cout << (ans==INF?-1:ans);
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/