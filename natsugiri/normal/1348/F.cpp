#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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

int N;
int A[200011];
int B[200011];
int ans[200011];
VI H[200011];
pair<int, int> pa[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", A+i, B+i), A[i]--;

    REP (i, N) H[A[i]].push_back(i);

    priority_queue<pair<int, int> > Q;

    REP (i, N) {
	EACH (e, H[i]) Q.emplace(-B[*e], *e);

	assert(Q.size());
	assert(i < -Q.top().first);

	auto a = Q.top(); Q.pop();
	ans[a.second] = i;
    }

    int x = -1, y = -1;
    REP (i, N) {
	EACH (e, H[i]) Q.emplace(-B[*e], *e);

	auto a = Q.top(); Q.pop();
	if (Q.size()) {
	    auto b = Q.top();
	    if (A[b.second] <= i && i < B[b.second]
		    && A[a.second] <= ans[b.second] && ans[b.second] < B[a.second]) {
		x = a.second;
		y = b.second;
		break;
	    }
	}
    }

    REP (i, N) ans[i]++;
    if (x == -1) {
	puts("YES");
	rprintf("%d", ans, ans+N);
    } else {
	puts("NO");
	rprintf("%d", ans, ans+N);
	swap(ans[x], ans[y]);
	rprintf("%d", ans, ans+N);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}