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

const int MAXN = 2e5 + 5;

int xx[MAXN], yy[MAXN];

LL getS(int i, int j, int k)
{
	return abs((xx[j] - xx[i]) * 1ll * (yy[k] - yy[i]) - (yy[j] - yy[i]) * 1ll * (xx[k] - xx[i]));
}

void relax(LL &ans, LL val, int &x, int &y, int &z, int i, int j, int k)
{
	if (ans > val && val > 0)
	{
		ans = val;
		x = i;
		y = j;
		z = k;
	}
}

int main(){
#ifdef LOCAL
	assert(freopen(".in", "r", stdin));
	assert(freopen(".out", "w", stdout));
#endif

	int n, x = 0, y = 0, z = 0;
	LL ans = 0;
	scanf("%d", &n);
	forn (i, n)
		scanf("%d%d", &xx[i], &yy[i]);
	forab (i, 2, n)
		if (getS(0, 1, i) > 0)	
		{
			ans = getS(0, 1, i);
			x = 0, y = 1, z = i;
			forab (j, 2, n)
			{
				if (j != i)
				{
					relax(ans, getS(0, 1, j), x, y, z, 0, 1, j);
					relax(ans, getS(0, i, j), x, y, z, 0, i, j);
					relax(ans, getS(1, i, j), x, y, z, 1, i, j);
				}
			}
			break;
		}
	printf("%d %d %d\n", x + 1, y + 1, z + 1);
	return 0;
}