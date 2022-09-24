#include<set>
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

struct Data { 
    int p, q, r;
    Data() {}
    Data(int p_, int q_, int r_) : p(p_), q(q_), r(r_) {}

    // decreasing
    bool operator<(const Data &y) const {
	return r > y.r;
    }
};
vector<Data> D;

int N, P, Q, R;

void MAIN() {
    scanf("%d%d%d%d", &N, &P, &Q, &R);
    int N3 = N*3;
    D.reserve(N3 + 1);
    REP (i, N) {
	int p, q, r;
	scanf("%d%d%d", &p, &q, &r);
	D.emplace_back(p, q, R);
	D.emplace_back(p, Q, r);
	D.emplace_back(P, q, r);
    }


    D.emplace_back(0, 0, 0);
    sort(D.begin(), D.end());

    LL ans = 0; 

    set<pair<int, int> > se;
    se.emplace(P+1, 0);
    se.emplace(0, Q+1);
    LL cur = 0;

    for (int i=0; i<N3;) {
	int stop = i;

	while (stop < N3 && D[i].r == D[stop].r) stop++;

	for (int j=i; j<stop; j++) {
	    pair<int, int> key(D[j].p, D[j].q);
	    auto it = se.upper_bound(key);

	    if (D[j].q <= it->second) continue;
	    pair<int, int> z = *it;
	    --it;
	    while (it != se.begin()) {
		if (it->first <= D[j].p && it->second <= D[j].q) {
		    pair<int, int> y = *it;
		    se.erase(it--);
		    cur -= (LL)(y.first - it->first) * (y.second - z.second);
		} else {
		    break;
		}
	    }

	    it = se.upper_bound(key);
	    {
		z = *it;
		it--;
		cur += (LL)(key.first - it->first) * (key.second - z.second);
		it++;
		se.insert(it, key);
	    }
	}
	LL r_high = D[i].r;
	LL r_low = D[stop].r;
	ans += cur * (r_high - r_low);

	i = stop;
    }

    ans = (LL) P * Q * R - ans;

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}