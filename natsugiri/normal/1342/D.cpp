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

int N, K;
int M[200011];
int C[200011];
VI vals[200011];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", M+i);
    sort(M, M+N);
    REP (i, K) scanf("%d", C+i+1);

    priority_queue<pair<int, int> > Q; // -cnt, name;
    int id = 0;
    Q.emplace(0, id++);

    for (int i=N; i--;) {
	int len = M[i];

	if (-Q.top().first >= C[len]) {
	    assert(-Q.top().first == C[len]);
	    Q.emplace(0, id++);
	}

	pair<int, int> p = Q.top();
	Q.pop();
	vals[p.second].push_back(len);
	Q.emplace(p.first-1, p.second);
    }
    printf("%d\n", (int)Q.size());
    REP (i, id) {
	printf("%d ", (int)vals[i].size());
	rprintf("%d", vals[i].begin(), vals[i].end());
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}