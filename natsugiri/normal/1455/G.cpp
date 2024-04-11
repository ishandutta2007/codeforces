#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>
#include<queue>

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

const LL INF = 1LL<<60;
int N, S;
int CNT;

char op[111];

struct MAP {
    map<int, LL> mp;
    priority_queue<pair<LL, int> > pq;
    LL add;

    LL get(int y) {
	auto it = mp.find(y);
	if (it == mp.end()) return INF;
	return it->second + add;
    }

    LL small() {
	while (1) {
	    LL cst = -pq.top().first + add;
	    int y = pq.top().second;
	    if (get(y) != cst) {
		pq.pop();
	    } else {
		return cst;
	    }
	}
    }

    void modify(int y, LL c) {
	mp[y] = c - add;
	pq.emplace(-(c - add), y);
    }

    void add_all(LL c) {
	add += c;
    }

    void eat(MAP &from) {
	if (mp.size() < from.mp.size()) {
	    swap(*this, from);
	}
	EACH (e, from.mp) {
	    int y = e->first;
	    LL cst = e->second + from.add;
	    amin(cst, get(y));
	    modify(y, cst);
	}
    }

    void erase(int y) {
	mp.erase(y);
    }
};

vector<MAP> stk;
LL solve() {
    stk.emplace_back();
    stk.back().modify(0, 0);

    while (CNT < N) {
	scanf("%s", op);
	CNT++;

	if (*op == 's') {
	    int y, v;
	    scanf("%d%d", &y, &v);
	    MAP &mp = stk.back();
	    if (y == S) {
		mp.add_all(v);
	    } else {
		LL small = mp.small();
		mp.add_all(v);
		mp.modify(y, small);
	    }
	} else if (*op == 'i') {
	    int y;
	    scanf("%d", &y);
	    LL cst = stk.back().get(y);
	    stk.back().erase(y);
	    stk.emplace_back();
	    stk.back().modify(y, cst);
	} else {
	    assert(*op == 'e');
	    MAP &from = stk.rbegin()[0];
	    MAP &to = stk.rbegin()[1];

	    to.eat(from);

	    stk.pop_back();
	}
    }

    return stk.back().small();
}

void MAIN() {
    scanf("%d%d", &N, &S);
    LL ans = solve();
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}