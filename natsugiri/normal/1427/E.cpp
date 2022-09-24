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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

const int LOG = 60;
LL B[60];
vector<LL> X;

using Tuple = tuple<LL, char, LL>;
vector<Tuple> ans;

bool add(LL m) {
    assert(0 <= m);
    int cnt = 0;
    bool ret = false;
    REP (i, LOG) if (m>>i&1) {
	if (B[i] == 0) {
	    B[i] = m;
	    ret = true;
	    break;
	} else {
	    cnt++;
	    X.push_back(m ^ B[i]);
	    ans.emplace_back(m, '^', B[i]);
	    m ^= B[i];
	}
    }


    if (!ret) {
	REP (i, cnt) {
	    X.pop_back();
	    ans.pop_back();
	}
	assert(m == 0);
	return false;
    } else {
	return true;
    }
}

bool check() {
    LL m = 1;
    REP (i, LOG) if (m>>i&1) {
	if (B[i] == 0) {
	    return false;
	} else {
	    m ^= B[i];
	    if (m == 0) return true;
	}
    }
    return false;
}

void solve(LL N) {
    X.clear();
    ans.clear();
    memset(B, 0, sizeof B);

    X.push_back(N);
    B[0] = N;

    for (int i=0; i<(int)X.size(); i++) {
	REP (j, i+1) {
	    if (j < i) {
		LL m = X[i] ^ X[j];
		X.push_back(m);
		ans.emplace_back(X[i], '^', X[j]);

		if (add(m)) {
		    if (check()) {
			goto OUT;
		    }
		} else {
		    X.pop_back();
		    ans.pop_back();
		}
	    }
	    {
		LL m = X[i] + X[j];
		X.push_back(m);
		ans.emplace_back(X[i], '+', X[j]);

		if (add(m)) {
		    if (check()) {
			goto OUT;
		    }
		} else {
		    X.pop_back();
		    ans.pop_back();
		}
	    }
	}
    }

    assert(false);
OUT:

    LL m = N;
    REP (i, LOG) if ((m^1)>>i&1) {
	if (B[i] == 0) {
	    assert(false);
	} else {
	    ans.emplace_back(m, '^', B[i]);
	    m ^= B[i];
	    if (m == 1) break;
	}
    }
    assert(m == 1);

    printf("%d\n", (int)ans.size());
    REP (i, ans.size()) {
	LL a, b;
	char c;
	tie(a, c, b) = ans[i];
	printf("%lld %c %lld\n", a, c, b);
    }
}


void MAIN() {
//    for (int i=262143; i<=999999; i+=2) {
//	printf("N = %d\n", i);
//	solve(i);
//	assert((int)ans.size() <= 100000);
//    }
    int N;
    scanf("%d", &N);
    solve(N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}