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

const int MAX_N = 100;

int cur[MAX_N], d[MAX_N], c[MAX_N], ans[MAX_N];
int a, b, minn = 1e9;
vi v;

void gen(int k, int n, int sum) {
 	if (k == n) {
 		bool ok = 1;
 		forab (i, 1, n + 1)
			if (c[i] > 0)
				ok = 0;
		if (ok && sum < minn) {
			minn = sum;
			forn (i, n)
				ans[i] = d[i];
		}		 		
 	 	return;
 	}
 	forn (i, 9) {
		d[k] = i;
		c[k] -= b * i, c[k + 1] -= a * i, c[k + 2] -= b * i;
		gen(k + 1, n, sum + i); 	
		c[k] += b * i, c[k + 1] += a * i, c[k + 2] += b * i;
	}
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n;
	scanf("%d%d%d", &n, &a, &b);	
	forn (i, n)
		scanf("%d", &c[i]), c[i]++;
	int k = (c[0] + b - 1) / b;
	c[0] -= b * k, c[1] -= a * k, c[2] -= b * k;
	forn (i, k)
		v.pb(1);
	k = 0;
	if (c[n - 1] > 0)
		k = (c[n - 1] + b - 1) / b;
	forn (i, k)
		v.pb(n - 2);
	c[n - 3] -= b * k, c[n - 2] -= a * k, c[n - 1] -= b * k;
	gen(0, n - 2, 0);
	forn (i, n - 2)
		forn (j, ans[i])
			v.pb(i + 1);
	printf("%d\n", sz(v));
	for (int k : v)
		printf("%d ", k + 1);
	return 0;
}