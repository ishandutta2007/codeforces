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

const int MAX_N = 200;

long double p[MAX_N][MAX_N], d[MAX_N][MAX_N];
int a[MAX_N][MAX_N];

vi dfs(int v, int n) {
 	if (v >= n) {
 		d[v][v - n] = 0.;
 		p[v][v - n] = 1.;
 		return {v - n};
 	}
	auto ind1 = dfs(2 * v, n);
 	auto ind2 = dfs(2 * v + 1, n);

    long double maxx1 = 0;
    for (auto u : ind1) {
		maxx1 = max(maxx1, d[2 * v][u]); 	 	
 	}
    long double maxx2 = 0;
    for (auto u : ind2) {
		maxx2 = max(maxx2, d[2 * v + 1][u]); 	 	
 	}

 	for (auto u : ind1) {
 	 	long double curP = 0;
 	 	for (auto w : ind2) {
			curP += p[2 * v + 1][w] * a[u][w] / 100.;
 	 	}
 	 	p[v][u] = curP * p[2 * v][u];
 	 	d[v][u] = d[2 * v][u] + maxx2 + p[v][u] * sz(ind1);
 	}

 	for (auto u : ind2) {
 	 	long double curP = 0;
 	 	for (auto w : ind1) {
			curP += p[2 * v][w] * a[u][w] / 100.;
 	 	}
 	 	p[v][u] = curP * p[2 * v + 1][u];
 	 	d[v][u] = d[2 * v + 1][u] + maxx1 + p[v][u] * sz(ind1);
 	}

 	ind1.insert(ind1.end(), ind2.begin(), ind2.end());
 	return ind1;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int k;
	scanf("%d", &k);
	int n = 1 << k;
	forn (i, n)
		forn (j, n)
			scanf("%d", &a[i][j]);
	dfs(1, n);
	
	long double ans = 0;
	forn (i, n) 
		ans = max(ans, d[1][i]);
	printf("%.20f\n", (double) ans);
	return 0;
}