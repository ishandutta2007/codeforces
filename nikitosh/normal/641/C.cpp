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

const int MAX_N = 2e6 + 5;

int pr[MAX_N];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, q;
	scanf("%d%d", &n, &q);	
	LL t1 = 0;
	LL t2 = 1;
	forn (i, q)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			int k;
			scanf("%d", &k);
			if (k < 0)
				k += n;
			t1 += k, t2 += k;
		}
		else
		{
			t1 ^= 1;
			t2 ^= 1;
		}
	}
	forn (i, n)
	{
		int k = 0;
		if (i % 2 == 0)
			k = (t1 + i) % n;
		if (i % 2 == 1)
			k = (t2 + i - 1) % n;
		pr[k] = i;
	}
	forn (i, n)
		printf("%d ", pr[i] + 1);
	return 0;
}