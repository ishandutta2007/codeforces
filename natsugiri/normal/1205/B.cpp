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
LL A[100011];
int dist[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    {
	int len = 0;
	REP (i, N) if (A[i]) A[len++] = A[i];
	N = len;
    }
    REP (t, 62) {
	int cnt = 0;
	REP (i, N) if (A[i]>>t&1) cnt++;
	if (cnt >= 3) {
	    puts("3");
	    return;
	}
    }
    int ans = 1<<29;
    VI qu;
    REP (s, N) {
	memset(dist, 0x3f, sizeof (int) * N);
	dist[s] = 0;
	qu.clear();
	qu.push_back(s);
	for (int i=0; i<(int)qu.size(); i++) {
	    int v = qu[i];
	    REP (j, N) if (v != j && (A[v] & A[j])) {
		if (dist[j] > dist[v] + 1) {
		    dist[j] = dist[v] + 1;
		    qu.push_back(j);
		} else if (dist[j] == dist[v]) {
		    amin(ans, dist[v] * 2 + 1);
		} else if (dist[j] == dist[v] + 1) {
		    amin(ans, dist[v] * 2 + 2);
		}
	    }
	}
    }
    if (ans == (1<<29)) {
	ans = -1;
    }
    printf("%d\n", ans);
}


int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}