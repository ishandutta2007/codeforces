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

const int MAXN = 2e5 + 5;

char s[MAXN];
int sum[MAXN];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, k;
	scanf("%d%d\n", &n, &k);
	gets(s);
	forn (i, n)
		sum[i + 1] = sum[i] + (s[i] == '0');
	int l = 0, r = n;
	while (r - l > 1)
	{
	 	int m = (l + r) / 2;
	 	bool ok = 0;
	 	forn (i, n)
	 	{
	 	    int rr = sum[i + m + 1];
	 	    if (i + m + 1 > n)
	 	    	rr = sum[n];
	 	    int ll = 0;
	 	    if (i >= m)
	 	    	ll = sum[i - m];
	 		if (s[i] == '0' && rr - ll >= k + 1)
	 			ok = 1;
		}
		if (ok)
			r = m;
		else
			l = m;
	}
		printf("%d\n", r);
	return 0;
}