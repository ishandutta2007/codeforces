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

const int MAXN = 105;

int used[MAXN];

int main(){
#ifdef LOCAL
	assert(freopen(".in", "r", stdin));
	assert(freopen(".out", "w", stdout));
#endif

	int n, k;
	scanf("%d", &n);
	int it = 0;
	forn (i, n)
	{
		forn (j, n)
			used[j] = 0;
		forn (j, n)
			scanf("%d", &k), used[k]++;
		bool was = 0;
		forn (j, n)	
			if (used[j] > 1)
			{
				printf("%d ", j);
				was = 1;
			}
		if (!was)
			printf("%d ", n - it), it++;		
	}	

	return 0;
}