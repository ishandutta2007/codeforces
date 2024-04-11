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

int M, K, N, S;
int A[500011];
int B[500011];

int C[500011];

void MAIN() {
    scanf("%d%d%d%d", &M, &K, &N, &S);
    REP (i, M) scanf("%d", A+i);
    REP (i, S) scanf("%d", B+i);

    int cnt = 0;
    REP (i, S) {
	if (C[B[i]] == 0) cnt++;
	C[B[i]]--;
    }
    sort(B, B+S);

    int r = 0;
    REP (i, M) {
	while (r < M && cnt) {
	    C[A[r]]++;
	    if (C[A[r]] == 0) cnt--;
	    r++;
	}

	if (cnt == 0) {
	    int a = i / K + 1 + (M-r) / K;
//	    eprintf("[%d %d), %d\n", i, r, a);
	    if (a >= N) {
		VI ans;

		VI pool;
		vector<pair<int, int> > p;
		for (int j=i; j<r; j++) {
		    p.emplace_back(A[j], j);
		}
		sort(p.begin(), p.end());
		int pos = 0;
		REP (x, S) {
		    while (pos < (int)p.size() && B[x] != p[pos].first) {
			pool.push_back(p[pos].second);
			pos++;
		    }

		    pos++;
		}
		while (pos < (int)p.size()) {
		    pool.push_back(p[pos].second);
		    pos++;
		}
		for (int t=K-S; t<(int)pool.size(); t++) ans.push_back(pool[t]+1);

		REP (t, i % K) ans.push_back(t+1);

		sort(ans.begin(), ans.end());
		printf("%d\n", (int)ans.size());
		rprintf("%d", ans.begin(), ans.end());
		return;
	    }
	}

	if (C[A[i]] == 0) cnt++;
	C[A[i]]--;
    }

    puts("-1");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}