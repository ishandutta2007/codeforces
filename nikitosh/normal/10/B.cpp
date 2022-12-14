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

const int INF = 1e9;
const int MAX_N = 205;

int go[MAX_N][MAX_N], used[MAX_N][MAX_N];

int sum(int l, int r) {
 	return r * (r + 1) / 2 - l * (l - 1) / 2;
}

int calc(int l, int r, int c) {
 	if (l >= c)
 	 	return sum(l - c, r - c);
	if (c >= r)
		return sum(c - r, c - l);
	return sum(0, c - l) + sum(0, r - c);
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, k;
	scanf("%d%d", &n, &k);
	int c = k / 2;
	forn (tt, n) {
		int a;
		scanf("%d", &a);
		int ans = INF, x0 = 0, y0 = 0;
		forn (i, k) {
			go[i][k] = 0;
			fornr (j, k)
				if (used[i][j])
					go[i][j] = 0;
				else
					go[i][j] = go[i][j + 1] + 1;
		   	forn (j, k)
		   		if (go[i][j] >= a) {
		   			int l = abs(i - c) * a + calc(j, j + a - 1, c);
		   	        //printf("%d\n", l);
		   			if (l < ans || (l == ans && (i < x0 || (i == x0 && j < y0)))) 
		   				ans = l, x0 = i, y0 = j;
		   		}
		}
		if (ans == INF) {
			puts("-1");
			continue;
		}
	   	forab (i, y0, y0 + a)
			used[x0][i] = 1;
		printf("%d %d %d\n", x0 + 1, y0 + 1, y0 + a);	
	}	
	
	return 0;
}