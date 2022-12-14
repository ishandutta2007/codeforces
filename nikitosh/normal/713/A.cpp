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

const int LOG = 18;

map<vi, int> m;

void add(ll k, int dlt) {
    vi v(LOG);
    int cnt = 0;
    while (k > 0)
		v[cnt++] = k % 2, k /= 10;
	m[v] += dlt;		 		
}

int get(ll k) {
    vi v(LOG);
    int cnt = 0;
    while (k > 0)
		v[cnt++] = k % 2, k /= 10;
	return m[v];		 			 	
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int t;
	scanf("%d", &t);
	forn (tt, t) {
		char ch;
		ll k;
	 	scanf(" %c" I64, &ch, &k); 
	 	if (ch == '+')
	 		add(k, 1);
	 	if (ch == '-')
	 		add(k, -1);
	 	if (ch == '?')
	 		printf("%d\n", get(k));
	}
	return 0;
}