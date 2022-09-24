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

int N;
pair<int, int> P[5011];
bool B[5011];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", &P[i].first, &P[i].second);
    sort(P, P+N);

    B[1] = true;
    for (int i=1; i<N; i++) {
	if (P[i-1].first <= P[i].second) B[i+1] = true;
	if (B[i] && P[i-1].second <= P[i].second) B[i+1] = true;
    }

    printf("%d\n", B[N]? P[N-1].second: P[N-1].first);

    return 0;
}