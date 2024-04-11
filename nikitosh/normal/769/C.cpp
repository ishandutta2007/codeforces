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

const int turn[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}}; //DLRU
const int INF = 1e9;
const char *DIR = "DLRU";
const int MAX_N = 1005;

int a[MAX_N][MAX_N], d[MAX_N][MAX_N];
pii q[MAX_N * MAX_N];
char s[MAX_N];

bool isGood(int x, int y, int n, int m) {
 	return x >= 0 && y >= 0 && x < n && y < m && a[x][y] == 0;
}

void bfs(int x, int y, int n, int m) {
 	int head = 0, tail = 0;
 	forn (i, n)
 		forn (j, m)
 			d[i][j] = INF;
	d[x][y] = 0;
	q[tail++] = mp(x, y);
 	while (tail > head) {
		pii pos = q[head++];
		int x = pos.fs, y = pos.sc;
		forn (i, 4) {
		    int nX = x + turn[i][0], nY = y + turn[i][1];
			if (isGood(nX, nY, n, m) && d[nX][nY] > d[x][y] + 1) {
			 	d[nX][nY] = d[x][y] + 1;
			 	q[tail++] = mp(nX, nY);
			}
		}
 	}
}

void go(int x, int y, int k, int n, int m) {
	if (k == 0)
		return;
 	forn (i, 4) {
 	 	int nX = x + turn[i][0], nY = y + turn[i][1];
 	 	if (isGood(nX, nY, n, m) && d[nX][nY] <= k - 1) {
 	 	 	putchar(DIR[i]);
 	 	 	go(nX, nY, k - 1, n, m);
 	 	 	return;
 	 	}	
 	}
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m, k;
	scanf("%d%d%d\n", &n, &m, &k);
	pii pos;
	forn (i, n) {
	 	gets(s);
	 	forn (j, m) {
	 		if (s[j] == '*')
	 			a[i][j] = 1;
			if (s[j] == 'X')
				pos = {i, j};
		}
	}
	bool canGo = 0;
	forn (i, 4)
		canGo |= isGood(pos.fs + turn[i][0], pos.sc + turn[i][1], n, m);
	if (k % 2 != 0 || !canGo) {
		puts("IMPOSSIBLE");
		return 0;		 	
	}
	bfs(pos.fs, pos.sc, n, m);
	go(pos.fs, pos.sc, k, n, m);
	return 0;
}