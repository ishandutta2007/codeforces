#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

int N, M;
int SX, SY, FX, FY;

pair<int, int> P[100011];
pair<int, int> Xi[100011];
pair<int, int> Yi[100011];
LL D[100011];

VI G[100011];

void MAIN() {
    scanf("%*d%d", &M);
    scanf("%d%d%d%d", &SX, &SY, &FX, &FY);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);

	P[i] = make_pair(x, y);
	Xi[i] = make_pair(x, i);
	Yi[i] = make_pair(y, i);
    }

    P[M] = make_pair(SX, SY);
    Xi[M] = make_pair(SX, M);
    Yi[M] = make_pair(SY, M);

    sort(Xi, Xi+M+1);
    sort(Yi, Yi+M+1);

    REP (i, M) {
	int a = Xi[i].second;
	int b = Xi[i+1].second;
	G[a].push_back(b);
	G[b].push_back(a);

	a = Yi[i].second;
	b = Yi[i+1].second;
	G[a].push_back(b);
	G[b].push_back(a);
    }

    memset(D, 0x3f, sizeof D);
    D[M] = 0;
    priority_queue<pair<LL, int> > Q;
    Q.emplace(0LL, M);

    while (!Q.empty()) {
	LL cst = -Q.top().first;
	int v = Q.top().second;
	Q.pop();

	if (D[v] != cst) continue;

	EACH (e, G[v]) {
	    LL add = min(
		    abs((LL)P[v].first - P[*e].first),
		    abs((LL)P[v].second - P[*e].second));
	    if (D[*e] > cst + add) {
		D[*e] = cst + add;
		Q.emplace(-D[*e], *e);
	    }
	}
    }


    LL ans = 1LL<<60;
    REP (i, M+1) {
	LL tmp = abs((LL)P[i].first - FX) + abs((LL)P[i].second - FY) + D[i];
	amin(ans, tmp);
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}