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

const int MAX_N = 1e5 + 5, MAX_C = 205, MAX = 1e9;

int b[MAX_C][MAX_C], cnt[MAX_C], d[MAX_C], q[MAX_C];
ll a[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	int cur = 0;
	forn (i, n) {
	 	ll k;
	 	cin >> k;
	 	if (k != 0)
			a[cur++] = k;
	 	vi v;
	 	while (k) {
	 		v.pb(k % 2);
	 	 	k /= 2;
	 	}
	 	forn (j, sz(v))
	 		if (v[j])
	 			cnt[j]++;
	}
	forn (i, 60)
		if (cnt[i] >= 3) {
		 	puts("3");
		 	return 0;
		}
	forn (i, cur)
		forn (j, cur) 
			if (i != j && (a[i] & a[j]))
				b[i][j] = 1;
	int ans = MAX;
	forn (i, cur)
		forn (j, cur) 
			if (b[i][j]) {
			 	b[i][j] = b[j][i] = 0;
			 	forn (g, cur)
			 		d[g] = cur * 2;
			 	int head = 0, tail = 0;
			 	q[tail++] = i;
			 	d[i] = 0;
			 	while (tail > head) {
			 		int u = q[head++];
			 		forn (g, cur)
			 			if (b[u][g] && d[g] > d[u] + 1) {
			 			 	d[g] = d[u] + 1;
			 			 	q[tail++] = g;
			 			}
			 	}
			 	if (d[j] != 2 * cur)
			 		ans = min(ans, d[j] + 1);
			 	b[i][j] = b[j][i] = 1;
			}
	if (ans == MAX)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}