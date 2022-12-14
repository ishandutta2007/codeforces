#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FNAME ""

const int MAX_N = 2e5 + 5;

ll a[MAX_N];

set<pii> s;

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m, l;
	scanf("%d%d%d", &n, &m, &l);
	forn (i, n)
		scanf(I64, &a[i]);
	int last = -1;
	forn (i, n + 1) {
	 	if (a[i] > l && last == -1)
	 		last = i;
	 	else if (a[i] <= l && last != -1) {
	 	 	s.insert(mp(last, i - 1));
	 	 	last = -1;
		}
	}
	forn (i, m) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			printf("%d\n", sz(s));
		} else {
		 	int p, d;
		 	scanf("%d%d", &p, &d);
		 	p--;
		 	if (a[p] + d <= l || a[p] > l)
		 		a[p] += d;
		 	else {
		 		a[p] += d;
		 		int lef = p, righ = p;
		 	 	auto it = s.lower_bound(mp(p, p));	
		 	 	if (it != s.end() && it->first == p + 1) {
		 	 	 	righ = it->second;
		 	 	 	s.erase(it);
		 	 	}
		 	 	it = s.lower_bound(mp(p, p));	
		 	 	if (it != s.begin()) {
		 	 	 	it--;
		 	 	 	if (it->second == p - 1) {
		 	 	 	 	lef = it->first;
		 	 	 	 	s.erase(it);
		 	 	 	}
		 	 	}
		 	 	s.insert(mp(lef, righ));
		 	}
		}
	}

	return 0;
}