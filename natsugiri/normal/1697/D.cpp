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

int N;
int A[1011];
int L[26];

int query(int l, int r) {
    printf("? 2 %d %d\n", l+1, r);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

void MAIN() {
    scanf("%d", &N);

    REP (t, 26) L[t] = -1;

    int cnt = 1;
    VI V;
    L[0] = 0;
    for (int i=1; i<N; i++) {
	V.clear();
	REP (t, 26) if (L[t] != -1) {
	    V.push_back(L[t]);
	}
	sort(V.begin(), V.end());
	int lo = -1, hi = V.size();
	while (hi - lo > 1) {
	    int mid = (lo + hi) / 2;
	    int q = query(V[mid], i+1);
	    if (q == (int)V.size() - mid + 1) {
		hi = mid;
	    } else {
		lo = mid;
	    }
	}

	if (lo == -1) {
	    A[i] = cnt;
	    L[cnt] = i;
	    cnt++;
	} else {
	    REP (t, 26) if (L[t] == V[lo]) {
		A[i] = t;
		L[t] = i;
		break;
	    }
	}
    }

    REP (t, 26) if (L[t] != -1) {
	printf("? 1 %d\n", L[t] + 1);
	fflush(stdout);
	static char s[11];
	scanf("%s", s);
	L[t] = *s;
    }

    printf("! ");
    REP (i, N) putchar(L[A[i]]);
    putchar('\n');
    fflush(stdout);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}