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

const int MAX_N = 2e3 + 5;

int a[MAX_N];
set<int> s;

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n)
		scanf("%d", &a[i]);
	int it = -1;	
	fornr (i, n) {
		if (s.count(a[i])) {
		    it = i;
		    break;
		}	
		s.insert(a[i]);
	}
	if (it == -1) {
	 	printf("%d\n", 0);
	 	return 0;
	}
	int ans = it + 1;
	forn (i, n) {
		bool ok = 1;
	 	while (s.count(a[i])) {
	 	 	it++;
	 	 	if (it >= n) {
	 	 		ok = 0;
	 	 		break;
	 	 	}
	 	 	else
	 	 		s.erase(a[it]);
	 	}
	 	if (!ok)
	 		break;
	 	ans = min(ans, it - i);
	 	s.insert(a[i]);
	}
	printf("%d\n", ans);
	return 0;
}