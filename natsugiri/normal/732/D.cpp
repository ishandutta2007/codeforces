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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, M, D[100111], A[100111];
pair<int, int> P[100111];

bool ok(int x) {
    REP (i, M) P[i] = make_pair(-1, A[i]);
    for (int i=x; i--; ) {
	if (D[i] != -1 && P[D[i]].first == -1) P[D[i]].first = i;
    }

    sort(P, P+M);
    if (P[0].first == -1) return false;

    int cur = 0;
    int tt = 0;
    REP (i, x) {
	if (P[cur].first == i) {
	    if (P[cur].second <= tt) {
		tt -= P[cur].second;
		cur++;
		if (cur == M) return true;
	    } else {
		return false;
	    }
	} else {
	    tt++;
	}
    }

    return false;
}

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", D+i), D[i]--;
    REP (i, M) scanf("%d", A+i);

    int lo = 0, hi = N+1;
    while (hi - lo > 1) {
	int m = (hi + lo) / 2;
	(ok(m)? hi: lo) = m;
    }

    if (hi == N+1) hi = -1;
    printf("%d\n", hi);

    return 0;
}