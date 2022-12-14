#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAX_N = 522;

int a[MAX_N], b[MAX_N], last[2 * MAX_N], d[MAX_N][MAX_N];
pii pr[MAX_N][MAX_N];
set<int> s;
map<int, int> ma;
vi numbers;

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, m;
	scanf("%d", &n);
	forn (i, n)
		scanf("%d", &a[i]), s.insert(a[i]);	
	scanf("%d", &m);
	forn (i, m)
		scanf("%d", &b[i]), s.insert(b[i]);	
	
	int it = 0;
	for (auto k : s)
		ma[k] = it++, numbers.pb(k);
	
	forn (i, n)
		a[i] = ma[a[i]];
	forn (i, m)
		b[i] = ma[b[i]];

	forn (i, n) {
		forn (j, (n + m))
			last[j] = -1;
	 	forn (j, m) {
	 		last[b[j]] = j;
	 		if (a[i] != b[j])
	 			continue;
	 		d[i][j] = 1;
	 		pr[i][j] = mp(-1, -1);
	 		forn (g, i) 
	 			if (a[g] < a[i] && last[a[g]] != -1) {
	 			 	if (d[i][j] < d[g][last[a[g]]] + 1) {
	 			 	 	d[i][j] = d[g][last[a[g]]] + 1;
	 			 	 	pr[i][j] = mp(g, last[a[g]]);
	 			 	}
	 			}
	 	}
	}
	int x = 0, y = 0, maxx = 0;
	forn (i, n)
		forn (j, m)
			if (d[i][j] > maxx) 
				maxx = d[i][j], x = i, y = j;
	printf("%d\n", d[x][y]);
	if (d[x][y] == 0)
		return 0;
	vi v;
	while (x >= 0 && y >= 0) {
		v.pb(a[x]);
		int x2 = pr[x][y].fs;
		y = pr[x][y].sc;
		x = x2;
	}
	reverse(all(v));
	for (int k : v)
		printf("%d ", numbers[k]);
	return 0;
}