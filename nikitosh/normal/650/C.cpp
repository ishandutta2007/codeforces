#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end() 

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

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAXN = 1e6 + 5;

vector <int> a[MAXN], ans[MAXN], lef[MAXN], righ[MAXN], up[MAXN], down[MAXN], used[MAXN];
pair <int, pii> b[MAXN];
int lastX[MAXN], lastY[MAXN];
map <int, int> last;
int minn;
vector <pii> v;

void dfs(int x, int y)
{
 	used[x][y] = 1;
 	if (lastX[x] != -1)
		minn = max(minn, ans[x][lastX[x]] + (a[x][lastX[x]] != a[x][y]));
	lastX[x] = y;
	if (lastY[y] != -1)
		minn = max(minn, ans[lastY[y]][y] + (a[lastY[y]][y] != a[x][y]));
	lastY[y] = x;
	v.pb(mp(x, y));
	if (lef[x][y] != -1 && !used[x][lef[x][y]])
 		dfs(x, lef[x][y]);	
 	if (righ[x][y] != -1 && !used[x][righ[x][y]])
 		dfs(x, righ[x][y]);	
 	if (up[x][y] != -1 && !used[up[x][y]][y])
 		dfs(up[x][y], y);	
 	if (down[x][y] != -1 && !used[down[x][y]][y])
 		dfs(down[x][y], y);	
}

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, m, pos = 0;
	scanf("%d%d", &n, &m);
	forn (i, n)
	{
	    a[i].resize(m);
	    ans[i].resize(m);
	    used[i].resize(m);
	    lef[i].resize(m);
	    righ[i].resize(m);
		up[i].resize(m);
		down[i].resize(m);
		forn (j, m)
			scanf("%d", &a[i][j]), b[pos++] = mp(a[i][j], mp(i, j)), lef[i][j] = -1, righ[i][j] = -1, up[i][j] = -1, down[i][j] = -1;
	}
	forn (i, n)
	{
	    last.clear();
		forn (j, m)
		{
			if (last.count(a[i][j]))
				lef[i][j] = last[a[i][j]], righ[i][last[a[i][j]]] = j;
			last[a[i][j]] = j;
		}
	}
	forn (j, m)
	{
	 	last.clear();
	 	forn (i, n)
	 	{
	 		if (last.count(a[i][j]))
				up[i][j] = last[a[i][j]], down[last[a[i][j]]][j] = i;
			last[a[i][j]] = i;
	 	}	
	}
	forn (i, n)
		lastX[i] = -1;
	forn (i, m)
		lastY[i] = -1;
	sort(b, b + pos);
	forn (i, pos)
	{
	 	int x = b[i].sc.fs, y = b[i].sc.sc;
	 	if (used[x][y])
	 		continue;
        v.clear();
        minn = 1;
        dfs(x, y);
        for (auto np : v)
        	ans[np.fs][np.sc] = minn;
	}
	forn (i, n)
	{
		forn (j, m)
			printf("%d ", ans[i][j]);
		puts("");
	}
	return 0;
}