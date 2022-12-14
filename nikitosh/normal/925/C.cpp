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

const int MAX_N = 1e5 + 5;

vector<ll> ans, newAns;
ll a[MAX_N];
vector<ll> b[105];
int cur[105];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n) 
	 	scanf(I64, &a[i]);
	forn (i, n) {
		fornr (j, 60)
			if ((a[i] >> j) & 1) {
				b[j].pb(a[i]); 	
		    	break;
			}
	}
	fornr (i, 60) {
	 	if (sz(b[i]) > 1 + cur[i]) {
	 	 	puts("No");
	 	 	return 0;
	 	}
	 	for (ll k : b[i])
	 		forn (j, 60)
	 			if ((k >> j) & 1)
	 				cur[j]++;
		newAns.clear();
		int ind = 0;
		if (ind < sz(b[i]))
	        newAns.pb(b[i][0]), ind++;
		for (ll k : ans) {
		 	newAns.pb(k);
		 	if (((k >> i) & 1) && ind < sz(b[i]))
		 		newAns.pb(b[i][ind++]);
		}
		ans = newAns;
	}
	puts("Yes");
	for (ll k : ans)
		printf(I64 " ", k);
	return 0;
}