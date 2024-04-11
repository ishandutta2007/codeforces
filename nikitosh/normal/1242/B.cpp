#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using vi = vector<int>;
using pii = pair<int, int>;
 
#define FNAME ""

const int MAX_N = 2e5 + 5;

int pr[MAX_N];
vi g[MAX_N];
  
int gett(int v) {
	return pr[v] == v ? v : pr[v] = gett(pr[v]);
}  

void unite(int v, int u) {
	v = gett(v), u = gett(u);
	if (v != u)
		pr[v] = u;
}
  
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;
	forn (i, m) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].pb(u), g[u].pb(v);
	}
	int minDeg = n, ind = -1;
	forn (i, n) {
		pr[i] = i;
		sort(all(g[i]));
		if (minDeg > sz(g[i]))
			minDeg = sz(g[i]), ind = i;
	}
	vi ver;
	ver.pb(ind);
	for (int u : g[ind])
		ver.pb(u);
	for (int v : ver) {
		int it = 0;
		forn (i, n) {
			if (it != sz(g[v]) && g[v][it] == i) {
				it++;
				continue;
			}
			unite(v, i);
		}
	}
	set<int> s;
	forn (i, n)
		s.insert(gett(i));
	cout << sz(s) - 1;
	return 0;
}