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

const int MAXN = 1e5;

int used[MAXN];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, k, a[4];
	scanf("%d%d%d%d%d%d", &n, &k, &a[0], &a[1], &a[2], &a[3]);
	if (n == 4 || k < n + 1)
	{
		puts("-1");
		return 0;
	}
	forn (i, 4)
		a[i]--, used[a[i]] = 1;	
	printf("%d %d ", a[0] + 1, a[2] + 1);
	forn (i, n)
		if (!used[i])
			printf("%d ", i + 1);
	printf("%d %d ", a[3] + 1, a[1] + 1);
	puts("");
	printf("%d %d ", a[2] + 1, a[0] + 1);
	forn (i, n)
		if (!used[i])
			printf("%d ", i + 1);
	printf("%d %d ", a[1] + 1, a[3] + 1);
	puts("");	
			
	return 0;
}