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

int N, Q;
struct Data {
    int l, r;
    double p;
    Data(){}
    bool operator<(const Data &y) const {
	return l != y.l? l < y.l:
	    y.r < r;
    }
} D[5011];

int A[100111];

typedef map<int, double> Map;
Map Merge(const Map& a, const Map &b) {
    if (a.empty()) return b;
    if (b.empty()) return a;
    Map nxt;
    EACH (e, a) EACH (f, b)
	nxt[max(e->first, f->first)] += e->second * f->second;
    return nxt;
}

pair<Map, int> rec(int L, int R, int B) {
    int NB = B;
    while (NB < Q && D[NB].l == L && D[NB].r == R) NB++;

    Map cur;
    if (NB == Q || R <= D[NB].l) {
	int a = *max_element(A+L, A+R);
	cur[a] = 1.0;
    } else {
	int last = L;
	while (NB < Q && D[NB].r <= R) {
	    if (last < D[NB].l) {
		pair<Map, int> tmp = rec(last, D[NB].l, NB);
		cur = Merge(cur, tmp.first);
		last = D[NB].l;
		NB = tmp.second;
	    }
	    {
		pair<Map, int> tmp = rec(D[NB].l, D[NB].r, NB);
		cur = Merge(cur, tmp.first);
		last = D[NB].r;
		NB = tmp.second;
	    }
	}

	if (last < R) {
	    pair<Map, int> tmp = rec(last, R, NB);
	    cur = Merge(cur, tmp.first);
	    last = D[NB].r;
	    NB = tmp.second;
	}
    }

    while (B < Q && D[B].l == L && D[B].r == R) {
	Map nxt;
	EACH (e, cur) {
	    nxt[e->first] += (1.0 - D[B].p) * e->second;
	    nxt[e->first+1] += D[B].p * e->second;
	}
	B++;
	swap(cur, nxt);
    }
    return make_pair(cur, NB);
}

int main() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);
    REP (i, Q) scanf("%d%d%lf", &D[i].l, &D[i].r, &D[i].p), D[i].l--;
    sort(D, D+Q);

    pair<Map, int> tmp = rec(0, N, 0);
    double ans = 0;
    EACH (e, tmp.first) ans += e->first * e->second;

    printf("%.9f\n", ans);

    return 0;
}