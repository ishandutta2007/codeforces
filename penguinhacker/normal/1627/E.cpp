#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
const ll INF=2e18;
int n, m, k;
ll x[mxN];
ar<int, 5> lad[mxN];
vector<int> d[mxN];
vector<ll> dp[mxN];
vector<vector<ar<int, 3>>> l[mxN];

int id(int i, int x) {
	auto it=lower_bound(d[i].begin(), d[i].end(), x);
	assert(it!=d[i].end());
	return it-d[i].begin();
}

void solve() {
	cin >> n >> m >> k;
	for (int i=0; i<n; ++i) {
		cin >> x[i];
		d[i].clear();
		l[i].clear();
		dp[i].clear();
	}
	d[0].push_back(0);
	d[n-1].push_back(m-1);
	for (int i=0; i<k; ++i) {
		int a, b, c, d2, e;
		cin >> a >> b >> c >> d2 >> e, --a, --b, --c, --d2;
		lad[i]={a, b, c, d2, e};
		d[a].push_back(b);
		d[c].push_back(d2);
	}
	for (int i=0; i<n; ++i) {
		sort(d[i].begin(), d[i].end());
		d[i].resize(unique(d[i].begin(), d[i].end())-d[i].begin());
		l[i].resize(d[i].size());
		dp[i].assign(d[i].size(), INF);
	}
	for (int i=0; i<k; ++i)
		l[lad[i][0]][id(lad[i][0], lad[i][1])].push_back({lad[i][2], id(lad[i][2], lad[i][3]), lad[i][4]});
	dp[0][0]=0;
	for (int i=0; i<n; ++i) {
		priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
		for (int j=0; j<d[i].size(); ++j)
			pq.push({dp[i][j], j});
		while(pq.size()) {
			ll cd=pq.top()[0], u=pq.top()[1];
			pq.pop();
			if (dp[i][u]!=cd)
				continue;
			if (u&&cd+(d[i][u]-d[i][u-1])*x[i]<dp[i][u-1])
				pq.push({dp[i][u-1]=cd+(d[i][u]-d[i][u-1])*x[i], u-1});
			if (u+1<d[i].size()&&cd+(d[i][u+1]-d[i][u])*x[i]<dp[i][u+1])
				pq.push({dp[i][u+1]=cd+(d[i][u+1]-d[i][u])*x[i], u+1});
		}
		for (int j=0; j<d[i].size(); ++j)
			for (ar<int, 3> a : l[i][j])
				dp[a[0]][a[1]]=min(dp[a[0]][a[1]], dp[i][j]-a[2]);
		//for (ll x : dp[i])
		//	cout << i << " " << x << endl;
	}
	if (dp[n-1].back()>=INF/2) {
		cout << "NO ESCAPE\n";
		return;
	}
	cout << dp[n-1].back() << "\n";
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