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

const int MAX_N = 1005;

int l[MAX_N], r[MAX_N], used[MAX_N], ans[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n) 
		scanf("%d", &l[i]);
	forn (i, n) 
		scanf("%d", &r[i]);
	int cur = n;
	while (1) {
	 	bool was = 0;
	 	forn (i, n)
	 		if (!used[i])
	 			was = 1;
		if (!was)
			break;
		int cnt = 0;
		forn (i, n)
			if (!used[i] && l[i] == 0 && r[i] == 0) {
			 	cnt++;
			 	used[i] = 1;
				ans[i] = cur;
			}
		if (cnt == 0) {
		 	puts("NO");
		 	return 0;
		}
		int curR = cnt, curL = 0;
		forn (i, n) {
			if (ans[i] == cur)
				curR--, curL++;
			else if (!used[i]) {
			 	if (l[i] < curL || r[i] < curR) {
			 	 	puts("NO");
			 	 	return 0;
			 	}
			 	l[i] -= curL, r[i] -= curR;
			}
		}
		cur--;		
	}
	puts("YES");
	forn (i, n)
		printf("%d ", ans[i]);		

	return 0;
}