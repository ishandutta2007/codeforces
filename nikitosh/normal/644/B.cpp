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

set<pair<LL, int>> s;
LL d[MAXN], t[MAXN], q[MAXN], ans[MAXN];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, b;
	scanf("%d%d", &n, &b);
	forn (i, n)
	{
		scanf(I64 I64, &t[i], &d[i]);	
		s.insert(mp(t[i], i + 1));
		ans[i] = -1;
	}
	int head = 0, tail = 0;
	int busy = 0;
	while (sz(s))
	{
		auto np = *s.begin();
		s.erase(s.begin());
		LL t = np.fs;
		if (np.sc < 0)
		{
			ans[-np.sc - 1] = np.fs;
			busy = 0;
			if (tail > head)
			{
			    int v = q[head++];
				s.insert(mp(t + d[v - 1], -v));	
				busy = 1;
			}
		}
		else
		{
			if (busy == 0)
			{
				busy = 1;
				int v = np.sc;
				s.insert(mp(t + d[v - 1], -v));
		 	}	
		 	else if (tail - head < b)
		 		q[tail++] = np.sc;
		}
	}
	forn (i, n)
		printf(I64 " ", ans[i]);
    return 0;
}