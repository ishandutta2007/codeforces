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

const int MAX_N = 1e5 + 5, INF = 2e9;

int a[MAX_N];
set<int> s;

int tryPut(int k) {
	if (!k)
		return 0;
 	if (!s.count(k)) {
 		s.insert(k);
 		return 1;
 	}
 	if (k == 1)
 		return 0;
 	if (tryPut(k / 2))
 		return 1;	
	return 0;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n) {
	 	scanf("%d", &a[i]);
		s.insert(a[i]);
	}
	while (1) {
	 	int k = *s.rbegin();
		if (!tryPut(k / 2)) {
		    for (int k : s) {
			 	printf("%d ", k);
	        }
		 	return 0;
		}
		s.erase(k);
	}
	return 0;
}