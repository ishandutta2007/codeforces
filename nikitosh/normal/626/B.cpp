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

const int MAXN = 1e5 + 5;
const char *t = "BGR";

char s[MAXN];
int was[MAXN], go[MAXN];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n;
	scanf("%d\n", &n);
	gets(s);
	forn (i, n)
		forn (j, 3)
			if (s[i] == t[j])
				was[j]++;
	if (was[0] && was[1] && was[2])
	{
	 	puts("BGR");
	 	return 0;
	}
	forn (j, 3)
	{
		bool ok = 1;
		forn (g, 3)
		{
			if ((g == j) && !was[g])
				ok = 0; 	
			if (g != j && was[g])
				ok = 0;
		}
		if (ok)
		{
		 	printf("%c\n", t[j]);
		 	return 0;
		}
	}
	forn (j, 3)
		if (!was[j])
		{
			go[j] = 1;
		 	forn (g, 3)
		 		if (g != j && was[g] > 1)
		 		 	go[3 - j - g] = 1;
			forn (g, 3)
				if (go[g])
					printf("%c", t[g]);
			return 0;
		}
	assert(0);
	return 0;
}