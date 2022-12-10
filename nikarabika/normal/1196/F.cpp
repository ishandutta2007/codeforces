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

const int maxn = 2e5 + 10,
	  maxk2 = 1000;
set<pair<LL, pii> > s;
map<pii, LL> dis;
map<pii, bool> mark;
vector<pll> adj[maxn];
int n, m, k;

bool is_new(int u, int v) {
	if (u == v)
		return false;
	if (u > v) swap(u, v);
	if (mark[MP(u, v)]) {
		mark.erase(MP(u, v));
		return false;
	}
	return mark[MP(u, v)] = true;
}

void relax_adjs(int src, int u) {
	LL disu = (u == src ? 0 : dis[MP(src, u)]);
	for (auto e : adj[u]) {
		LL w = e.R;
		int v = e.L;
		LL &disv = dis[MP(src, v)];
		LL disv2 = disv;
		if ((v != src and disv2 == 0) or disu + w < disv2) {
			s.erase(MP(disv2, MP(src, v)));
			disv = disu + w;
			disv2 = disu + w;
			s.insert(MP(disv2, MP(src, v)));
			if (sz(s) >= maxk2) {
				auto it = s.end();
				it--;
				dis.erase(it->R);
				if (it->R == MP(src, v)) {
					s.erase(it);
					break;
				}
				s.erase(it);
			}
		}
	}
}

bool cmp(pll x, pll y) {
	return x.R < y.R;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		adj[fi].PB(MP(se, th));
		adj[se].PB(MP(fi, th));
	}
	for (int i = 0; i < n; i++) {
		sort(all(adj[i]), cmp);
		relax_adjs(i, i);
	}
	for (int _ = 0; _ < maxk2; _++) {
		auto eps = s.begin()->R;
		if (is_new(eps.L, eps.R)) {
			k--;
			if (!k) {
				cout << s.begin()->L << endl;
				return 0;
			}
		}
		s.erase(s.begin());
		int src = eps.L;
		int u = eps.R;
		relax_adjs(src, u);
	}
	return 0;
}