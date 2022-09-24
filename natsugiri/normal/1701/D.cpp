#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
int A[500011];
int B[500011];
vector<pair<int, int> > Z[500011];

void MAIN() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
	int b;
	scanf("%d", &b);
	B[i] = b;
    }


    REP (i, N+1) Z[i].clear();

    for (int i=1; i<=N; i++) {
	int b = B[i];
	if (b == 0) {
	    Z[i+1].emplace_back(N, i);
	    // eprintf("%d %d\n", i+1, N);
	} else {
	    int max_a = max(1, i / b);
	    int min_a = min(N, i / (b+1) + 1);
	    Z[min_a].emplace_back(max_a, i);
	    // eprintf("%d %d\n", min_a, max_a);
	}
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
    for (int a=1; a<=N; a++) {
	EACH (e, Z[a]) {
	    Q.push(*e);
	}

	assert(Q.size());
	pair<int, int> p = Q.top();
	Q.pop();
	assert(a <= p.first);
	A[p.second] = a;
    }
    rprintf("%d", A+1, A+N+1);

#ifdef LOCAL
    for (int i=1; i<=N; i++) assert(i / A[i] == B[i]);
#endif
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}