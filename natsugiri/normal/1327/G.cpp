#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>

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

int N;
string T[1011];
int C[1011];
string S;
char buf[1000011];


const int ALPHA_BASE = 'a';
const int ALPHA_SIZE = 14;

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
	    // add(i, begin[idx[j]], value[idx[j]]);
	    // nodes[i].sum += 1;
	    nodes[i].sum += C[idx[j]];
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

//VI run(const string &t) {
//    VI v(t.size());
//    int x = 0;
//    REP (i, t.size()) {
//      x = get_next(x, t[i]);
//	v[i] += nodes[x].sum;
//    }
//    return v;
//}

map<pair<int, int>, LL> cur, nxt;

VI B[15];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%s%d", buf, C+i);
	T[i] = buf;
    }
    scanf("%s", buf);
    S = buf;

    build(T, T+N);

    VI pos;
    pos.push_back(-1);
    REP (i, S.size()) if (S[i] == '?') pos.push_back(i);
    pos.push_back(S.size());


    cur[make_pair(0, 0)] = 0LL;
    LL ans = -(1LL<<60);

    REP (i, (int)pos.size()-1) {
	auto it = cur.begin();
	nxt.clear();
	while (it != cur.end()) {
	    const int start = it->first.first;
	    int x = start;
	    LL val = 0;
	    for (int k=pos[i]+1; k<pos[i+1]; k++) {
		x = get_next(x, S[k]);
		val += nodes[x].sum;
	    }

	    while (it != cur.end() && it->first.first == start) {
		const int MASK = it->first.second;
		if (pos[i+1] < (int)S.size()) {
		    REP (d, 14) if (~MASK>>d&1) {
			int y = get_next(x, d+'a');
			pair<int, int> nkey(y, MASK|(1<<d));
			auto g = nxt.find(nkey);
			if (g == nxt.end()) {
			    nxt.emplace(nkey, val + nodes[y].sum + it->second);
			} else {
			    amax(g->second, val + nodes[y].sum + it->second);
			}
		    }
		} else {
		    amax(ans, val + it->second);
		}
		it++;
	    }
	}
	swap(cur, nxt);
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}