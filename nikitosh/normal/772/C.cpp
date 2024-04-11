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
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAX_N = 3e5 + 5;

int was[MAX_N], ans[MAX_N], pr[MAX_N];
vi lst[MAX_N];

int gcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1, y = 0; 
		return a;
	} 
	else {
		int g = gcd(b, a % b, x, y);
	   	int newX = y;
   		y = x - a / b * y;
	   	x = newX;
   		return g;
	}
}

int inverse(int a, int mod) { //returns -1, if a and mod are not coprime
	int x, y;
	int g = gcd(a, mod, x, y);
	return g == 1 ? (x % mod + mod) % mod : -1;
}

void go(int a, int b, int m, vi &ans) {
    int g = __gcd(a, m);
    //printf("a=%d b=%d g=%d a/g=%d m=%d inv=%d\n", a, b, g, a / g, m, inverse(a / g, m / g));
	ans.pb((b / g * 1ll * inverse(a / g, m / g)) % m);	 	
}

void check(vi ans, int m) {
 	int cur = 1;
 	puts("");
 	set<int> wass;
 	for (int k : ans) {
 	 	cur = (cur * 1ll * k) % m; 
 	 	if (wass.count(cur))
 	 		puts("AAA");
 		//printf("%d ", cur);
 		wass.insert(cur);	
 	}
 	//puts("");
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m, k;
	scanf("%d%d", &n, &m);
	forn (i, n)
		scanf("%d", &k), was[k] = 1;
	was[m] = was[0];
	vi divisors;	
	forab (i, 1, m + 1)
		if (m % i == 0)
			divisors.pb(i);
	forab (i, 1, m + 1) {
	    int g = __gcd(m, i);
	 	if (!was[i])
	 		lst[g].pb(i);
	}
	reverse(all(divisors));
	pr[m] = -1;
	forn (i, sz(divisors)) {
		int maxx = -1;
	 	forn (j, i)
	 		if (divisors[j] % divisors[i] == 0) {
	 		 	if (ans[divisors[j]] > maxx) {
	 		 	 	maxx = ans[divisors[j]];
	 		 	 	pr[divisors[i]] = divisors[j];
	 		 	 	//printf("%d %d\n", divisors[i], divisors[j]);
	 		 	}
	 		}
	 	maxx = max(maxx, 0);
		ans[divisors[i]] = maxx + sz(lst[divisors[i]]);
	}
	int maxx = 0, ind = -1;
	forn (i, sz(divisors)) {
	 	int d = divisors[i];
	 	if (sz(lst[d]) > 0 && ans[d] > maxx)
	 		maxx = ans[d], ind = d;
	}
	int last = 1;
	vi ans;
	while (ind != -1) {
		//printf("%d %d\n", ind, pr[ind]);
		if (sz(lst[ind]) == 0) {
		 	ind = pr[ind];
		 	continue;
		}
		go(last, lst[ind][0], m, ans);
		forn (j, sz(lst[ind]) - 1)
			go(lst[ind][j], lst[ind][j + 1], m, ans);
		last = lst[ind].back();
		ind = pr[ind];
	}
	printf("%d\n", sz(ans));
	for (int k : ans)
		printf("%d ", k);
	puts("");
	//check(ans, m);
	return 0;
}