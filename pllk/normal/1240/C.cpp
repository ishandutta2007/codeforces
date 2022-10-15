#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, k;
vector<pair<int,int>> v[505050];
ll d[505050][2];

void dfs(int s, int e) {
	vector<vector<ll>> vv;
	for (auto u : v[s]) {
		if (u.first == e) continue;
		dfs(u.first,s);
		ll a1 = u.second+d[u.first][1];
		ll a2 = d[u.first][0];
		vv.push_back({a1-a2,max(a1,a2),a2});
	}
	sort(vv.rbegin(),vv.rend());
	d[s][0] = d[s][1] = 0;
	for (int i = 0; i < vv.size(); i++) {
		if (i+1 <= k) {
			d[s][0] += vv[i][1];
		} else {
			d[s][0] += vv[i][2];
		}
		if (i+1 <= k-1) {
			d[s][1] += vv[i][1];
		} else {
			d[s][1] += vv[i][2];
		}
	}
}

void lol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) v[i].clear();
	for (int i = 1; i <= n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	dfs(1,0);
	cout << max(d[1][0],d[1][1]) << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) lol();
}