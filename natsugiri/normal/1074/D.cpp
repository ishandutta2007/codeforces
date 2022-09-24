#include<map>
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
map<int, pair<int, int> > U; // U[x] := (parent, diff);

pair<int, int> eval(int x) {
    auto it = U.find(x);
    if (it == U.end()) {
	return make_pair(x, 0);
    } else {
	pair<int, int> p = eval(it->second.first);
	it->second.first = p.first;
	it->second.second ^= p.second;
	return it->second;
    }
}

void MAIN() {
    int Q;
    scanf("%d", &Q);
    int last = 0;

    REP ($, Q) {
	char op[11];
	scanf("%s", op);
	if (*op == '1') {
	    int l, r, x;
	    scanf("%d%d%d", &l, &r, &x);
	    l ^= last;
	    r ^= last;
	    x ^= last;
	    if (l > r) swap(l, r);
	    l--;

	    pair<int, int> lp = eval(l);
	    pair<int, int> rp = eval(r);
	    if (lp.first == rp.first) {
		// ignore
	    } else {
		if (lp.first > rp.first) swap(lp, rp);
		U[rp.first] = make_pair(lp.first, x ^ lp.second ^ rp.second);
	    }

	} else {
	    int l, r;
	    scanf("%d%d", &l, &r);
	    l ^= last;
	    r ^= last;
	    if (l > r) swap(l, r);
	    l--;
	    pair<int, int> lp = eval(l);
	    pair<int, int> rp = eval(r);

	    if (lp.first == rp.first) {
		last = lp.second ^ rp.second;
		printf("%d\n", last);
	    } else {
		puts("-1");
		last = 1;
	    }
	}
//	EACH (e, U) printf("(%d %d %d)", e->first, e->second.first, e->second.second);
//	puts("");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}