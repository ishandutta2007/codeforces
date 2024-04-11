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

const int MAX_N = 1e5 + 5;

int a[MAX_N], b[MAX_N];
double c[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, p;
	scanf("%d%d", &n, &p);
	ll sum = 0;
	forn (i, n)
		scanf("%d%d", &a[i], &b[i]), c[i] = b[i] * 1. / a[i], sum += a[i];
	if (p >= sum) {
	 	puts("-1");
	 	return 0;
	}
	double l = 0, r = 1e12;
	forn (k, 100) {
	 	double m = (l + r) / 2;
		double need = 0;	 	
	 	forn (i, n)
	 		if (m >= c[i])
	 			need += (m - c[i]) * a[i];	 
		if (need <= p * m)
			l = m;
		else
			r = m;
	}
	printf("%.20f\n", l);
	return 0;
}