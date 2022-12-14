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

char s[10];
const int primes[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
vi v;

int main() {
	
	forn (i, 15) {
		printf("%d\n", primes[i]);
		fflush(stdout);
		scanf("%s", s);
		if (s[0] == 'y') {
			v.pb(primes[i]);
		}
	}	
	if (sz(v) > 1) {
		puts("composite");
		return 0;
	}	
	if (sz(v) == 0) {
	 	puts("prime");
	 	return 0;
	}
	int k = v[0];
	if (k * k > 100) {
	 	puts("prime");
	 	return 0;
	}
	printf("%d\n", k * k);
	fflush(stdout);
  	scanf("%s", s);
  	if (s[0] == 'y') {
  		puts("composite");
  		return 0;
  	}
	puts("prime"); 
	return 0;
}