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

const int MAX_N = 1005, LOG = 10;

int a[MAX_N][MAX_N], down[MAX_N][MAX_N], righ[MAX_N][MAX_N], sq[MAX_N][MAX_N], logg[MAX_N];
short ST[MAX_N][MAX_N][LOG][LOG];

inline int readInt() {
  int s = 0, c = getchar(), x = 0;
  if (c == '-')
    s = 1, c = getchar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getchar();
  return s ? -x : x;
}

template <class T> inline void writeInt( T x ) {
  if (x < 0)
    putchar('-'), x = -x;
  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n--)
    putchar(s[n]);
}


int max4(int a, int b, int c, int d) {
 	return max(max(a, b), max(c, d));
}

int get(int x_1, int y_1, int x_2, int y_2) {
 	int n = x_2 - x_1 + 1, m = y_2 - y_1 + 1;
 	int l1 = logg[n], l2 = logg[m];
 	return max4(ST[x_1][y_1][l1][l2], ST[x_2 - (1 << l1) + 1][y_1][l1][l2], ST[x_1][y_2 - (1 << l2) + 1][l1][l2], ST[x_2 - (1 << l1) + 1][y_2 - (1 << l2) + 1][l1][l2]); 
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

    int n = readInt(), m = readInt();
	forn (i, n)
		forn (j, m)
			a[i][j] = readInt();			
	int q = readInt();
	fornr (i, n)
		fornr (j, m) {
			if (i == n - 1)
				down[i][j] = a[i][j];
			else if (a[i][j])
				down[i][j] = down[i + 1][j] + 1;
			if (j == m - 1)
				righ[i][j] = a[i][j];
			else if (a[i][j])
				righ[i][j] = righ[i][j + 1] + 1;
			if (i == n - 1 || j == m - 1)
				sq[i][j] = a[i][j];
			else
				sq[i][j] = min(min(righ[i][j], down[i][j]), sq[i + 1][j + 1] + 1);		 	
		}
	logg[1] = 0;
	forab (i, 2, MAX_N)
		logg[i] = logg[i / 2] + 1;
	forn (x, n)
		forn (y, m)
			ST[x][y][0][0] = sq[x][y];
	forn (i, LOG)
		forn (x, n - (1 << i) + 1) {
	 		if (i != 0)
		 		forn (y, m)
					ST[x][y][i][0] = max(ST[x][y][i - 1][0], ST[x + (1 << (i - 1))][y][i - 1][0]);	 			
			forab (j, 1, LOG) 
				forn (y, m - (1 << j) + 1)		 	
		 			ST[x][y][i][j] = max(ST[x][y][i][j - 1], ST[x][y + (1 << (j - 1))][i][j - 1]);
		}	
	/*
	forn (i, n) {
		forn (j, m)
			printf("%d ", sq[i][j]);
		puts("");
	}
	*/
	forn (qq, q) {
		int x_1 = readInt(), y_1 = readInt(), x_2 = readInt(), y_2 = readInt();
	 	int bl = 0, br = min(x_2 - x_1 + 1, y_2 - y_1 + 1) + 1;	
	 	x_1--, y_1--, x_2--, y_2--;
	 	while (br - bl > 1) {
	 	 	int bm = (bl + br) / 2;
	 	 	if (get(x_1, y_1, x_2 - bm + 1, y_2 - bm + 1) >= bm)
	 	 		bl = bm;
	 	 	else
	 	 		br = bm;
	 	}
		writeInt(bl);
		putchar('\n');
	}
	return 0;
}