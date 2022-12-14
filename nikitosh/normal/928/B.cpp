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

const int MAX_N = 1e5 + 5;

int ans[MAX_N];

pii getSegment(int x, int k, int n) {
 	return mp(max(1, x - k), min(n, x + k));
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, k;
	scanf("%d%d", &n, &k);
	forab (i, 1, n + 1) {
		int l;
	 	scanf("%d", &l);
	 	pii segment = getSegment(i, k, n);
	 	if (l == 0)
	 		ans[i] = segment.sc - segment.fs + 1;
	 	else {
	 		int r = getSegment(l, k, n).sc;
	 	 	ans[i] = ans[l];
	 	 	if (segment.fs > r)
	 	 		ans[i] += segment.sc - segment.fs + 1;
	 	 	else
	 	 		ans[i] += segment.sc - r;
	 	}
	}	
	forab (i, 1, n + 1)
		printf("%d ", ans[i]);
	return 0;
}