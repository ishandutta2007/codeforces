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
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FNAME ""

struct VerSeg {
 	int x, y_1, y_2;
 	VerSeg(int x_, int y_1_, int y_2_): x(x_), y_1(y_1_), y_2(y_2_) {}
 	VerSeg() {}
};

struct HorSeg {
 	int y, x_1, x_2;
 	HorSeg(int y_, int x_1_, int x_2_): y(y_), x_1(x_1_), x_2(x_2_) {}
 	HorSeg() {}
};

vector<VerSeg> ver, versAns;
vector<HorSeg> hor, horsAns;
set<pii> was;

//  - n    - m 
// 
const int MAX_N = 2e3 + 100;

int n, m, paired[2 * MAX_N], used[2 * MAX_N], maxIndependent[2 * MAX_N];
vector <int> g[MAX_N];
pii a[MAX_N];

bool dfs(int v) {
	if (used[v])
		return false;
	used[v] = 1;
	for(int to : g[v]) 
		if (paired[to] == -1 || dfs(paired[to])) {
			paired[to] = v;
			paired[v] = to;
			return true;
		}
	return false;
}

int kuhn() {
	int ans = 0;
	forn(i, n + m)
		paired[i] = -1;
	for (int run = 1; run;) { 
		run = 0;
		memset(used, 0, sizeof(used));
		forn(i, n) 
			if (!used[i] && paired[i] == -1 && dfs(i)) {
				ans++;
				run = 1;
			}
	}
	return ans;
}
//       ,    ,   -   .
//Max  - A+, B-
//Min     - A-, B+ 

void dfsCoverIndependent(int v) {
	if (used[v])
		return;
	used[v] = 1;
	for(int to : g[v]) 
		if (!used[to])
			used[to] = 1, dfsCoverIndependent(paired[to]);
}

// 
void findCoverIndependent() {
	memset(used, 0, sizeof(used));
	forn(i, n)
		if (paired[i] == -1)
			dfsCoverIndependent(i);
	forn(i, n)
		if(used[i])
			maxIndependent[i] = 1;
	forab(i, n, n + m)
		if (!used[i])
			maxIndependent[i] = 1;
}


int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int k;
	scanf("%d", &k);
	forn (i, k) {
	 	scanf("%d%d", &a[i].fs, &a[i].sc);
	}
	sort(a, a + k);
	forab (i, 1, k)
		if (a[i].fs == a[i - 1].fs) {
		 	ver.pb(VerSeg(a[i].fs, a[i - 1].sc, a[i].sc));
		}
	forn (i, k)
		swap(a[i].fs, a[i].sc);
	sort(a, a + k);
	forn (i, k)
		swap(a[i].fs, a[i].sc);
	forab (i, 1, k)
		if (a[i].sc == a[i - 1].sc) {
		 	hor.pb(HorSeg(a[i].sc, a[i - 1].fs, a[i].fs));
		}
	n = sz(ver), m = sz(hor);
	forn (i, n)
		forn (j, m) {
		 	if (ver[i].y_1 < hor[j].y && ver[i].y_2 > hor[j].y && hor[j].x_1 < ver[i].x && hor[j].x_2 > ver[i].x)
		 		g[i].pb(n + j), g[n + j].pb(i);
		}
	kuhn();
	findCoverIndependent();

	was.clear();
	forn (i, n) {
		if (maxIndependent[i]) {
	 		int ind = n;
		 	forab (j, i, n) {
		 	 	if (!maxIndependent[j] || ver[j].x != ver[i].x) {
		 	 	    ind = j;
		 	 	 	break;
		 	 	}
		 		was.insert(mp(ver[j].x, ver[j].y_1));
		 		was.insert(mp(ver[j].x, ver[j].y_2));
		 	}
	 	 	versAns.pb(VerSeg(ver[i].x, ver[i].y_1, ver[ind - 1].y_2));
	 	 	i = ind - 1;
		 }
	}
	forn (i, k) 
		if (!was.count(a[i]))
			versAns.pb(VerSeg(a[i].fs, a[i].sc, a[i].sc));

	was.clear();
	forn (i, m) {
		if (maxIndependent[n + i]) {
	 		int ind = m;
		 	forab (j, i, m) {
		 	 	if (!maxIndependent[n + j] || hor[j].y != hor[i].y) {
		 	 	    ind = j;
		 	 	 	break;
		 	 	}
		 		was.insert(mp(hor[j].x_1, hor[j].y));
		 		was.insert(mp(hor[j].x_2, hor[j].y));
		 	}
	 	 	horsAns.pb(HorSeg(hor[i].y, hor[i].x_1, hor[ind - 1].x_2));
	 	 	i = ind - 1;
		 }
	}
	forn (i, k) 
		if (!was.count(a[i]))
			horsAns.pb(HorSeg(a[i].sc, a[i].fs, a[i].fs));

	printf("%d\n", sz(horsAns));
	for (auto seg : horsAns)
		printf("%d %d %d %d\n", seg.x_1, seg.y, seg.x_2, seg.y);

	printf("%d\n", sz(versAns));
	for (auto seg : versAns)
		printf("%d %d %d %d\n", seg.x, seg.y_1, seg.x, seg.y_2);
	return 0;
}