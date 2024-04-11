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

const int MAX_N = 1005, INF = 1e9;
const int TURN[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

pair<pair<short, short>, short> q[MAX_N * MAX_N * 17];
int a[MAX_N][MAX_N], d[MAX_N][MAX_N][4], used[MAX_N][MAX_N][4];
char s[MAX_N][MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m, sX = 0, sY = 0, fX = 0, fY = 0;
	scanf("%d%d\n", &n, &m);
	forn (i, n) {
	 	gets(s[i]);
	 	forn (j, m) {
	 		if (s[i][j] == 'S') {
	 		 	sX = i, sY = j;
	 		}
	 		if (s[i][j] == 'T') {
	 		 	fX = i, fY = j;
	 		}
	 		if (s[i][j] == '*') {
	 		 	a[i][j] = 1;
	 		}
	 	}
	}
	int head = 8 * m * n, tail = 8 * m * n;
	forn (i, n)
		forn (j, m)
			forn (g, 4)
				d[i][j][g] = INF;
	forn (i, 4) {
		q[tail++] = mp(mp(sX, sY), i);
		d[sX][sY][i] = 0;
	}
	while (tail > head) {
		auto npp = q[head++];
		int x = npp.fs.fs, y = npp.fs.sc, dir = npp.sc;
		if (used[x][y][dir])
			continue;
		used[x][y][dir] = 1;
		if (a[x][y])
			continue;
		forn (i, 4) {
			int nX = x + TURN[i][0], nY = y + TURN[i][1];
			if (nX < 0 || nY < 0 || nX >= n || nY >= m)
				continue;
			if (i == dir) {
				if (d[nX][nY][i] > d[x][y][dir]) {
				 	d[nX][nY][i] = d[x][y][dir];
				 	q[--head] = mp(mp(nX, nY), i);
				}
			} else {
				if (d[nX][nY][i] > d[x][y][dir] + 1) {
				 	d[nX][nY][i] = d[x][y][dir] + 1;
				 	q[tail++] = mp(mp(nX, nY), i);
				}			
			}
		}	
	}
	int minn = 1e9;
	forn (i, 4)
		minn = min(minn, d[fX][fY][i]);
	//printf("%d\n", minn);
	if (minn <= 2)
		puts("YES");
	else
		puts("NO");			               	
	return 0;
}