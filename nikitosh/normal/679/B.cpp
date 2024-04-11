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

vector<ll> v;

ll cub(int a) {
 	return a * 1ll * a * 1ll * a;
}

int get(ll x) {
	if (x <= 7)
		return x;
 	int s = pow(x, 1./3), c = s;
 	for (int a = max(1, s - 1); a < s + 2; a++)
 		if (cub(a) <= s)
 			c = a; 
	return 1 + get(x - cub(c));
}

pair<int, ll> solve(ll x) {
 	if (x <= 7)
 		return mp(x, x);
	int c = (int) (pow(x, 1./3) + 0.00001);
	auto ans1 = solve(min(x - cub(c), cub(c + 1) - cub(c) - 1));
	auto ans2 = solve(min(x - cub(c - 1), cub(c) - cub(c - 1) - 1));
	if (ans1.fs > ans2.fs) 
		return mp(ans1.fs + 1, ans1.sc + cub(c));
	if (ans1.fs < ans2.fs) 
		return mp(ans2.fs + 1, ans2.sc + cub(c - 1));
	return mp(ans1.fs + 1, max(ans1.sc + cub(c), ans2.sc + cub(c - 1)));
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	ll x;
	scanf(I64, &x);	
	auto np = solve(x);
	printf("%d " I64 "\n", np.fs, np.sc);
	return 0;
}