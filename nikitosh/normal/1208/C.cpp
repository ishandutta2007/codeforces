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

const int MAX_N = 1005;

int a[MAX_N][MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	bool flag = 0;
	int cur = 0;
	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < n; j+= 2) {
		 	a[i][j] = cur++;
		 	a[i][j + 1] = cur++;
		 	a[i + 1][j] = cur++;
		 	a[i + 1][j + 1] = cur++;
		 	if (flag)
		 		swap(a[i + 1][j], a[i][j + 1]);
		 	flag ^= 1;
		}
		flag ^= 1;
	}
	forn (i, n) {
		forn (j, n)
			printf("%d ", a[i][j]);
		puts("");
	}
	return 0;
}