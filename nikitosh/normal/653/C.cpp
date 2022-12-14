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

int t[MAXN], n;
vi v;

int check(int i)
{
 	if (i % 2 == 0)
 	{
 		if (i > 0 && t[i] >= t[i - 1])
 			return 0;
 		if (i < n - 1 && t[i] >= t[i + 1])
 			return 0;
 	}
 	else
 	{
 		if (t[i] <= t[i - 1])
 			return 0;
 		if (i < n - 1 && t[i] <= t[i + 1])
 			return 0;
 	}
	return 1;
}

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	scanf("%d", &n);
	forn (i, n)
		scanf("%d", &t[i]);
	forn (i, n - 1)
	{
		if (i % 2 == 0 && t[i] >= t[i + 1])
			v.pb(i), i++;
		else if (i % 2 == 1 && t[i] <= t[i + 1])
			v.pb(i), i++;
	}	
	if (sz(v) > 2)
	{
		puts("0");
		return 0;
	}
	int ind = v[0];
	int ans = 0;
	forab (i, ind, ind + 2)
	{
	 	forn (j, n)
			if (j != i)
			{
				if (sz(v) == 2 && abs(j - v[0]) > 2 && abs(j - v[1]) > 2)
					continue;
				swap(t[i], t[j]);
				int ok = 1;
				forab (g, max(0, i - 5), min(n, i + 5))
					ok = min(ok, check(g));
				forab (g, max(0, j - 5), min(n, j + 5))
					ok = min(ok, check(g));
				forab (g, max(0, v[1] - 5), min(n, v[1] + 5))
					ok = min(ok, check(g));
				ans += ok;
				if (i == ind && j == ind + 1 && ok)
					ans--;					
				swap(t[i], t[j]);
			}
	}
	printf("%d\n", ans);
	return 0;
}