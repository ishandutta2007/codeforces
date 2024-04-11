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

const int MAXN = 300011;
int N;
int A[MAXN], P[MAXN];


struct Node {
    int cnt;
    int le, ri;
    Node() {}
    void clear() {
	cnt = 0;
	le = ri = -1;
    }
} node[31*MAXN];
int node_i;

int insert(int x, int sh, int v) {
    int idx = x;
    if (x == -1) {
	idx = node_i++;
	node[idx].clear();
    }
    if (sh < 0) {
    } else {
	if (v>>sh&1) {
	    node[idx].ri = insert(node[idx].ri, sh-1, v);
	} else {
	    node[idx].le = insert(node[idx].le, sh-1, v);
	}
    }
    node[idx].cnt++;
    return idx;
}

int query_ans;
void query(int x, int sh, int v, int prefix) {
    if (sh < 0) {
	query_ans = prefix;
    } else {
	int le = node[x].le;
	int ri = node[x].ri;
	if (v>>sh&1) {
	    if (ri != -1 && node[ri].cnt) {
		query(ri, sh-1, v, prefix|(1<<sh));
	    } else {
		query(le, sh-1, v, prefix);
	    }
	} else {
	    if (le != -1 && node[le].cnt) {
		query(le, sh-1, v, prefix);
	    } else {
		query(ri, sh-1, v, prefix|(1<<sh));
	    }
	}
    }
    node[x].cnt--;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", P+i);

    node[0].clear();
    node_i++;

    REP (i, N) insert(0, 29, P[i]);
    REP (i, N) {
	query(0, 29, A[i], 0);
	printf("%d%c", A[i] ^ query_ans, " \n"[i==N-1]);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}