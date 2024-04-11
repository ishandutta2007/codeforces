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

const int INF = 2e9;
const LL LLINF = 2e18;
const int MAXN = 2e5 + 5;

int a[MAXN];
multiset <LL> s;

inline int mod(int cur, int modd)
{
 	int k = cur % modd;
 	if (k < 0)
 		k += modd;
	return k;
}

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, k;
	LL b, c;
	scanf("%d%d" I64 I64, &n, &k, &b, &c);	
	b = min(b, 5 * c);
	forn (i, n)
		scanf("%d", &a[i]);
	sort(a, a + n);
	LL ans = LLINF;
	forn (q, 5)
	{
		//if (q != 2)
		//	continue;
		s.clear();
		LL hold = 0;
		int last = -INF;
		LL curAns = 0;
		forn (i, n)
		{
			int cur = a[i];
			while (mod(cur, 5) != q)
				cur++;			
			if (last != -INF)		
				hold += (cur - last) / 5 * b;
			//printf("tt %d %I64d\n", a[i], hold);
			while (i < n && a[i] <= cur)
			{
			    //printf("i = %d\n", i);
			    if (sz(s) < k)
			    {
			     	s.insert((cur - a[i]) * c - hold);
			    	curAns += (cur - a[i]) * c - hold;
			    }
			    else if (*(--s.end()) > (cur - a[i]) * c - hold)
			    {
			    	//printf("ii = %d\n", i);
			    	curAns += (cur - a[i]) * c - hold - *(--s.end());
			    	s.erase(--s.end());
			     	s.insert((cur - a[i]) * c - hold);
				}
				i++;
			}
			//printf(I64 " " I64 " " I64 "\n", curAns, hold, ans);
			i--;
			if (sz(s) == k)
				ans = min(ans, curAns + hold * k);
			last = cur;
	 	}	
	}
	printf(I64 "\n", ans);
	return 0;
}