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
pair<int, int> P[200011];
pair<int, int> Q[200011];

bool go(int s) {
    if (s == N) return false;
    REP (i, M) {
	int x = (P[i].first + s) % N;
	int y = (P[i].second + s) % N;
	if (x > y) swap(x, y);
	Q[i] = make_pair(x, y);
    }
    sort(Q, Q+M);
    REP (i, M) if (P[i] != Q[i]) return false;
    return true;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	if (x > y) swap(x, y);
	P[i] = make_pair(x, y);
    }
    sort(P, P+M);

    bool yes = false;
    for (int i=1; i*i<=N; i++) if (N % i == 0) {
	yes = yes || go(i);
	yes = yes || go(N/i);
    }

    puts(yes? "Yes": "No");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}