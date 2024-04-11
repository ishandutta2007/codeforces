#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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

int N, X, Y;
int A[100011];
int B[100011];
int ans[100011];

VI stk[100011];
int W[100011];

void MAIN() {
    scanf("%d%d%d", &N, &X, &Y);
    REP (i, N) scanf("%d", B+i);

    REP (i, N+2) {
	stk[i].clear();
	W[i] = 0;
    }

    REP (i, N) stk[B[i]].push_back(i);

    int REST = -1;
    for (int i=1; i<=N+1; i++) if (stk[i].empty()) REST = i;

    priority_queue<pair<int, int> > Q;

    REP (i, N+2) if (stk[i].size()) {
	Q.emplace(stk[i].size(), i);
    }


    REP (t, X) {
	pair<int, int> p = Q.top();
	Q.pop();

	int pos = stk[p.second].back();
	stk[p.second].pop_back();
	p.first--;
	A[pos] = p.second;
	if (p.first) Q.push(p);
    }

    int shift = 0;
    vector<pair<int, int> > CP;
    REP (t, N-Y) {
	pair<int, int> p = Q.top();
	Q.pop();

	amax(shift, p.first);

	int pos = stk[p.second].back();
	stk[p.second].pop_back();
	p.first--;

	W[p.second]++;
	CP.emplace_back(p.second, pos);
	if (p.first) Q.push(p);
    }

    REP (t, Y-X) {
	pair<int, int> p = Q.top();
	Q.pop();

	amax(shift, p.first);

	int pos = stk[p.second].back();
	stk[p.second].pop_back();
	p.first--;
	CP.emplace_back(p.second, pos);
	if (p.first) Q.push(p);
    }

    assert(Q.empty());

    sort(CP.begin(), CP.end());
    for (int i=CP.size(); i--;) {
	if (W[CP[i].first]) {
	    W[CP[i].first]--;
	    CP[i].first = REST;
	}
    }

    REP (i, CP.size()) {
	int pos = CP[(i+shift) % CP.size()].second;
	A[pos] = CP[i].first;
    }


    // check;
    REP (i, N) ans[i] = A[i];
    int count_X = 0;
    REP (i, N) if (A[i] == B[i]) count_X++;

    sort(A, A+N);
    sort(B, B+N);
    int count_Y = 0;
    for (int i=0, j=0; i<N && j<N;) {
	if (A[i] == B[j]) {
	    count_Y++;
	    i++;
	    j++;
	} else if (A[i] < B[j]) i++;
	else j++;
    }

    if (count_X == X && count_Y == Y) {
	puts("YES");
	rprintf("%d", ans, ans+N);
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}