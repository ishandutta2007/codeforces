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

const int MAX_N = 1e5 + 5;

vi g[MAX_N], v;
int used[MAX_N], pr[MAX_N];

void dfs(int u) {
 	v.pb(u);
 	used[u] = 1;
 	for (int w : g[u])
 		if (!used[w])
 			dfs(w);
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, m, x, y;
	scanf("%d%d", &n, &m);	
	forn (i, m)
		scanf("%d%d", &x, &y), x--, y--, g[x].pb(y), g[y].pb(x);
	if (n == 1) {
		if (m > 1) {
         	puts("NO");
         	return 0;
        }
		if (m == 0) {
		 	puts("YES");
		 	printf("1\n1 1\n");
		 	return 0;
		}
		printf("YES\n0\n");
		return 0;
	}	
	if (m > n) {
	 	puts("NO");
	 	return 0;
	}
	bool ok = 1;
	forn (i, n)
		if (sz(g[i]) > 2)
			ok = 0;
	if (!ok) {
		puts("NO");
		return 0;
	} 
	ok = 1;
	forn (i, n)
		for (int k : g[i])
			if (k == i)
				ok = 0;
	if (!ok) {
		puts("NO");
		return 0;
	} 
	forn (i, n)
		pr[i] = -1;
	forn (i, n)
		if (!used[i]) {
		    v.clear();
			dfs(i);
			vi tmp;
			for (int u : v) {
			 	if (sz(g[u]) == 1)
			 		tmp.pb(u);
			}
			if (sz(v) == 1) {
			 	pr[v[0]] = v[0];
			 	continue;
			}
            if (sz(tmp) == 0) {
			 	if (sz(v) == n) {
			 	 	printf("YES\n0\n");
			 	 	return 0;
			 	}
			 	puts("NO");
			 	return 0;
			}
			assert(sz(tmp) == 2);
			pr[tmp[0]] = tmp[1];
			pr[tmp[1]] = tmp[0];
		}
	puts("YES");
	printf("%d\n", n - m);
	int cnt = n - m;
	forn (i, n) {
		forn (g, 2) {
	 	if (pr[i] == -1)
	 		continue;
		forn (j, n)
			if (i != j && pr[j] != -1 && (pr[j] != i || (cnt == 1))) {
				printf("%d %d\n", i + 1, j + 1);
				cnt--;
				int p = pr[i], q = pr[j];
				pr[p] = q;
				pr[q] = p;
				if (p != i)
					pr[i] = -1;
				if (q != j)
					pr[j] = -1;
				//printf("%d %d %d %d\n", i, j, pr[i], pr[j]);
				break;
			}
		}				
	}
	return 0;
}