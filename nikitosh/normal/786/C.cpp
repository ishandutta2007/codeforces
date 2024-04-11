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

const int MAX_N = 4e5 + 5, INF = 1e9;

vi v[MAX_N];
int last[MAX_N], a[MAX_N];
map<int, int> prevv;

int go(int ver, int l, int up, int tSize) {
	int cur = 1;
	while (ver > 1) {
		if (ver % 2 == 0)
			cur += lower_bound(all(v[ver + 1]), l) - v[ver + 1].begin();
		ver /= 2;
		if (cur > up)
			break;
	}
	//printf("%d %d\n", ver, cur);
	if (cur <= up)
		return INF;
	ver = 2 * ver + 1;
	while (sz(v[ver])) {	
		if (ver >= tSize)
			break;
		int k = lower_bound(all(v[2 * ver + 1]), l) - v[2 * ver + 1].begin();
		if (cur - k <= up)
			ver = 2 * ver + 1;
		else {
			cur -= k;
			ver *= 2;
		}
	}
	return ver;
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
   	forn (i, n) {
   		if (!prevv.count(a[i]))
   			last[i] = -1;
   		else
   			last[i] = prevv[a[i]];
   		prevv[a[i]] = i;
	}
	int tSize = 1;
	while (tSize < n)
		tSize *= 2;
	forn (i, n)
		v[tSize + i].pb(last[i]);
	for (int i = tSize - 1; i >= 1; i--) {
	    v[i].resize(sz(v[2 * i]) + sz(v[2 * i + 1]));
		merge(all(v[2 * i]), all(v[2 * i + 1]), v[i].begin());
	}
	forab (k, 1, n + 1) {
	 	int l = 0, cnt = 0;
	 	while (l < n) {
	 		l = go(l + tSize, l, k, tSize) - tSize;
	 		//printf("%d\n", l);
	 		cnt++; 	
	 	}
	 	printf("%d ", cnt);
	}
	puts("");
	return 0;
}