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
  
const int N = 3e5 + 5;  
  
int cur = 0;  
pii a[N];
vi v[N];
set<pii> edges;

void addEdge(int v, int u) {
	edges.insert(mp(v, u));
	edges.insert(mp(u, v));
}

void addEdges(const vi& cycle) {
	forn (i, sz(cycle) - 1) {
		addEdge(cycle[i], cycle[i + 1]);
	}
	addEdge(cycle[0], cycle.back());
}
  
void glue(vector<int>& cycle, int edgesNum, int k, int ind) {
	if (sz(cycle) + edgesNum - 2 * k <= 2)
		k--;
	int removed = -1;
	if (k == edgesNum - 1 && edges.count(mp(cycle.back(), cycle[sz(cycle) - k - 1]))) {
		removed = cycle.back();
		cycle.pop_back();
	}
	int b = cycle.back();
	vi u;
	forn (i, k) {
		u.pb(cycle.back());
		cycle.pop_back();
	}
	v[ind].pb(cycle.back());
	forn (i, edgesNum - k - 1) {
		v[ind].pb(cur);
		cycle.pb(cur++);
	}
	cycle.pb(b);
	v[ind].insert(v[ind].end(), all(u));
	if (removed != -1)
		cycle.pb(removed);
	addEdges(v[ind]);
}  
  
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;
	forn (i, n)
		cin >> a[i].fst, a[i].snd = i;
	sort(a, a + n);	
	reverse(a, a + n);
	
	vi cycle;
	forn (i, a[0].fst)
		cycle.pb(cur++);
	v[a[0].snd] = cycle;
	addEdges(cycle);
	int sum = 0;
	forab (i, 1, n)
		sum += a[i].fst - 2;
	forab (i, 1, n) {
		int k = a[i].fst - 2;
		sum -= k;
		if (sz(cycle) + k - 2 < sum) {
			glue(cycle, a[i].fst, 1, a[i].snd);	
		} else if (sz(cycle) - k - 2 >= sum) {
			glue(cycle, a[i].fst, a[i].fst - 1, a[i].snd);
		} else {
			glue(cycle, a[i].fst, (sz(cycle) + a[i].fst - 2 - sum) / 2, a[i].snd);
		}
	}
		
	cout << cur << "\n";
	forn (i, n) {
		for (int k : v[i])
			cout << k + 1 << " ";
		cout << "\n";
	}
	return 0;
}