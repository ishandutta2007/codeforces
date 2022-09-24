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

const int ALPHA_BASE = 'a';
const int ALPHA_SIZE = 26;

struct Node {
    int sum;
    int mask;
    int head;
    int fail;
    Node() { 
	sum = 0;
	mask = 0;
	head = 0;
	fail = 0;
    }

    int child(char c) const {
	return head + __builtin_popcount(mask & ((1<<(c-ALPHA_BASE))-1));
    }
};

vector<Node> nodes;

template<class ITER> void build(ITER begin, ITER end) {
    int n = end - begin;
    VI idx(n);
    REP (i, n) idx[i] = i;
    sort(idx.begin(), idx.end(), [&](int i, int j){ return begin[i] < begin[j]; });
    nodes.clear();
    nodes.push_back(Node());
    nodes.back().head = 1;
    VI depth, left, right;
    depth.push_back(0);
    left.push_back(0);
    right.push_back(n);
    for (int i=0; i<(int)nodes.size(); i++) {
	nodes[i].head = nodes.size();
	int j = left[i];
	while (j < right[i] && (int)begin[idx[j]].size() <= depth[i]) {
	    // add(i, begin[idx[j]]);
	    nodes[i].sum += 1;
	    j++;
	}
	while (j<right[i]) {
	    const char c = begin[idx[j]][depth[i]];
	    int k = j;
	    while (k < right[i] && c == begin[idx[k]][depth[i]]) k++;
	    nodes.push_back(Node());
	    depth.push_back(depth[i]+1);
	    left.push_back(j);
	    right.push_back(k);
	    nodes[i].mask |= 1<<(c-ALPHA_BASE);
	    j = k;
	}
    }

    nodes[0].fail = -1;
    for (int i=1; i<(int)nodes.size(); i++) {
	int k = nodes[i].head;
	for (int j=0; j<ALPHA_SIZE; j++) if (nodes[i].mask>>j&1) {
	    int f = nodes[i].fail;
	    while (f >= 0 && ~nodes[f].mask>>j&1) f = nodes[f].fail;
	    if (f >= 0) {
		nodes[k].fail = nodes[f].child(j+ALPHA_BASE);
		nodes[k].sum += nodes[nodes[k].fail].sum;
	    } else {
		nodes[k].fail = -1;
	    }
	    k++;
	}
    }
}

VI run(const string &t) {
    VI v(t.size());
    int x = 0;
    REP (i, t.size()) {
	while (x >= 0 && ~nodes[x].mask>>(t[i]-ALPHA_BASE)&1) x = nodes[x].fail;
	if (x < 0) x = 0;
	else x = nodes[x].child(t[i]);
	v[i] += nodes[x].sum;
    }
    return v;
}

char buf[200011];
string T;
string S[200011];
int N;

void MAIN() {
    scanf("%s", buf);
    T = buf;
    scanf("%d", &N);
    REP (i, N) {
	scanf("%s", buf);
	S[i] = buf;
    }

    build(S, S+N);
    VI head = run(T);

    reverse(T.begin(), T.end());
    REP (i, N) reverse(S[i].begin(), S[i].end());
    build(S, S+N);
    VI tail = run(T);
    reverse(tail.begin(), tail.end());

    LL ans = 0;
    REP (i, (int)T.size()-1) {
	ans += (LL)head[i] * tail[i+1];
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}