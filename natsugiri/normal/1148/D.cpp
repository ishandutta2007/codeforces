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

struct Data {
    int a, b, i;
    Data(){}
    Data(int a_, int b_, int i_) {
	a = a_;
	b = b_;
	i = i_;
    }

    bool operator<(const Data &o) const {
	if (b <= o.a) return false;
	if (o.b <= a) return true;
	return i < o.i;
    }
};

VI ans;
void solve(vector<Data> U) {
    sort(U.begin(), U.end());
    EACH (e, U) ans.push_back(e->i+1);
    EACH (e, U) eprintf("%d < %d > ", e->a, e->b);
    eprintf("\n");
}
vector<Data> U, D;
int N;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int a, b;
	scanf("%d%d", &a, &b);
	if (a < b) U.emplace_back(a, b, i);
	else D.emplace_back(-a, -b, i);
    }

    if (U.size() >= D.size()) solve(U);
    else solve(D);
    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}