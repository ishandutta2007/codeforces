#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<tuple>

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

int N;
LL A[1011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    using Tuple = tuple<int,int,int>;
    vector<Tuple> ans;

    for (int i=0; i+1<N; i+=2) {
	ans.emplace_back(1, i, i+1);
	ans.emplace_back(2, i, i+1);
	ans.emplace_back(2, i, i+1);
	ans.emplace_back(1, i, i+1);
	ans.emplace_back(2, i, i+1);
	ans.emplace_back(2, i, i+1);
    }


    printf("%d\n", (int)ans.size());
    EACH (e, ans) {
	int t, i, j;
	tie(t, i, j) = *e;
	printf("%d %d %d\n", t, i+1, j+1);
	assert(i < j);
	if (t == 1) {
	    A[i] += A[j];
	} else {
	    A[j] -= A[i];
	}
	// rprintf("%lld", A, A+N);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}