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

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	ll lA, rA, tA, lB, rB, tB;
	scanf(I64 I64 I64 I64 I64 I64, &lA, &rA, &tA, &lB, &rB, &tB);
	ll g = __gcd(tA, tB);
	ll maxx = 0;
	forn (i, 2) {
		ll newL = lA + (lB + tA * tB - lA + g - 1) / g * g;
		ll newR = min(rB + tA * tB, newL + rA - lA);
		maxx = max(maxx, newR - newL + 1);
		swap(rA, rB);
		swap(lA, lB);
	}
	printf(I64 "\n", maxx);
	return 0;
}