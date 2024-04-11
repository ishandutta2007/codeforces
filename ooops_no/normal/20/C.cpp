/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

using namespace std;
typedef long long ll;

const ll INF = (ll) 1e18;

int main() {
	ll n, m, s;
	cin >> n >> m;
	s = 1;
	vector < vector < pair<ll, ll> > > g(n+1);
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		g[a].push_back(make_pair(b,c));
		g[b].push_back(make_pair(a, c));
	}
	vector<ll> d(n+1, INF), p(n+1);
	d[s] = 0;
	set < pair<ll, ll> > q;
	q.insert(make_pair(d[s], s));
	while (!q.empty()) {
		ll v = q.begin()->second;
		q.erase(q.begin());

		for (size_t j = 0; j < g[v].size(); ++j) {
			ll to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				q.erase(make_pair(d[to], to));
				d[to] = d[v] + len;
				p[to] = v;
				q.insert(make_pair(d[to], to));
			}
		}
	}
	ll to = n;
	vector<ll> ans;
	if (d[n] == INF) {
		cout << -1;
		return 0;
	}
	while (p[to] != 0) {
		ans.push_back(to);
		to = p[to];
	}
	reverse(ans.begin(), ans.end());
	cout << '1' << " ";
	for (ll i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}