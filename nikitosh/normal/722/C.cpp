#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
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
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAX_N = 1e5 + 5;

multiset<ll> sums;
set<pii> s;
ll a[MAX_N], sum[MAX_N];

inline ll get(int l, int r) {
 	return sum[r] - sum[l];
}

void add(int l, int r) {
 	if (l < r)
 		sums.insert(get(l, r)), s.insert(mp(l, r));
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n) {
	 	scanf(I64, &a[i]);
	 	sum[i + 1] = sum[i] + a[i];
	}
	sums.insert(get(0, n));
	s.insert(mp(0, n));
	forn (i, n) {
		int ind;
	 	scanf("%d", &ind);
	 	ind--;
	 	auto it = s.upper_bound(mp(ind + 1, -1));
	 	it--;
	 	int l = it->fs, r = it->sc;
	 	//eprintf("%d %d\n", l, r);
	 	s.erase(it);
	 	sums.erase(sums.find(get(l, r)));
	 	add(l, ind);
	 	add(ind + 1, r);	
	 	if (sz(sums)) 
	 		printf(I64 "\n", *sums.rbegin());
	 	else
	 		puts("0");
	}
	return 0;
}