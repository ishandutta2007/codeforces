#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

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
// a ab bc ca a;
//
// a abca a;
//
// abc ca a;
//
// a ab b ba a
// ab ba a

set<pair<int, int> > se[26][26];
set<int> idx;

int alpha[26];

int N;
char S[200011];
vector<pair<int, int> > ps, ans;
int stk[200011];
VI G[200011];

void dfs(int v, int h) {
    //eprintf("[%d %d) %d\n", ps[v].first, ps[v].second, h);
    int len = 0;
    EACH (e, G[v]) {
	dfs(*e, h + len);
	len += ps[*e].second - ps[*e].first;
    }
    //eprintf("x %d %d %d\n", h, len, ps[v].second - ps[v].first);
    ans.emplace_back(ps[v].first - h, ps[v].second - h - len);
}


void MAIN() {
    REP (a, 26) REP (b, 26) se[a][b].clear();
    idx.clear();
    memset(alpha, 0, sizeof alpha);

    scanf("%s", S);
    N = strlen(S);
    REP (i, N) G[i].clear();

    VI idxv;
    REP (i, N-1) if (S[i] == S[i+1]) {
	idx.insert(i+1);
	idxv.push_back(i+1);
	alpha[S[i]-'a']++;
    }
    REP (i, (int)idxv.size()-1) {
	int a = S[idxv[i]]-'a';
	int b = S[idxv[i+1]]-'a';
	se[a][b].emplace(idxv[i], idxv[i+1]);
    }
    idxv.clear();

    ps.clear();
    while (1) {
	int a = 0;
	REP (c, 26) if (alpha[a] < alpha[c]) a = c;

	if (alpha[a] == 0) break;

	int b = -1;
	REP (c, 26) if (c != a) {
	    if (se[a][c].size()) { b = c; break; }
	    if (se[c][a].size()) { b = a; a = c; break; }
	}
	if (b == -1) break;

	auto p = *se[a][b].begin();
	se[a][b].erase(se[a][b].begin());
	alpha[a]--;
	alpha[b]--;
	// [p.first, p.second);
	ps.push_back(p);
	idx.erase(p.first);
	idx.erase(p.second);
	auto it = idx.lower_bound(p.second);
	if (it != idx.end()) {
	    int c = S[*it] - 'a';
	    se[b][c].erase(make_pair(p.second, *it));
	}
	if (it != idx.begin()) {
	    auto left = prev(it);
	    int x = S[*left] - 'a';
	    se[x][a].erase(make_pair(*left, p.first));

	    if (it != idx.end()) {
		int c = S[*it] - 'a';
		se[x][c].emplace(*left, *it);
	    }
	}
    }

    EACH (e, idx) ps.emplace_back(0, *e);
    ps.emplace_back(0, N);

    printf("%d\n", (int)ps.size());
    sort(ps.begin(), ps.end(), [](const pair<int, int> &x, const pair<int, int> &y) {
	    return x.first != y.first? x.first < y.first:
	    x.second > y.second;
	    });

    stk[0] = 0;
    int t = 0;
    for (int i=1; i<(int)ps.size(); i++) {
	while (ps[stk[t]].second <= ps[i].first) {
	    t--;
	}
	//eprintf("%d -> %d\n", stk[t], i);
	G[stk[t]].push_back(i);
	stk[++t] = i;
    }

    ans.clear();
    dfs(0, 0);

    EACH (e, ans) {
	printf("%d %d\n", e->first+1, e->second);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}