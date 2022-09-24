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

int N;

// px + y + q >= 0;
// y >= -px - q;
vector<pair<LL, LL> > P, S;
void add(LL p, LL q) {
    P.emplace_back(-p, -q);
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	LL x, y;
	scanf("%lld%lld", &x, &y);
	// bx + c + x^2 - y >= 0;
	add(x, x*x - y);
    }

    sort(P.begin(), P.end());
    REP (i, P.size()) {
	while (S.size() && S.back().first == P[i].first) S.pop_back();
	while (S.size() >= 2u) {
	    pair<LL, LL> a = S.rbegin()[1];
	    pair<LL, LL> b = S.rbegin()[0];
	    pair<LL, LL> c = P[i];
	    if ((a.second - b.second) * (c.first - b.first) >= (b.second - c.second) * (b.first - a.first)) {
		S.pop_back();
	    } else {
		break;
	    }
	}
	S.push_back(P[i]);
    }


    int ans = S.size();
    ans--;
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}