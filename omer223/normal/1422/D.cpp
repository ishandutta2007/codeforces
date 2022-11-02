#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <bitset>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> pt;

const int sz = 1e5 + 5;
int n, m;
int sx, sy, fx, fy;
pt pts[sz];
ll dijkdist[sz];
vector<pll> adj[sz];

void sortx() {
	sort(pts + 1, pts + m + 1,
		[](const pt& a, const pt& b) -> bool
	{
		if (a.first.first != b.first.first)return a.first.first < b.first.first;
		else if (a.first.second != b.first.second)return a.first.second < b.first.second;
		else return a.second < b.second;
	});
}

void sorty() {
	sort(pts + 1, pts + m + 1,
		[](const pt& a, const pt& b) -> bool
	{
		if (a.first.second != b.first.second)return a.first.second < b.first.second;
		else if (a.first.first != b.first.first)return a.first.first < b.first.first;
		else return a.second < b.second;
	});
}

void sortind() {
	sort(pts + 1, pts + m + 1,
		[](const pt& a, const pt& b) -> bool
	{
		if (a.second != b.second)return a.second < b.second;
		else if (a.first.second != b.first.second)return a.first.second < b.first.second;
		else return a.first.first < b.first.first;
	});
}

inline ll dist(int i, int j) {
	return min(abs(pts[i].first.first - pts[j].first.first), abs(pts[i].first.second - pts[j].first.second));
}

inline ll distToGoal(int i) {
	return abs(pts[i].first.first - fx) + abs(pts[i].first.second - fy);
}

inline ll distToSrc(int i) {
	return min(abs(pts[i].first.first - sx),abs(pts[i].first.second - sy));
}

void input() {
	cin >> n >> m;
	cin >> sx >> sy >> fx >> fy;
	foru(i, 0, m) {
		cin >> pts[i+1].first.first >> pts[i+1].first.second; pts[i+1].second = i+1;
	}
}

void initGraph() {
	for (int i = 1; i <= m; i++) {
		ll myd = distToSrc(i);
		adj[0].pb({ i,myd });
		adj[i].pb({ 0,myd });
	}
	sortx();
	for (int i = 2; i <= m; i++) {
		int idthis = pts[i].second, idprv = pts[i - 1].second;
		ll myd = dist(i, i - 1);
		adj[idthis].pb({ idprv,myd });
		adj[idprv].pb({ idthis,myd });
	}
	sorty();
	for (int i = 2; i <= m; i++) {
		int idthis = pts[i].second, idprv = pts[i - 1].second;
		ll myd = dist(i, i - 1);
		adj[idthis].pb({ idprv,myd });
		adj[idprv].pb({ idthis,myd });
	}
	sortind();
}

/*
84 1
67 59 41 2
39 56
*/

void sp() {
	dijkdist[0] = 0;
	for (int i = 1; i <= m; i++)dijkdist[i] = 1e17;
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		auto x = pq.top(); pq.pop();
		ll src = x.second, cost = x.first;
		for (auto y : adj[src]) {
			if (dijkdist[y.first] > cost + y.second) {
				dijkdist[y.first] = cost + y.second;
				pq.push({ dijkdist[y.first],y.first });
			}
		}
	}
}

int main() {
	fast;
	input();
	initGraph();
	sp();
	ll ans = abs(sx - fx) + abs(sy - fy);
	foru(i, 1, m + 1)
		ans = min(ans, dijkdist[i] + distToGoal(i));
	cout << ans << endl;
	return 0;
}