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

const int MAXN = 1e6 + 5, MAXLOG = 21;

int a[MAXN], b[MAXN], maxx[MAXN][MAXLOG], minn[MAXN][MAXLOG], logg[MAXN], ans[MAXN];

inline pii getMinMax(int l, int r)
{
 	int len = logg[r - l];
 	return mp(max(maxx[l][len], maxx[r - (1 << len)][len]), min(minn[l][len], minn[r - (1 << len)][len]));
}

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, k;
	scanf("%d%d", &n, &k);
	forn (i, n)
		scanf("%d", &a[i]), a[i] *= 100;
	forn (i, n)
		scanf("%d", &b[i]);	
	forn (i, n)
		maxx[i][0] = a[i], minn[i][0] = b[i];

	forab (i, 2, n + 2)
		logg[i] = logg[i / 2] + 1;
	forab (j, 1, MAXLOG)
	{
	 	forn (i, n)
	 	{
	 		maxx[i][j] = maxx[i][j - 1];
	 		minn[i][j] = minn[i][j - 1];
			if (i + (1 << (j - 1)) < n)
			{
				maxx[i][j] = max(maxx[i][j], maxx[i + (1 << (j - 1))][j - 1]);
				minn[i][j] = min(minn[i][j], minn[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	forn (i, n)
	{
		int l = 0, r = n - i;
		while (r - l > 1)
		{
			int m = (l + r) / 2;
			auto np = getMinMax(i, i + m);
			if (np.fs > np.sc)
				r = m;
			else
				l = m;
		}	
		//printf("%d %d\n", i, r);
		forab (j, max(1, r - 1), r + 1)
		{
			auto np = getMinMax(i, i + j);
			ans[i] = max(ans[i], min(np.fs, np.sc));
		}
	}
	//forn (i, n)
	//	printf("%d ", ans[i]);
	sort(ans, ans + n);
	double cur = k * 1. / n;
	int t = n - 1;
	double allAns = 0;
	forn (i, n)
	{
		allAns += ans[i] * cur;
		cur *= (t - k + 1) * 1. / t;
		t--;
	}
	printf("%.20f\n", allAns);
	return 0;
}