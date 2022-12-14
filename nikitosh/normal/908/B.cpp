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

const int MAX_N = 105;
const int TURN[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char s[MAX_N][MAX_N];
char t[MAX_N];
int p[4];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m;
	scanf("%d%d\n", &n, &m);
	int sX = 0, sY = 0, fX = 0, fY = 0;
	forn (i, n) {
		gets(s[i]);
		forn (j, m) {
			if (s[i][j] == 'S')
				sX = i, sY = j;				
			if (s[i][j] == 'E')
				fX = i, fY = j;				
		}
	}	
	gets(t);
	forn (i, 4)
		p[i] = i;
	int len = strlen(t);
	int ans = 0;
	do {
		int curX = sX, curY = sY;
		bool ok = 1;
		forn (i, len) {
			int dir = p[t[i] - '0'];
			curX += TURN[dir][0], curY += TURN[dir][1];
			if (curX < 0 || curY < 0 || curX >= n || curY >= m || s[curX][curY] == '#') {
			 	ok = 0;
			 	break;
			}
			if (s[curX][curY] == 'E') {
			    ok = 1;
				break;
			}
		}	
		if (ok && s[curX][curY] != 'E')
			ok = 0;
		if (ok)
			ans++;
	} while (next_permutation(p, p + 4));
	printf("%d\n", ans);
	return 0;
}