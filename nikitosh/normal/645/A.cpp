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

const int MAXN = 10;

char s[MAXN][MAXN], t[MAXN], r[MAXN], t2[MAXN], r2[MAXN];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	forn (i, 4)
		gets(s[i]);
	forn (i, 2)
		r[i] = s[0][i];		
	forn (i, 2)
		r[2 + i] += s[1][1 - i];		
	forn (i, 2)
		t[i] = s[2][i];		
	forn (i, 2)
		t[2 + i] += s[3][1 - i];		
	forn (i, 4)
		r[4 + i] = r[i], t[4 + i] = t[i];
	forn (i, 4)
		if (r[i] == 'X')
		{
		    //printf("%d\n", i);
			forn (j, 3)
				r2[j] = r[i + j + 1];
			break;
		}
	forn (i, 4)
		if (t[i] == 'X')
		{
		    //printf("%d\n", i);
			forn (j, 3)
				t2[j] = t[i + j + 1];
			break;
		}
	forn (g, 3)
	{
	    bool ok = 1;
		forn (j, 3)
			if (r2[j] != t2[(j + g) % 3])
			{
				ok = 0;
			}
		if (ok)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}