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

const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 5;

int last[MAXN], sum[MAXN];
char s[MAXN];

inline int add(int x)
{
 	if (x >= MOD)
 		x -= MOD;
 	if (x < 0)
 		x += MOD;
	return x;
}

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, k;
	scanf("%d%d\n", &n, &k);	
	gets(s);
	int m = strlen(s);
	forn (i, k)
		last[i] = -1;
	sum[0] = 1;
	forn (i, m)
	{
		int c = s[i] - 'a';
		int k = 0;
		if (last[c] != -1)
			k = sum[last[c]];
		sum[i + 1] = add(2 * sum[i] - k);
		last[c] = i;	
	}
	forab (j, m, m + n)
	{
		int minn = n + m + 1, c = -1;
		forn (i, k)
			if (last[i] < minn)
			{
				minn = last[i];
				c = i;
			}	
		int k = 0;
		if (last[c] != -1)
			k = sum[last[c]];
		sum[j + 1] = add(2 * sum[j] - k);
		last[c] = j;			
	}
	printf("%d\n", sum[n + m]);
	return 0;
}