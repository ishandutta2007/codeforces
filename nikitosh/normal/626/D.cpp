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

const int MAXN = 1e5 + 5, MAX = 5000;

int a[MAXN], sum[MAXN], cnt[MAXN];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n;
	scanf("%d", &n);
	forn (i, n)
		scanf("%d", &a[i]);
	sort(a, a + n);	
	forn (i, n)
		forn (j, i)
			cnt[a[i] - a[j]]++;
	sum[MAX] = cnt[MAX];
	fornr (i, MAX)
		sum[i] = sum[i + 1] + cnt[i];
	LL ans = 0;	
	forab (i, 1, MAX)
	{
	 	forab (j, 1, MAX)
	 	{
	 		ans += cnt[i] * 1ll * cnt[j] * 1ll * sum[i + j + 1];	
	 	}
	}
	LL k = n * (n - 1) / 2;
	printf("%.20f\n", ans * 1.0 / k / k / k);
	return 0;
}