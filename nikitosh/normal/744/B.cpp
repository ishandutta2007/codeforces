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

const int N = 1024, INF = 1e9 + 10;

vi minn[N];

vi fix(const vi &v, int n) {
 	vi u;
 	for (int k : v)
 		if (k < n)
 			u.pb(k + 1);
	return u;
}

vi print(vi v, int n) {
	v = fix(v, n);
	if (sz(v) == 0)
		return vi(n, INF);
 	printf("%d\n", sz(v));
 	for (int l : v)
 		printf("%d ", l);
 	printf("\n");
 	fflush(stdout);
 	vi u(n);
 	forn (i, n)
 		scanf("%d", &u[i]);
	return u;
}

void printAns(vi v) {
	printf("%d\n", -1);
 	for (int l : v)
 		printf("%d ", l);
 	printf("\n");
 	fflush(stdout);
	exit(0);
}

int get(int ind, int k, int row) {
 	int curN = N / 2, curIt = 9;
 	int curAns = INF;
 	while (curN > 0) {
 		if (k >= curN) {
 		    //printf("k = %d curN = %d curIt = %d\n", k, curN, curIt);
 			curAns = min(curAns, minn[curIt * 2 + ind][row]), k -= curN;
 		}
 	 	curIt--;
 	 	curN /= 2;
 	}
 	return curAns;
}

int main() {
#ifdef LOCAL    
	//freopen(FNAME".in", "r", stdin);
	//freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	int two = 1;
	int it = 0;
	while (two < N) {
	    vi v1, v2;
	 	for (int i = 0; i < N; i += 2 * two) {
	 	     forab (j, i, i + two)
	 	     	v1.pb(j);
	 	     forab (j, i + two, i + 2 * two)
	 	     	v2.pb(j);
	 	}	
	 	two *= 2;
	 	minn[it++] = print(v1, n);
	 	minn[it++] = print(v2, n);
	}
	vi ans;
	forn (i, n) {
		ans.pb(min(get(0, i, i), get(1, N - 1 - i, i)));	 	
	}
	printAns(ans);
	return 0;
}