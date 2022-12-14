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
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAX_N = 1e4 + 5;

pii p[MAX_N];

double sqr(double a) {
 	return a * a;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n)
		scanf("%d%d", &p[i].fs, &p[i].sc);
	p[n] = p[0], p[n + 1] = p[1];
	double ans = 1e20;
	forn (i, n) {
		double dist = abs((p[i + 2].sc - p[i].sc) * 1ll * p[i + 1].fs - (p[i + 2].fs - p[i].fs) * 1ll * p[i + 1].sc 
		+ p[i + 2].fs * 1ll * p[i].sc - p[i + 2].sc * 1ll * p[i].fs) / 
		sqrt(sqr(p[i + 2].sc - p[i].sc) + sqr(p[i + 2].fs - p[i].fs));
		
		ans = min(ans, dist / 2);
	}
	printf("%.20f\n", ans);
	return 0;
}