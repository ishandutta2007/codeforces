#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, k, w, d[1000][1000];
pair<int, int> cost[1000];
string s[1000][10];

int dist(int a, int b) {
	int cnt=0;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (s[a][i][j]!=s[b][i][j])
				++cnt;
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k >> w;
	for (int i=0; i<k; ++i) {
		for (int j=0; j<n; ++j)
			cin >> s[i][j];
		cost[i]={n*m, -1};
	}
	for (int i=0; i<k; ++i)
		for (int j=i+1; j<k; ++j)
			d[i][j]=d[j][i]=dist(i, j)*w;
	int ans=0;
	vector<pair<int, int>> a;
	for (int r=0; r<k; ++r) {
		int u=-1;
		for (int i=0; i<k; ++i)
			if (cost[i].first!=-1)
				if (u==-1||cost[i].first<cost[u].first)
					u=i;
		assert(cost[u].first!=-1);
		ans+=cost[u].first;
		a.emplace_back(u+1, cost[u].second+1);
		cost[u].first=-1;
		for (int i=0; i<k; ++i)
			if (d[u][i]<cost[i].first)
				cost[i]={d[u][i], u};
	}
	cout << ans << '\n';
	for (auto x : a)
		cout << x.first << ' ' << x.second << '\n';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/