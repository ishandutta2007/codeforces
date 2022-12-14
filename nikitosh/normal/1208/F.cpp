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

const int MAX_N = 2e6 + 5, MAX_B = 21;

int a[MAX_N], fst[MAX_N], snd[MAX_N];

void optimize(int ind, int val) {
 	if (snd[ind] < val && fst[ind] != val)
 		snd[ind] = val;
 	if (fst[ind] < snd[ind])
 		swap(fst[ind], snd[ind]);
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
	forn (i, MAX_N)
		fst[i] = snd[i] = -1;
	fornr (i, n) {
	 	if (snd[a[i]] != -1)
	 		continue;
	 	optimize(a[i], i);
	}
	fornr (i, MAX_N) {
		if (fst[i] == -1)
			continue;
	 	forn (j, MAX_B) {
			if (i & (1 << j)) {
			 	int k = i ^ (1 << j);
			 	optimize(k, snd[i]);
			 	optimize(k, fst[i]);
	 	 	}
	 	}
	}
	int ans = 0;
	forn (i, n) {
		int curAns = 0;
		int remMask = 0;
	 	fornr (j, MAX_B) {
	 		if (a[i] & (1 << j))
	 			curAns |= (1 << j);
	 		else {
	 		 	int newMask = remMask | (1 << j);
	 		 	if (snd[newMask] > i) {
	 		 	 	remMask = newMask;
	 		 	 	curAns |= (1 << j);
	 		 	}
	 	 	}
	 	}
	 	ans = max(ans, curAns);
	}
	printf("%d\n", ans);
	return 0;
}