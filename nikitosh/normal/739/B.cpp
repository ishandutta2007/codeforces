#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
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

const int MAX_N = 2e5 + 5;

int a[MAX_N];
vector<pair<ll, int>> path;
int sum[MAX_N], ans[MAX_N];
vector<pair<int, ll>> g[MAX_N];

int curSum = 0;

void dfs(int v, ll len) {
	if (sz(path)) {
		int k = lower_bound(all(path), mp(len - a[v], -1)) - path.begin();
		sum[path.back().sc]++;
		if (k != 0)
			sum[path[k - 1].sc]--;
	}
	path.pb(mp(len, v));
	for (auto np : g[v])
		dfs(np.fs, len + np.sc);
	path.pop_back();
}

int calcAns(int v) {
	int curSum = 0;
 	for (auto np : g[v])
 		curSum += calcAns(np.fs);
 	curSum += sum[v];
 	ans[v] = curSum;
 	return curSum;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

    int n;
    scanf("%d", &n);
	forn (i, n)
		scanf("%d", &a[i]);
	forn (i, n - 1) {
	 	int p, w;
	 	scanf("%d%d", &p, &w);
	 	g[p - 1].pb(mp(i + 1, w));
	}
	dfs(0, 0);	
	calcAns(0);
	forn (i, n)
		printf("%d ", ans[i]);
	return 0;
}