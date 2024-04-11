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

const int MAX = 100011;
int min_factor[MAX];
vector<int>prime;
void make_prime() {
    assert("Call once" && prime.empty());
    for (int i=2; i<MAX; i+=2) min_factor[i] = 2;
    for (int i=3; i*i<MAX; i++) {
	if (min_factor[i] == 0) {
	    min_factor[i] = i;
	    for (int j=i*i; j<MAX; j+=i)
		if (min_factor[j] == 0) min_factor[j] = i;
	}
    }
    for (int i=2; i<MAX; i++) {
	if (min_factor[i] == 0) min_factor[i] = i;
	if (min_factor[i] == i) prime.push_back(i);
    }
}

int N, Q;
int A[100011];

int prv[100011];
int R[19][100011];

void MAIN() {
    make_prime();

    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);

    memset(prv, -1, sizeof prv);

    REP (i, 100011) prv[i] = N;

    R[0][N] = N;

    for (int i=N; i--;) {
	int a = A[i];
	R[0][i] = R[0][i+1];
	while (a > 1) {
	    int m = min_factor[a];
	    amin(R[0][i], prv[m]);

	    prv[m] = i;
	    while (a % m == 0) a /= m;
	}
    }

    REP (t, 18) {
	REP (i, N+1) {
	    R[t+1][i] = R[t][R[t][i]];
	}
    }

    REP ($, Q) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--;
	int ans = 0;
	for (int t=18; t>=0; t--) {
	    if (R[t][l] < r) {
		ans += 1<<t;
		l = R[t][l];
	    }
	}

	assert(l < r);
	assert(R[0][l] >= r);
	ans++;
	printf("%d\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}