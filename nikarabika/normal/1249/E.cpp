//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 5e5 + 100;
vector<pii> adj[maxn];
int dis[maxn],
	a[maxn],
	b[maxn];
set<pii> s;
int n, c;

void add1edge(int u, int v, int w) {
	adj[u].PB(MP(v, w));
}

void add2edge(int u, int v, int w) {
	add1edge(u, v, w);
	add1edge(v, u, w);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> c;
	for (int i = 0; i + 1 < n; i++)
		cin >> a[i];
	for (int i = 0; i + 1 < n; i++)
		cin >> b[i];
	for (int i = 0; i + 1 < n; i++) {
		add2edge(i, i + 1, a[i]);
		add2edge(n + i, n + i + 1, b[i]);
	}
	for (int i = 0; i < n; i++)
		add1edge(i, n + i, c), add1edge(n + i, i, 0);
	memset(dis, 63, sizeof dis);
	dis[0] = 0;
	s.insert(MP(0, 0));
	while (sz(s)) {
		int u = s.begin()->R;
		s.erase(s.begin());
		for (auto e : adj[u]) {
			int v = e.L,
				w = e.R;
			if (dis[u] + w < dis[v]) {
				s.erase(MP(dis[v], v));
				dis[v] = dis[u] + w;
				s.insert(MP(dis[v], v));
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << dis[i] << ' ';
	cout << '\n';
	return 0;
}