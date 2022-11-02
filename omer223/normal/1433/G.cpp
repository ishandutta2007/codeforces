#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e3;
int n, m, k;
vector<pii> adj[sz];
vector<pii> v;
vector<pii> e;
ll dist[sz][sz];
bitset<sz> fin;

void input() {
	cin >> n >> m >> k;
	int a, b, w;
	foru(i, 0, m) {
		cin >> a >> b >> w; a--; b--;
		adj[a].pb({ b,w });
		adj[b].pb({ a,w });
		e.pb({ a,b });
	}
	foru(i, 0, k) {
		cin >> a >> b; a--; b--;
		v.pb({ a,b });
	}
}

void sp(int src) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	fin.reset();
	pq.push({ 0,src });
	while (!pq.empty()) {
		pii x = pq.top(); pq.pop();
		if (fin[x.second])continue;
		fin[x.second] = 1;
		int s = x.second;
		for (auto t : adj[s]) {
			if (dist[src][t.first] > dist[src][s] + t.second) {
				dist[src][t.first] = dist[src][s] + t.second;
				pq.push({ dist[src][t.first], t.first });
			}
		}
	}
}

void findDists() {
	foru(i, 0, n) {
		foru(j, 0, n) {
			if (i == j)continue;
			dist[i][j] = 1e15;
		}
	}
	foru(i, 0, n)sp(i);
}

int main() {
	fast;
	input();
	findDists();
	ll bst = 1e18;
	int edgesSize = e.size(), l, r, sta, stb;
	foru(i, 0, edgesSize) {
		sta = e[i].first, stb = e[i].second;
		ll cursum = 0;
		foru(j, 0, k) {
			ll tmp = 1e15;
			l = v[j].first, r = v[j].second;
			tmp = dist[l][r];
			tmp = min(tmp, dist[l][sta] + dist[stb][r]);
			tmp = min(tmp, dist[l][stb] + dist[sta][r]);
			cursum += tmp;
		}
		bst = min(bst, cursum);
	}
	cout << bst << '\n';
	return 0;
}