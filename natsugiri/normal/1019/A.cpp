#include<tuple>
#include<queue>
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

int N, M;
VI A[3011];

typedef tuple<int, int, int> T;
vector<T> H;
int iter[3011];

void MAIN() {
    scanf("%d%d", &N, &M);
    H.reserve(N);
    REP (i, N) {
	int p, c;
	scanf("%d%d", &p, &c);
	p--;
	A[p].push_back(c);
    }
    REP (i, M) {
	sort(A[i].begin(), A[i].end());
	REP (j, A[i].size()) {
	    H.emplace_back(A[i][j], i, j);
	}
    }
    sort(H.begin(), H.end());

    LL ans = 1LL<<60;
    for (int s=max(1, (int)A[0].size()); s<=N; s++) {
	int cnt = A[0].size();
	for (int i=1; i<M; i++) {
	    if ((int)A[i].size() >= s) {
		iter[i] = (int)A[i].size() - s+ 1;
	    } else {
		iter[i] = 0;
	    }
	    cnt += iter[i];
	}

	LL tmp = 0;
	REP (i, N) {
	    int p, c, j;
	    tie(c, p, j) = H[i];
	    if (p == 0) continue;
	    if (j < iter[p]) tmp += c;
	    else if (cnt < s) {
		tmp += c;
		cnt++;
	    }
	}

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