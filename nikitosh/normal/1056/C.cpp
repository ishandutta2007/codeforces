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

const int MAX_N = 2005;

int a[MAX_N], used[MAX_N], pr[MAX_N];

int readInt() {
 	int k;
 	scanf("%d", &k);
 	k--;
 	used[k] = 1;
 	return k; 
}

void makeMove(int k) {
	printf("%d\n", k + 1);
	used[k] = 1;
	fflush(stdout);
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m;
	scanf("%d%d", &n, &m);
	forn (i, 2 * n)
		scanf("%d", &a[i]);
	forn (i, 2 * n)
		pr[i] = -1;
	vector<pii> v;
	forn (i, m) {
		int a2, b;
		scanf("%d%d", &a2, &b);
		a2--, b--;
		pr[a2] = b;
		pr[b] = a2;
		v.pb(mp(a2, b));
	}
	int t;
	scanf("%d", &t);
	if (t == 1) {
	 	for (auto np : v) {
	 	 	if (a[np.fs] > a[np.sc]) {
	 	 	 	makeMove(np.fs);
	 	 	 	assert(readInt() == np.sc);
	 	 	} else {
	 	 	 	makeMove(np.sc);
	 	 	 	assert(readInt() == np.fs);
	 	 	}
	 	}
	 	while (1) {
	 		int ind = -1;
	 	 	forn (i, 2 * n)
 	 	 		if (!used[i] && (ind == -1 || a[i] > a[ind])) 
 	 	 			ind = i;
			if (ind == -1)
				break;
			makeMove(ind);
			readInt();
	 	}
	} else {
	 	while (1) {
	 	    int cnt2 = 0;
	 		forn (i, 2 * n)
				cnt2 += !used[i];
		    if (cnt2 == 0) {
		    	break;
		    } 		 			
	 	 	int k = readInt();
	 	 	if (pr[k] != -1) 
	 	 		makeMove(pr[k]);
	 	 	else {
        	 	for (auto np : v) {
        	 		if (used[np.fs])
        	 			continue;
        	 	 	if (a[np.fs] > a[np.sc]) {
        	 	 	 	makeMove(np.fs);
        	 	 	 	assert(readInt() == np.sc);
        	 	 	} else {
        	 	 	 	makeMove(np.sc);
        	 	 	 	assert(readInt() == np.fs);
        	 	 	}
        	 	}
        	 	while (1) {
        	 		int ind = -1;
        	 	 	forn (i, 2 * n)
         	 	 		if (!used[i] && (ind == -1 || a[i] > a[ind])) 
         	 	 			ind = i;
        			if (ind == -1)
        				break;
        			makeMove(ind);
        			int cnt = 0;
        			forn (i, 2 * n)
        				if (!used[i])
        					cnt++;
        			if (cnt == 0)
        				break;
        			readInt();
        	 	} 	
	 	 		break;
	 	 	}
	 	}
	}
	return 0;
}