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

double EPS = 1e-12;

void handle(int rz, int vz, int z_1, int z_2, double &l, double &r) {
  	if (vz == 0) {
  		if (rz <= z_1 || rz >= z_2) {
  		 	puts("-1");
  		 	exit(0);
  		}
   	}	
   	if (vz > 0) {
   		l = max(l, (z_1 - rz) * 1. / vz);
   		r = min(r, (z_2 - rz) * 1. / vz);
   	}
   	if (vz < 0) {
   		l = max(l, (z_2 - rz) * 1. / vz);
   		r = min(r, (z_1 - rz) * 1. / vz);		
   	}   
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	int x_1, y_1, x_2, y_2;
	scanf("%d%d%d%d", &x_1, &y_1, &x_2, &y_2);
	double l = 0, r = 1e9;
	forn (i, n) {
		int rx, ry, vx, vy;
		scanf("%d%d%d%d", &rx, &ry, &vx, &vy);
		handle(rx, vx, x_1, x_2, l, r);
		handle(ry, vy, y_1, y_2, l, r);
	}	
	if (r <= l + EPS) {
		puts("-1");
		return 0;	 	
	}
	printf("%.20f\n", l);
	return 0;
}