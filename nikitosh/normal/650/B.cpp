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

const int MAXN = 5e5 + 5;

int c[MAXN], sumPr[MAXN], sumSuf[MAXN];
char s[MAXN];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, a, b, t;
	scanf("%d%d%d%d\n", &n, &a, &b, &t);
	gets(s);
	forn (i, n)
		if (s[i] == 'w')
			c[i] = b + 1;
		else
			c[i] = 1;
	sumPr[0] = c[0];
	sumSuf[0] = c[0];
	forn (i, n - 1)
		sumPr[i + 1] = sumPr[i] + c[i + 1] + a;		
	forn (i, n - 1)
		sumSuf[i + 1] = sumSuf[i] + c[n - i - 1] + a;		
	if (t < c[0])
	{
	 	printf("0\n");
	 	return 0;
	}
	int ans = 0;
	forn (i, n)
	{
		int l = sumPr[i] + a * i;
		if (t < l)
			continue;
		int k = upper_bound(sumSuf, sumSuf + n, t - l + c[0]) - sumSuf;
		ans = max(ans, k + i);
		//printf("%d %d %d\n", ans, i, l);
	}
	forn (i, n)
	{
		int l = sumSuf[i] + a * i;
		if (t < l)
			continue;
		int k = upper_bound(sumPr, sumPr + n, t - l + c[0]) - sumPr;
		ans = max(ans, k + i);
	}
	ans = min(ans, n);
	printf("%d\n", ans);
	return 0;
}