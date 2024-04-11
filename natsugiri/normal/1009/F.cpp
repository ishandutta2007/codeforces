#include<deque>
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
const int MAXN = 1000011;

struct Data {
    vector<int> d;
    int idx;

    Data() {
	idx = -1;
    }

    void inc() {
	if (d.empty()) {
	    idx = 0;
	    d.push_back(1);
	} else {
	    idx++;
	    d.push_back(1);
	    if (d[(int)d.size()-1-idx] == 1) idx = 0;
	}
    }

    void eat(Data &t) {
	if (d.size() < t.d.size()) {
	    swap(d, t.d);
	    swap(idx, t.idx);
	}
	if (idx != -1) {
	    int value = d[(int)d.size()-1-idx];
	    if (idx < (int)t.d.size()) value += t.d[(int)t.d.size()-1-idx];
	    REP (i, t.d.size()) {
		int new_value = d[(int)d.size()-1-i] + t.d[(int)t.d.size()-1-i];
		if (value < new_value || (value == new_value && i < idx)) {
		    idx = i;
		    value = new_value;
		}
	    }

	    REP (i, t.d.size()) {
		d[(int)d.size()-1-i] += t.d[(int)t.d.size()-1-i];
	    }
	}
    }
};
Data D[MAXN];

int N;
VI G[MAXN];
int depth[MAXN];
int ans[MAXN];

VI ord;

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    ord.reserve(N);
    ord.push_back(0);
    memset(depth, -1, sizeof depth);
    depth[0] = 0;
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (depth[*e] == -1) {
	    depth[*e] = depth[v] + 1;
	    ord.push_back(*e);
	}
    }

    REP (i_, N) {
	int v = ord[N-1-i_];
	EACH (e, G[v]) if (depth[*e] > depth[v]) {
	    D[v].eat(D[*e]);
	    D[*e].d = VI();
	}
	
	D[v].inc();
	ans[v] = D[v].idx;
    }

    REP (i, N) printf("%d\n", ans[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}