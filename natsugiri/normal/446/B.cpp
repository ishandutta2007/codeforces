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

int N, M, K, P;
int A[1011][1011];

vector<LL> solve() {
    priority_queue<LL> Q;
    REP (i, N) {
	LL s = 0;
	REP (j, M) s += A[i][j];
	Q.push(s);
    }

    vector<LL> ret(K+1);
    LL sum = 0;
    REP (i, K) {
	LL tmp = Q.top(); Q.pop();
	sum += tmp;
	Q.push(tmp - M * P);
	ret[i+1] = sum;
    }
    return ret;
}

int main() {
    scanf("%d%d%d%d", &N, &M, &K, &P);
    REP (i, N) REP (j, M) scanf("%d", A[i]+j);

    vector<LL> a = solve();
    REP (i, 1011) REP (j, i) swap(A[i][j], A[j][i]);
    swap(N, M);
    vector<LL> b = solve();

    LL ans = -(1LL<<60);
    REP (i, K+1) {
	LL tmp = a[i] + b[K-i] - (LL)P * i * (K-i);
	amax(ans, tmp);
    }


    printf("%lld\n", ans);

    return 0;
}