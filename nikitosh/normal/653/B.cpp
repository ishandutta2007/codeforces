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

const int MAXN = 100;

int a[MAXN], go[MAXN];
char s[MAXN], t[MAXN];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, q;
	scanf("%d%d", &n, &q);
	forn (qq, q)
	{
		scanf("%s %s", s, t);
		int st = (s[0] - 'a') * 6 + s[1] - 'a';
		go[st] = t[0] - 'a' + 1;
	}	
	int res = 1;
	forn (i, n)
		res *= 6;
	int ans = 0;
	forn (i, res)
	{
		int k = i;
	 	forn (j, n)
	 		a[j] = k % 6, k /= 6;
		bool ok = 1;
		forn (j, n - 1)
		{
			int l = 6 * a[n - j - 1] + a[n - j - 2];
			if (go[l] == 0)
			{
				ok = 0;
				break;
			}
			a[n - j - 2] = go[l] - 1;
		}
		if (ok && a[0] == 0)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}