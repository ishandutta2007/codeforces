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

const int MAX_N = 2e5 + 5;

int a[MAX_N], b[MAX_N];

map<int, int> m;

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, k;
	scanf("%d%d", &n, &k);
	forn (i, n)
		scanf("%d", &a[i]);
	b[0] = a[0];
	forab (i, 1, n)
		b[i] = b[i - 1] ^ a[i];
	forn (i, n)
		if (b[i] >= (1 << (k - 1)))
			b[i] ^= ((1 << k) - 1);
	m[0]++;						
	forn (i, n)
		m[b[i]]++;
	ll ans = (n + 1) * 1ll * n / 2;
	for (auto np : m) {
	 	int l = np.sc;
	 	int l1 = l / 2, l2 = (l + 1) / 2;
	 	ans -= l1 * 1ll * (l1 - 1) / 2;
	 	ans -= l2 * 1ll * (l2 - 1) / 2;
	}
	printf(I64, ans);
	return 0;
}