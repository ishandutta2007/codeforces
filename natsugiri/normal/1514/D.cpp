#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
int Q;
int A[300011];

const int MAGIC = 500;

struct Query {
    int l, r, i;

    bool operator<(const Query &o) const {
	if (l / MAGIC != o.l / MAGIC) return l < o.l;
	return r < o.r;
    }
} query[300011];

int C[300011];
int D[300011];
int ma;

void ADD(int a, int sgn) {
    D[C[a]]--;
    C[a] += sgn;
    D[C[a]]++;
    while (D[ma+1]) ma++;
    while (D[ma] == 0) ma--;
}

int ans[300011];

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);
    REP (i, Q) {
	scanf("%d%d", &query[i].l, &query[i].r);
	query[i].l--;
	query[i].i = i;
    }

    sort(query, query+Q);
    D[0] = N;

    int L = 0, R = 0;
    REP (i_, Q) {
	const Query q = query[i_];

	while (q.l < L) ADD(A[--L], 1);
	while (R < q.r) ADD(A[R++], 1);
	while (L < q.l) ADD(A[L++], -1);
	while (q.r < R) ADD(A[--R], -1);

	int len = q.r - q.l;
	int other = len - ma;
	if (other + 1 >= ma) ans[q.i] = 1;
	else ans[q.i] = ma - other;
    }
    REP (i, Q) printf("%d\n", ans[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}