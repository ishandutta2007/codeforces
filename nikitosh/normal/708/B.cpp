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

const int MAX = 1e5 + 5;

ll aa[4];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	forn (i, 4)
        scanf(I64, &aa[i]);
    if (aa[0] == 0 && aa[1] == 0 && aa[2] == 0 && aa[3] == 0) {
    	puts("0");
    	return 0;
    }
    int a = -1, b = -1;
	forn (i, MAX)
		if (i * 1ll * (i - 1) == 2 * aa[0]) {
			a = i;			
			break;
		}	
	forn (i, MAX)
		if (i * 1ll * (i - 1) == 2 * aa[3]) {
			b = i;			
			break;
		}	
    if (aa[0] == 0) {
     	if (aa[1] + aa[2] > 0)
     		a = 1;
     	else
     		a = 0;
    }
    if (aa[3] == 0) {
     	if (aa[1] + aa[2] > 0)
     		b = 1;
     	else
     		b = 0;
    }
	if (a == -1 || b == -1) {
		puts("Impossible");
		return 0;	
	}	
	if ((a + b) * 1ll * (a + b - 1) != 2 * (aa[0] + aa[1] + aa[2] + aa[3])) {
		puts("Impossible");
		return 0;	
	}
	int curB = b;
	forn (i, a + b) {
	 	if (aa[1] >= curB)
	 		printf("0"), aa[1] -= curB;
	 	else
	 		printf("1"), curB--;
	}
	return 0;
}