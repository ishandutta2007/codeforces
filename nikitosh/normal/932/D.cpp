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

const int MAX_N = 4e5 + 5, MAX_LOG = 20;

int upVertexMax[MAX_N][MAX_LOG], upVertexSum[MAX_N][MAX_LOG], upLengthSum[MAX_N][MAX_LOG];
ll upValueMax[MAX_N][MAX_LOG], upValueSum[MAX_N][MAX_LOG], c[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int queries;
	scanf("%d", &queries);
	int last = 0;
	int cnt = 1;
	forn (i, MAX_LOG) {
		upVertexMax[cnt][i] = cnt;
		upVertexSum[cnt][i] = cnt;
		upValueMax[cnt][i] = 0;
		upValueSum[cnt][i] = 0;
		upLengthSum[cnt][i] = 0;
	}

	forn (qq, queries) {
		int t;
		ll p, q;
		scanf("%d" I64 I64, &t, &p, &q);
		ll r = p ^ last, w = q ^ last;
		//cerr << t << " " << r << " " << w << endl;
		if (t == 1) {
			cnt++;
			c[cnt] = w;
			upVertexMax[cnt][0] = r;
			upValueMax[cnt][0] = w;
			forab (i, 1, MAX_LOG) {
				upVertexMax[cnt][i] = upVertexMax[upVertexMax[cnt][i - 1]][i - 1];
				upValueMax[cnt][i] = max(upValueMax[cnt][i - 1], upValueMax[upVertexMax[cnt][i - 1]][i - 1]);
			}	
			if (upValueMax[r][MAX_LOG - 1] < w) {
				upVertexSum[cnt][0] = cnt;
				upValueSum[cnt][0] = 0;
				upLengthSum[cnt][0] = 0;
		   	}
			else {
				fornr (i, MAX_LOG)
					if (upValueMax[r][i] < w)
						r = upVertexMax[r][i];
				if (c[r] < w)
					r = upVertexMax[r][0];
				assert(c[r] >= w);
				upVertexSum[cnt][0] = r;
				upValueSum[cnt][0] = c[r];
				upLengthSum[cnt][0] = 1;
			}
			forab (i, 1, MAX_LOG) {
				upVertexSum[cnt][i] = upVertexSum[upVertexSum[cnt][i - 1]][i - 1];
				upValueSum[cnt][i] = upValueSum[cnt][i - 1] + upValueSum[upVertexSum[cnt][i - 1]][i - 1]; 	
				upLengthSum[cnt][i] = upLengthSum[cnt][i - 1] + upLengthSum[upVertexSum[cnt][i - 1]][i - 1]; 	
			}
		} else {
			if (w < c[r]) {
			 	last = 0;
			} else {
				w -= c[r];
				int curVertex = r;
				last = 1;
				fornr (i, MAX_LOG)
					if (upValueSum[curVertex][i] <= w) {
						w -= upValueSum[curVertex][i];
						last += upLengthSum[curVertex][i];
						curVertex = upVertexSum[curVertex][i];
					}
			}
			printf("%d\n", last); 	
		}
	}	

	return 0;
}