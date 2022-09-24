#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
pair<int, int> P[200011];

pair<int, int> X[2500011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d", &P[i].first);
	P[i].second = i;
    }

    sort(P, P+N);
    REP (i, 2500011) X[i].first = -1;

    REP (i, N-1) {
	if (i >= 2) {
	    for (int j=i+1; j<N; j++) {
		int d = P[j].first - P[i].first;
		if (X[d].first != -1) {
		    int f = X[d].first;
		    int s = X[d].second;

		    int x = P[f].second;
		    int y = P[j].second;
		    int z = P[s].second;
		    int w = P[i].second;

		    puts("YES");
		    printf("%d %d %d %d\n", x+1, y+1, z+1, w+1);
		    return;
		}
	    }
	}

	for (int j=0; j<i; j++) {
	    int d = P[i].first - P[j].first;
	    if (X[d].first == -1) {
		X[d].first = j;
		X[d].second = i;
	    }
	}
    }

    puts("NO");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}