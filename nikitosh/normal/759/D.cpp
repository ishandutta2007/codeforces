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

const int MAX_N = 5e3 + 5, ALPHA = 26, MOD = 1e9 + 7;

char s[MAX_N];
ll tmp[MAX_N];
int d[MAX_N][MAX_N], last[ALPHA + 5], c[MAX_N][MAX_N];

inline int add(int a, int b) {
 	a += b;
 	return a >= MOD ? a - MOD : a;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d\n", &n);
	gets(s);
	forn (i, ALPHA)
		last[i] = -1;
	c[0][0] = 1;
	forab (i, 1, n + 1) {
	 	c[i][0] = 1;
	 	forab (j, 1, i + 1)
	 		c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
	}
	forn (i, n) {
		forn (j, i + 2)
			tmp[j] = 0;
		tmp[0] = 1;
		forn (j, ALPHA) 
			if (j != s[i] - 'a' && last[j] != -1) {
				int ind = last[j];
			 	forab (k, 1, i + 1)
			 		tmp[k] += d[ind][k];
			}
		d[i][0] = 1;
		forn (j, i + 1)
			d[i][j + 1] = tmp[j] % MOD; 
		//forn (j, i + 2)
		//	printf("d[%d][%d] = %d\n", i, j, d[i][j]);
		last[s[i] - 'a'] = i;
	}
	int ans = 0;
	forn (j, ALPHA)
		if (last[j] != -1) 
			forab (i, 1, n + 1) 
				ans = (ans + d[last[j]][i] * 1ll * c[n - 1][i - 1]) % MOD;			                                 	
	printf("%d\n", ans);
	return 0;
}