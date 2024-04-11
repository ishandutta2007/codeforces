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

int N, M;
VI A[100011];
int C[100011];
int ans[100011];

void MAIN() {
    scanf("%d%d", &N, &M);
    int LIMIT = (M+1) / 2;

    REP (i, M) {
	A[i].clear();
	int len;
	scanf("%d", &len);
	A[i].resize(len);
	REP (j, len) scanf("%d", &A[i][j]);
    }

    REP (i, N+1) C[i] = 0;
    
    REP (i, M) {
	if (A[i].size() == 1u) {
	    ans[i] = A[i][0];
	    C[A[i][0]]++;
	} else {
	    ans[i] = -1;
	}
    }

    REP (i, M) if (ans[i] == -1) {
	EACH (e, A[i]) if (C[*e]+1 <= LIMIT) {
	    ans[i] = *e;
	    C[*e]++;
	    break;
	}
    }
    
    if (*min_element(ans, ans + M) == -1 || *max_element(C+1, C+N+1) > LIMIT) {
	puts("NO");
    } else {
	puts("YES");
	rprintf("%d", ans, ans+M);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}