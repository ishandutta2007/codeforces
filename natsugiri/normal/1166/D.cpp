#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

LL A, B, M;

void MAIN() {
    scanf("%lld%lld%lld", &A, &B, &M);

    if (A == B) {
	printf("1 %lld\n", A);
    } else if (A+1 <= B && B <= A+M) {
	printf("2 %lld %lld\n", A, B);
    } else if (A < B) {
	REP (t, 55) {
	    LL low = (A+1)<<t;
	    LL high = (A+M)<<t;
	    if (B < low) break;

	    if (low <= B && B <= high) {
		int k = t;
		vector<LL> ans;
		B -= A<<k;
		ans.push_back(A);
		k--;
		while (k > 0) {
		    LL c = 1LL<<k;
		    LL r = min((B-c)/c, M);
		    ans.push_back(r);
		    B -= r<<k;
		    k--;
		}
		{
		    ans.push_back(B-B/2);
		    ans.push_back(B/2);
		    REP (i, ans.size()) {
			REP (j, i) ans[i] += ans[j];
		    }
		}
		printf("%d ", t+2);
		rprintf("%lld", ans.begin(), ans.end());
		return ;
	    }
	}

	puts("-1");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}