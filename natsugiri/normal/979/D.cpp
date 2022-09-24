#include<cassert>
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

namespace BINARY_TRIE {
;
const int MAXN = 1000000;
const int BITS = 17; // assert(BITS < 32);
const unsigned MASK = (1<<BITS)-1;

struct Node {
    int cnt; // # values stored;
    unsigned mi;
    Node *ch0, *ch1;

    void clear() {
	cnt = 0;
	mi = ~0u;
	ch0 = ch1 = 0;
    }

    int cnt0() const {
	return ch0? ch0->cnt: 0;
    }

    int cnt1() const {
	return ch1? ch1->cnt: 0;
    }
};

const int NODES = MAXN * BITS;
Node nodes[NODES];
int node_i;

void clear_all() {
    node_i = 0;
}

Node* new_node() {
    Node *x = &nodes[node_i++];
    x->clear();
    return x;
}

Node* add(Node *x, unsigned v, int cnt, int sh=BITS-1) {
    if (!x) {
	x = new_node();
    }
    x->cnt += cnt;
    amin(x->mi, v);
    if (sh == -1) {
    } else if (v >> sh & 1) {
	x->ch1 = add(x->ch1, v, cnt, sh-1);
    } else {
	x->ch0 = add(x->ch0, v, cnt, sh-1);
    }
    return x;
}

unsigned solve(Node *x, unsigned most, unsigned mask) {
    for (int sh=BITS; sh--;) {
	if (!x || !x->cnt || x->mi > most) return ~0;
	if (mask>>sh&1) {
	    if (x->cnt0()) { x = x->ch0; }
	    else { x = x->ch1; }
	} else {
	    if (x->cnt1() && x->ch1->mi <= most) { x = x->ch1; }
	    else { x = x->ch0; }
	}
    }
    if (!x || !x->cnt || x->mi > most) return ~0;
    return x->mi;
}
}; // namespace BINARY_TRIE;

const int SIZE = 100011;
const int MAGIC = 300;
const int BITS = 17;

int C[SIZE];
BINARY_TRIE::Node* B[MAGIC+1];

void task1() {
    int U;
    scanf("%d", &U);
    C[U]++;
    if (C[U] > 1) return;

    // total O(MAGIC * SIZE);
    for (int k=1; k<=MAGIC && k<=U; k++) if (U % k == 0) {
	B[k] = BINARY_TRIE::add(B[k], U, 1);
    }
}

int task2() {
    int X, K, S;
    scanf("%d%d%d", &X, &K, &S);

    if (X % K) {
	return -1;
    }

    if (1 > S-X) {
	return -1;
    }

    if (K <= MAGIC) {
	// O(log SIZE);
	int t = BINARY_TRIE::solve(B[K], S-X, X);
	return t;
    } else {
	// O(SIZE / MAGIC);
	int ans = -1;
	
	for (int v=K; X+v <= S; v+=K) if (C[v]) {
	    if (ans == -1 || (X^ans)<(X^v)) ans = v;
	}

	return ans;
    }
}

void MAIN() {
    assert((1<<BITS) > SIZE);
//    int cnt = 0;
//    for (int t=1; t<=MAGIC; t++) {
//	int tmp = 0;
//	for (int i=1; i<=100000; i++) {
//	    if (i % t == 0) tmp++;
//	}
//	cnt += tmp;
//    }
//    printf("%d\n", cnt);

    int Q;
    scanf("%d", &Q);

    REP ($, Q) {
	char t[11];
	scanf("%s", t);
	if (*t == '1') {
	    task1();
	} else {
	    int ans = task2();
	    printf("%d\n", ans);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}