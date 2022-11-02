#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <queue>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf = 1e9;
const int sz = 2e5;
vector<int> adj[sz];
ll dp[sz];
int dist[sz];
int n, m;

void reset() {
	foru(i, 0, n) {
		adj[i].clear();
		dist[i] = inf;
		dp[i] = inf;
	}
}

void bfs() {
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : adj[x]) {
			if (dist[y] == inf) {
				dist[y] = dist[x] + 1;
				q.push(y);
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	reset();
	foru(i, 0, m) {
		int x, y;
		cin >> x >> y;
		adj[--x].pb(--y);
	}
	bfs();
	vector<pii> v;
	vector<int> ans(n);
	foru(i, 0, n)v.pb({ dist[i],i });
	sort(v.rbegin(), v.rend());
	int mxdist = v[0].ff;
	foru(i, 0, n) {
		int src = v[i].ss;
		ans[src] = dist[src];
		for (int x : adj[src]) {
			if (dist[x] <= dist[src])ans[src] = min(ans[src], dist[x]);
			else ans[src] = min(ans[src], ans[x]);
		}
	}
	foru(i, 0, n)cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}