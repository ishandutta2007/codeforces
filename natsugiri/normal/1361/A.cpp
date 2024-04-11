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

int N, M;
VI G[500011];
int T[500011];
pair<int, int> P[500011];
int mem[500011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    REP (i, N) {
	scanf("%d", T+i);
	P[i] = make_pair(T[i], i);
    }
    sort(P, P+N);

    int cnt = 0;
    bool yes = true;
    REP (i, N) {
	int v = P[i].second;
	cnt++;
	EACH (e, G[v]) mem[T[*e]] = cnt;
	for (int k=1; k<P[i].first; k++) if (mem[k] != cnt) { yes = false; break; }
	if (mem[P[i].first] == cnt) yes = false;
	if (!yes) break;
    }

    if (yes) {
	REP (i, N) printf("%d%c", P[i].second+1, " \n"[i==N-1]);
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}