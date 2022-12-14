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

const int MAX_N = 1e6 + 5;
const int TURN[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
const int TURN1[2][2] = {{0, -1}, {1, 0}};
const int TURN2[2][2] = {{-1, 0}, {0, 1}};

int n, m;
char s[MAX_N];
vector<vi> a, visited;
vector<pii> q[2];

bool good(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m;
}

void dfs(int i, int j, int curVal) {
	visited[i][j] = curVal;
	for (int g = 0; g < 8; g++) {
		int nX = i + TURN[g][0];
		int nY = j + TURN[g][1];
		if (good(nX, nY) && !visited[nX][nY]) {
			bool was = a[nX][nY];
			if (curVal == 1) {
				if (nX == i && nY == j - 1)
					was = 1;
				if (nX == i + 1 && nY == j)
					was = 1;
			}
			if (curVal == 2) {
				if (nX == i - 1 && nY == j)
					was = 1;
				if (nX == i && nY == j + 1)
					was = 1;
			}
			if (was)
				dfs(nX, nY, curVal);
		}
	}
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	scanf("%d%d\n", &n, &m);
	a.resize(n);
	visited.resize(n);
	forn (i, n)
		a[i].resize(m), visited[i].resize(m);
	forn (i, n) {
		scanf(" %s", s);
		forn (j, m)
			if (s[j] == '#')
				a[i][j] = 1;
			else
				a[i][j] = 0;
	}
	forn (i, n)
		forn (j, m)
			if (a[i][j]) {
				if (j == 0 || i == n - 1)
					q[0].pb(mp(i, j));
				if (i == 0 || j == m - 1)
					q[1].pb(mp(i, j));
			}
	forn (g, 2) {
		for (auto& np: q[g]) {
			if (!visited[np.fs][np.sc])
				dfs(np.fs, np.sc, g + 1);
		}
		if (g == 0) {
			for (auto& np : q[1]) 
				if (visited[np.fs][np.sc]) {
					puts("0");
					return 0;
				}
		}	
	}
	forn (i, n)
		forn (j, m) {
			if ((i == 0 && j == 0) || (i == n - 1 && j == m - 1))
				continue;
			bool was1 = (j == 0 || i == n - 1);
			bool was2 = (i == 0 || j == m - 1);
			forn (g, 8) {
				int nX = i + TURN[g][0];	
				int nY = j + TURN[g][1];	
				if (good(nX, nY)) {
					if (visited[nX][nY] == 1)
						was1 = 1;
					if (visited[nX][nY] == 2)
						was2 = 1;					
				}
			}
			if (was1 && was2) {
				puts("1");
				return 0;
			}
		}
	puts("2");
	return 0;
}