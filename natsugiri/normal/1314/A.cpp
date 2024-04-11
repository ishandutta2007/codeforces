#include<queue>
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

int N;
pair<LL, LL> P[200011]; // (num, time);

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", &P[i].first);
    REP (i, N) scanf("%lld", &P[i].second);
    sort(P, P+N);

    LL ans = 0;
    LL num = 0;
    priority_queue<pair<LL, LL> > Q; // (time, num);
    for (int i=0; i<N || !Q.empty(); ) {
	if (Q.empty()) amax(num, P[i].first);

	while (i < N && P[i].first <= num) {
	    Q.emplace(P[i].second, P[i].first);
	    i++;
	}

	//eprintf("%lld %lld -> %lld\n", Q.top().second, Q.top().first, num);
	ans += Q.top().first * (num - Q.top().second);
	Q.pop();
	num++;
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}