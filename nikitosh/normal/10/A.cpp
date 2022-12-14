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

const int MAX_N = 201;

int p[MAX_N], t[MAX_N], l[MAX_N], r[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n;
	scanf("%d%d%d%d%d%d", &n, &p[0], &p[1], &p[2], &t[0], &t[1]);
	forn (i, n)
		scanf("%d%d", &l[i], &r[i]);
	
	int last = l[0], ans = 0;
	forn (i, n)	{
	 	ans += p[0] * (r[i] - l[i]);
	 	int k = l[i] - last;
		ans += min(t[0], k) * p[0];
		ans += min(max(k - t[0], 0), t[1]) * p[1];
		ans += max(k - t[0] - t[1], 0) * p[2];
	 	last = r[i];
	}
	printf("%d\n", ans);	
	
	return 0;
}