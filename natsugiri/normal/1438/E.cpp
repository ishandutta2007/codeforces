#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}
int N;
int A[200011];

LL sums[200011];

int slow() {
    REP (i, N) sums[i+1] = sums[i] + A[i];
    int ret = 0;
    REP (i, N) {
	for (int j=i+2; j<N; j++) {
	    if ((A[i] ^ A[j] ^ (sums[j] - sums[i+1])) == 0) {
		ret++;
	    }
	}
    }

    eprintf("%d slow\n", ret);
    return ret;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    vector<pair<int, int> > ans;
    VI v;

    REP (a, 2) {
	REP (i, N) sums[i+1] = sums[i] + A[i];

	for (int t=30; t>=0; t--) {
	    v.clear();
	    REP (i, N) if ((A[i]>>t) == 1) {
		v.push_back(i);
	    }

	    EACH (e, v) {
		int L = *e;
		int lo = L+2, hi = N;
		while (hi - lo > 1) {
		    int mid = (lo + hi) / 2;
		    if ((sums[mid] - sums[L+1]) >> t) hi = mid;
		    else lo = mid;
		}
		for (int R=lo; R<N; R++) {
		    LL mid = sums[R] - sums[L+1];
		    if ((mid>>t) > 1) break;

		    if ((A[L] ^ A[R] ^ (sums[R] - sums[L+1])) == 0) {
			if (a == 0) {
			    ans.emplace_back(L, R);
			} else {
			    ans.emplace_back(N-1-R, N-1-L);
			}
		    }
		}
	    }
	}

	reverse(A, A+N);
    }

    sort_unique(ans);
    printf("%d\n", (int)ans.size());


//    slow();
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}