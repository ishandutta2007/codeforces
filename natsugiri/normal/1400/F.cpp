#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
const int ALPHA_BASE = '1';
const int ALPHA_SIZE = 9;

struct Node {
    LL sum; 
    int mask, head, fail;
    Node() { 
	sum = 0;
	mask = 0;
	head = 0;
	fail = 0;
    }
    int child(char c) const {
	int t = c-ALPHA_BASE;
	if (~mask>>t&1) return -1;
	return head + __builtin_popcount(mask & ((1<<t)-1));
    }
};

vector<Node> nodes;

int get_next(int x, char c) {
    while (x >= 0 && ~nodes[x].mask>>(c-ALPHA_BASE)&1) x = nodes[x].fail;
    if (x < 0) return 0;
    else return nodes[x].child(c);
}

template<class ITER> void build(ITER begin, ITER end) {
    int n = end - begin;
    VI idx(n);
    REP (i, n) idx[i] = i;
    sort(idx.begin(), idx.end(), [&](int i, int j){ return begin[i] < begin[j]; });
    nodes.clear();
    nodes.push_back(Node());
    VI depth, left, right;
    depth.push_back(0); left.push_back(0); right.push_back(n);
    for (int i=0; i<(int)nodes.size(); i++) {
	nodes[i].head = nodes.size();
	int j = left[i];
	while (j < right[i] && (int)begin[idx[j]].size() <= depth[i]) {
	    // nodes[i] is end of string begin[idx[j]];
	    // e.g. nodes[i].sum += value[idx[j]]);
	    nodes[i].sum += 1;
	    j++;
	}
	while (j<right[i]) {
	    const char c = begin[idx[j]][depth[i]];
	    int k = j;
	    while (k < right[i] && c == begin[idx[k]][depth[i]]) k++;
	    nodes.push_back(Node());
	    depth.push_back(depth[i]+1); left.push_back(j); right.push_back(k);
	    nodes[i].mask |= 1<<(c-ALPHA_BASE);
	    j = k;
	}
    }

    nodes[0].fail = -1;
    for (int i=1; i<(int)nodes.size(); i++) {
	int k = nodes[i].head;
	for (int j=0; j<ALPHA_SIZE; j++) if (nodes[i].mask>>j&1) {
	    int f = nodes[i].fail;
	    nodes[k].fail = get_next(f, j+ALPHA_BASE);
	    nodes[k].sum += nodes[nodes[k].fail].sum;
	    k++;
	}
    }
}


int N;
char S[1011];
int X;
vector<string> dict;

int buf[2][5011];
int *cur = buf[0];
int *nxt = buf[1];

void rec(int x, string &stk) {
    if (x == 0) {
	REP (i, stk.size()) {
	    int m = 0;
	    for (int j=i; j<(int)stk.size(); j++) {
		m += stk[j] - '0';
		if (m < X && X % m == 0) return;
	    }
	}
	dict.push_back(stk);
    } else {
	for (int i=2; i<=9 && i <= x; i++) if (X % i) {
	    stk.push_back('0' + i);
	    rec(x-i, stk);
	    stk.pop_back();
	}
    }
}


void MAIN() {
    scanf("%s%d", S, &X);
    N = strlen(S);

    {
	string stk;
	rec(X, stk);
	if (X <= 9) {
	    stk.push_back('0' + X);
	    dict.push_back(stk);
	}

	build(dict.begin(), dict.end());
	//EACH (e, dict) cerr << *e << endl;
	//eprintf("%d %d %d\n", X, (int)dict.size(), (int)nodes.size());
    }

    memset(cur, 0x3f, sizeof buf[0]);
    const int INF = cur[1];
    cur[0] = 0;
    REP (i, N) {
	memset(nxt, 0x3f, sizeof buf[0]);
	REP (j, nodes.size()) amin(nxt[j], cur[j] + 1);

	REP (j, nodes.size()) if (cur[j] < INF) {
	    int k = get_next(j, S[i]);
	    if (nodes[k].sum == 0) {
		amin(nxt[k], cur[j]);
	    }
	}

	swap(cur, nxt);
    }

    int ans = N;
    REP (j, nodes.size()) amin(ans, cur[j]);
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}