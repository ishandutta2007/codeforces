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

const int MAX = 1e6;

bool prime[MAX + 5];
unsigned int a, b, c, d;

inline unsigned int gett(unsigned int x) {
 	return d + x * c + x * x * b + x * x * x * a;
}

inline unsigned int get(int n, unsigned int k) {
    int x = n;
    unsigned int cur = 0;
 	while (x) {
 	 	x /= k;
 	 	cur += x;
 	}
 	return cur * gett(k);
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d%u%u%u%u", &n, &a, &b, &c, &d);
	forn (i, MAX)
		prime[i] = 1;
	prime[0] = prime[1] = 0;
	forab (i, 2, MAX)
		if (prime[i] && i * 1ll * i <= n) {
		 	for (int j = i * i; j < MAX; j += i)
		 		prime[j] = 0;
		}
	unsigned int ans = 0;
	vi primes;
	forab (i, 2, min(n + 1, MAX)) {
	    if (prime[i]) {
			ans += get(n, i);
			if (i * 1ll * i <= n)
				primes.pb(i);
		}
	}	
	for (int i = MAX; i <= n; i += MAX) {
	 	int l = i, r = min(n, i + MAX - 1);
	 	forn (j, MAX)
	 		prime[j] = 1;
	 	for (int p : primes) {
	 	 	for (int j = (l + p - 1) / p * p; j <= r; j += p)
	 	 		prime[j - l] = 0;
	 	}
	 	forab (j, l, r + 1)
	 		if (prime[j - l])
	 			ans += gett(j) * (unsigned int) (n / j);
	}
	printf("%u\n", ans);
	return 0;
}