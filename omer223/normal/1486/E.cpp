#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e5 + 5;
int n, m;
vector<pii> adj[sz][51];
int dist[sz][51];
bool done[sz][51];


int tn(int src, int layer) {
	return n * layer + src;
}

pii calc(int num) {
	return { num % n,num / n };
}

void input() {
	cin >> n >> m;
	foru(i, 0, m) {
		int x, y, w;
		cin >> x >> y >> w;
		x--; y--;
		adj[x][0].pb({ tn(y,w), 0 });
		adj[y][0].pb({ tn(x,w),0 });
		for (int wt = 1; wt <= 50; wt++)adj[x][wt].pb({ tn(y,0),(wt + w)*(wt + w) });
		for (int wt = 1; wt <= 50; wt++)adj[y][wt].pb({ tn(x,0),(wt + w)*(wt + w) });
	}
}


void sp() {
	foru(i, 0, n) {
		foru(j, 0, 51)dist[i][j] = 2e9 + 5;
	}
	dist[0][0] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,tn(0,0) });
	while (!pq.empty()) {
		auto x = pq.top(); pq.pop();
		int myd = x.ff, src = calc(x.ss).first, layer = calc(x.ss).second;
		if (done[src][layer])continue;
		done[src][layer] = 1;
		for (auto y : adj[src][layer]) {
			pii tmp = calc(y.ff);
			int ysrc = tmp.ff, ylayer = tmp.ss;
			if (dist[ysrc][ylayer] > myd + y.ss) {
				dist[ysrc][ylayer] = myd + y.ss;
				pq.push({ dist[ysrc][ylayer] ,y.ff });
			}
		}
	}
}

int main() {
	fast;
	input();
	sp();
	foru(i, 0, n) {
		if (dist[i][0] > 2e9)cout << -1 << ' ';
		else cout << dist[i][0] << ' ';
	}
	cout << '\n';
	return 0;
}