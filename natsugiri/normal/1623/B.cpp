#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
int L[1011];
int R[1011];
bool use[1011];

using Tuple = tuple<int, int, int>;
vector<Tuple> ans;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d%d", L+i, R+i);
	L[i]--;
    }

    memset(use, 0, sizeof (use[0]) * N);
    ans.clear();

    REP (t, N) {
	int best = 10000;
	int besti = 0;
	REP (i, N) if (!use[i] && R[i] - L[i] < best) {
	    best = R[i] - L[i];
	    besti = i;
	}

	int left_i = -1, right_i = -1;
	REP (i, N) if (use[i]) {
	    if (L[i] == L[besti] && (left_i == -1 || R[left_i] < R[i])) left_i = i;
	    if (R[i] == R[besti] && (right_i == -1 || L[i] < L[right_i])) right_i = i;
	}

	use[besti] = true;

	int k = -1;
	if (left_i == -1 && right_i == -1) {
	    k = L[besti];
	} else if (left_i == -1) {
	    k = L[besti];
	} else if (right_i == -1) {
	    k = R[besti]-1;
	} else {
	    k = R[left_i];
	}
	ans.emplace_back(L[besti], R[besti], k);
    }

    reverse(ans.begin(), ans.end());
    EACH (e, ans) {
	int l, r, k;
	tie(l, r, k) = *e;
	printf("%d %d %d\n", l+1, r, k+1);
    }
    printf("\n");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}