#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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

int N, M;
int A[300011];
int B[300011];

bool use[300011];

bool solve(int K) {
    memset(use, 0, sizeof (bool) * N);

    int cst = 0;
    int pos = K;
    REP (i, N) {
	if (!use[pos]) {
	    int cnt = 0;
	    int x = pos;
	    while (!use[x]) {
		cnt++;
		use[x] = true;
		x = (A[x] + K) % N;
	    }
	    cst += cnt-1;
	}

	pos++;
	if (pos == N) pos = 0;
    }

    return cst <= M;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i), A[i]--;

    REP (i, N) {
	B[i] = i - A[i];
	if (B[i] < 0) B[i] += N;
    }

    VI ans;
    sort(B, B+N);
    for (int i=0; i<N; ) {
	int j = i;
	while (j < N && B[i] == B[j]) j++;
	if (j-i >= N - 2*M) {
	    if (solve(B[i])) {
		ans.push_back(B[i]);
	    }
	}
	i = j;
    }

    if (ans.empty()) {
	puts("0");
    } else {
	printf("%d ", (int)ans.size());
	rprintf("%d", ans.begin(), ans.end());
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}