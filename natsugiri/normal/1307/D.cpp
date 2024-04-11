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

int N, M, K;
int A[200011];
VI G[200011];

void bfs(int D[], int s) {
    memset(D, 0x3f, sizeof (D[0]) * N);
    D[s] = 0;
    VI ord; ord.reserve(N);
    ord.push_back(s);
    for (int i=0; i<(int)ord.size(); i++) {
	int v = ord[i];
	EACH (e, G[v]) if (D[*e] > D[v] + 1) {
	    D[*e] = D[v] + 1;
	    ord.push_back(*e);
	}
    }
}

int D0[200011];
int D1[200011];

int eval(int x, int y) {
    return min({
	    D1[0],
	    D0[x] + D1[y] + 1,
	    D0[y] + D1[x] + 1});
}

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, K) scanf("%d", A+i), A[i]--;
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    bfs(D0, 0);
    bfs(D1, N-1);

    VI idx(A, A+K);
    sort(idx.begin(), idx.end(), [&](int a, int b) {
	    return D0[a] != D0[b]? D0[a] < D0[b]: D1[a] < D1[b];
	    });
    
    int ans = 0;
    REP (i, K-1) {
	int a = idx[i], b = idx[i+1];
	if (D1[a] <= D1[b]) {
	    ans = D1[0];
	}
    }

    if (ans == 0) {
	int pos = 0;
	for (int i=1; i<K; i++) {
	    int b = idx[i];
	    while (pos + 1 < i) {
		int y = idx[pos+1];
		int s = D0[y]+D1[b]+1;
		int t = D0[b]+D1[y]+1;
		if (s < t) pos++;
		else break;
	    }

	    amax(ans, eval(b, idx[pos]));
	    if (pos + 1 < i) amax(ans, eval(b, idx[pos+1]));
	}
    }


    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}