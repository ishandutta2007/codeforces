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

const int MAX_N = 1e6 + 1;

int prime[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, MAX_N)
		prime[i] = 1;
    prime[0] = prime[1] = 0;
    forab (i, 2, MAX_N) {
     	if (prime[i])
     		for (int j = 2 * i; j < MAX_N; j += i)
     			prime[j] = 0;
    }
	for (int i = n - 1; i >= 2; i--) 
		if (prime[i] && n % i == 0) {
			int k = n - i + 1;
			int ans = k;
			forab (d, 2, MAX_N) {
				if (!prime[d])
					continue;
				int l = (k - 1) / d * d;
				if (l != 0 && l + d >= k && l + d <= n) {
					ans = min(ans, l + 1);
					//printf("%d %d\n", d, l);
				}
			}	
			printf("%d\n", ans);				
			return 0;		 	
		}
	return 0;
}