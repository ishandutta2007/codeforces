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

const int MAX = 1e7;

int maxx[2], used[MAX];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int a, b;
	scanf("%d%d", &a, &b);
	forab (i, 1, a + 1)
		used[2 * i]++;
    forab (i, 1, b + 1)
		used[3 * i]++;	
	maxx[0] = 2 * a + 2;
	maxx[1] = 3 * b + 3;
	forn (i, MAX)
	{
		if (used[i] > 1)
		{
		 	used[i] = 1;
		 	if (maxx[0] <= maxx[1])
		 	{
		 		used[maxx[0]]++;
		 		maxx[0] += 2;
		 	}
		 	else
		 	{
		 		used[maxx[1]]++;
		 		maxx[1] += 3;
		 	}
		}
	}	
	printf("%d\n", max(maxx[0] - 2, maxx[1] - 3));
	return 0;
}