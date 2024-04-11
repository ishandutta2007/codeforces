#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
LL L, Wmax;

struct Data {
    LL x;
    LL nu, de;
    Data(LL x_, LL nu_, LL de_) {
	x = x_;
	nu = nu_;
	de = de_;
    }

    bool operator<(const Data &y) const {
	return x < y.x;
    }
};

vector<Data> Ri, Le;

void calc(LL x, int v, LL &nu, LL &de) {
    LL l = x;
    LL r = x + L;
    // (l, r);
    if (l < 0 && 0 < r) {
	nu = 0;
	de = 1;
    } else if ((l == 0 || r == 0) && Wmax > 1) {
	nu = 0;
	de = 1;
    } else if (r <= 0) {
	nu = -r;
	de = Wmax + v;
    } else {
	nu = l;
	de = Wmax - v;
    }
}

void MAIN() {
    scanf("%d%lld%lld", &N, &L, &Wmax);
    REP (i, N) {
	int x, v;
	LL nu, de;
	scanf("%d%d", &x, &v);
	calc(x, v, nu, de);
	if (de > 0) {
	    if (v == 1) Ri.emplace_back(Data(x, nu, de));
	    else Le.emplace_back(Data(x, nu, de));
	}
    }

    sort(Ri.begin(), Ri.end());
    sort(Le.begin(), Le.end());

    LL ans = 0;
    EACH (e, Ri) {

	int lo = -1, hi = Le.size();
	while (hi - lo > 1) {
	    int mid = (lo + hi) / 2;
	    LL nu = Le[mid].x + L - e->x;
	    LL de = 2;
	    if (nu >= 0
		    && nu * e->de > e->nu * de
		    && nu * Le[mid].de > Le[mid].nu * de) {
		hi = mid;
	    } else {
		lo = mid;
	    }
	}

	ans += (int)Le.size() - hi;

    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}