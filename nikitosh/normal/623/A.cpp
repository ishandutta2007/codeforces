#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

typedef long long LL;
typedef unsigned long long ULL;
typedef double dbl;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int MAXN = 505;
const char *ALPHA = "bac";

int a[MAXN][MAXN], used[MAXN];
vi g[MAXN];

void dfs(int v, int col, bool &flag)
{
	used[v] = col;
	for (int u : g[v])
	{
		if (used[u] > 0)
		{
			if (col != 3 - used[u])
				flag = 1;
		}
		else
			dfs(u, 3 - col, flag);
	}
}

int main(){
#ifdef LOCAL
	assert(freopen("test.in", "r", stdin));
	assert(freopen("test.out", "w", stdout));
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	forn (i, m)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--,u--;
		a[v][u] = a[u][v] = 1;
	}
	forn (i, n)
		forn (j, i)
			if (!a[i][j])
				g[i].pb(j), g[j].pb(i);
	bool flag = false;
	bool was = false;
	forn (i, n)
		if (sz(g[i]) > 0 && !used[i])
		{
			if (was)
			{
				puts("No");
				return 0;
			}
			dfs(i, 1, flag);
			was = 1;
		}
	if (flag)
	{
		puts("No");
		return 0;
	}
	forn (i, n)
		if (used[i] == 1)
		{
			forn (j, n)
				if (used[j] == 2 && a[i][j] == 1)
				{
					puts("No");
					return 0;
				}
		}
		puts("Yes");
		forn (i, n)
			printf("%c", ALPHA[used[i]]);
	return 0;
}