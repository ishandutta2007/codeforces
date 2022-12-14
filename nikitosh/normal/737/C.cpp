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

int a[MAX_N], cnt[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, s;
	scanf("%d%d", &n, &s);
	s--;
	int ans = 0;
	int curMax = 0;
	forn (i, n) {
		scanf("%d", &a[i]);
		if (i == s && a[i] != 0)
			a[i] = 0, ans++;
		cnt[a[i]]++, curMax = max(curMax, a[i]);
	}
	int bad = 0;
	forn (i, n)
		if (i != s && a[i] == 0)
			bad++;
	
	int curCnt = 0;
	int zero = 0, dubls = 0, bestAns = 1e9;
	forab (h, 0, n + 1) {
		curCnt += cnt[h];
		dubls += max(0, cnt[h] - 1);
		zero += (cnt[h] == 0);
		int liars = n - curCnt;
		if (bad + liars + dubls >= zero) {
		    bestAns = min(bestAns, ans + bad + liars + max(zero - bad - liars, 0));			
		}
	}
	printf("%d\n", bestAns);
	/*
	forab (i, 1, curMax + 1) {
		if (cnt[i] == 0) {
		    if (bad == 0) {
		    	while (curMax > i && cnt[curMax] == 0)
		    		curMax--;	
		    	if (curMax <= i)
		    		break;
		    	if (cnt[curMax] > 0)
		    		cnt[curMax]--, bad++, ans++;
		    	while (cnt[curMax] == 0)
		    		curMax--;	
		    }
		    bad--;
        }	 	
	}
	*/	
	return 0;
}