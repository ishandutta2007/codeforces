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

int N, M;
int K;

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    int limit = 4*N*M - 2*N - 2*M;

    vector<pair<int, string> > ans;
    bool yes;
    if (K > limit) {
	yes = false;
    } else {
	yes = true;

	REP (i, N-1) {
	    if (M > 1) {
		if (3*(M-1) <= K) {
		    ans.emplace_back(M-1, "RDU");
		    K -= 3*(M-1);
		} else {
		    int t = min(M-1, K/3);
		    if (t) {
			ans.emplace_back(t, "RDU");
			K -= 3*t;
		    }
		    assert(K < 3);
		    if (K == 1) {
			ans.emplace_back(1, "R");
		    } else if (K == 2) {
			ans.emplace_back(1, "RD");
		    }
		    K = 0;
		    break;
		}

		{
		    int t = min(M-1, K);
		    if (t) {
			ans.emplace_back(t, "L");
			K -= t;
		    }
		}
	    }
	    if (K) {
		ans.emplace_back(1, "D");
		K--;
	    }
	}

	{
	    int t = min(M-1, K);
	    if (t) {
		ans.emplace_back(t, "R");
		K -= t;
	    }
	}
	{
	    int t = min(M-1, K);
	    if (t) {
		ans.emplace_back(t, "L");
		K -= t;
	    }
	}
	{
	    int t = min(N-1, K);
	    if (t) {
		ans.emplace_back(t, "U");
		K -= t;
	    }
	}

	assert(K == 0);
	if (K) yes = false;
    }


    if (yes) {
	puts("YES");
	printf("%d\n", (int)ans.size());
	EACH (e, ans) printf("%d %s\n", e->first, e->second.c_str());
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}