#include<stack>
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
typedef vector<VI> Adj;
struct SCC {
    vector<int> scc;
    int cnt;
    SCC(){}
    SCC(const Adj &G) {
	int n = G.size();
	scc.assign(n, 0);
	vector<int> ord; ord.reserve(n);
	REP (k, n) if (scc[k] == 0) {
	    stack<int> S;
	    S.push(k);
	    while (!S.empty()) {
		int v = S.top(); S.pop();
		if (v >= 0) {
		    if (scc[v]) continue;
		    scc[v] = -1;
		    S.push(v-n);
		    EACH (e, G[v]) S.push(*e);
		} else {
		    ord.push_back(v+n);
		}
	    }
	}
	Adj R(n);
	REP (v, n) EACH (e, G[v]) R[*e].push_back(v);
	cnt = 0;
	for (int i=n; i--; ) if (scc[ord[i]] == -1) {
	    stack<int> S;
	    S.push(ord[i]); scc[ord[i]] = cnt;
	    while (!S.empty()) {
		int v = S.top(); S.pop();
		scc[ord[i]] = cnt;
		EACH (e, R[v]) if (scc[*e] == -1) {
		    S.push(*e); scc[*e] = cnt;
		}
	    }
	    cnt++;
	}
    }
    Adj shrink(const Adj &G) { // may have loop edges, doesn't have parallel edges
	Adj S(cnt);
	REP (v, G.size()) EACH (e, G[v]) S[scc[v]].push_back(scc[*e]);
	REP (i, cnt) {
	    sort(S[i].begin(), S[i].end());
	    S[i].erase(unique(S[i].begin(), S[i].end()), S[i].end());
	}
	return S;
    }
};
struct TwoSAT {
    int N, n;
    Adj G;
    SCC scc;
    vector<int>truth;
    bool sat;
    TwoSAT() {}
    TwoSAT(int n):n(n) { // n = number of variables
	N = n*2;
	G = Adj(N);
    }
    void add(int p, int q) { // p -> q
	G[p].push_back(q);
    }
    int inv(int p) { // id of ~p
	return (p+n)%N;
    }
    void IMP(int p, int q) { // p -> q
	add(p, q);
	add(inv(q), inv(p));
    }
    void T(int p) { // p is true : ~p -> p
	add(inv(p), p);
    }
    void OR(int p, int q) {
	IMP(inv(p), q);
    }
    void XOR(int p, int q) {
	IMP(p, inv(q));
	IMP(inv(p), q);
    }
    void EQ(int p, int q) {
	IMP(p, q);
	IMP(inv(p), inv(q));
    }
    bool SAT() {
	scc = SCC(G);
	sat = true; truth = vector<int>(n, 0);
	for (int i=0; i<n; i++) {
	    if (scc.scc[i] == scc.scc[i+n]) sat = false;
	    if (scc.scc[i] > scc.scc[i+n]) truth[i] = 1;
	}
	return sat;
    }
};

int N, M;;
int A[100111];
VI G[100111];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);
    REP (s, M) {
	int x;
	scanf("%d", &x);
	REP (i, x) {
	    int p;
	    scanf("%d", &p);
	    p--;
	    G[p].push_back(s);
	}
    }

    TwoSAT TS(M);
    REP (i, N) {
	int x = G[i][0], y = G[i][1];
	if (A[i]) {
	    TS.EQ(x, y);
	} else {
	    TS.XOR(x, y);
	}
    }

    bool yes = TS.SAT();
    puts(yes? "YES": "NO");

    return 0;
}