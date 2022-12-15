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

const int LOG = 16;

int ansX_1[2], ansX_2[2], ansY_1[2], ansY_2[2];

int print(int x_1, int y_1, int x_2, int y_2) {
    printf("? %d %d %d %d\n", x_1, y_1, x_2, y_2);
    fflush(stdout);
    int k;
    scanf("%d", &k);
    return k;
}

int get(int x_1, int y_1, int x_2, int y_2) {
 	if (ansX_1[0] >= x_1 && ansY_1[0] >= y_1 && ansX_2[0] <= x_2 && ansY_2[0] <= y_2)
 		return 1;
	return 0;
}

int printGet(int x_1, int y_1, int x_2, int y_2) {
 	return print(x_1, y_1, x_2, y_2) - get(x_1, y_1, x_2, y_2);
}

int main() {

	int n;
	scanf("%d", &n);
	forn (j, 2) {
		int l = 1, r = n;
	 	fornr (i, LOG)
	 		if (l + (1 << i) <= r) {
	 		 	int k = printGet(l + (1 << i), 1, r, n);
	 		 	if (k > 0)
	 		 		l += (1 << i);
	 		}
	 	fornr (i, LOG)
	 		if (l <= r - (1 << i)) {
	 		 	int k = printGet(l, 1, r - (1 << i), n);
	 		 	if (k > 0)
	 		 		r -= (1 << i);
	 		}
		ansX_1[j] = l, ansX_2[j] = r;
	 	l = 1, r = n;
	 	fornr (i, LOG)
	 		if (l + (1 << i) <= r) {
	 		 	int k = printGet(ansX_1[j], l + (1 << i), ansX_2[j], r);
	 		 	if (k > 0)
	 		 		l += (1 << i);
	 		}
	 	fornr (i, LOG)
	 		if (l <= r - (1 << i)) {
	 		 	int k = printGet(ansX_1[j], l, ansX_2[j], r - (1 << i));
	 		 	if (k > 0)
	 		 		r -= (1 << i);
	 		}
		ansY_1[j] = l, ansY_2[j] = r;
	}
	printf("! ");
	forn (j, 2)
		printf("%d %d %d %d ", ansX_1[j], ansY_1[j], ansX_2[j], ansY_2[j]);
	puts("");
	fflush(stdout);
	return 0;
}