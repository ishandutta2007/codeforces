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
int A[5011];

const LL SIZE = sizeof(LL) * 3011 * 3;
LL buf[2][3011][3];
LL (*cur)[3] = buf[0];
LL (*nxt)[3] = buf[1];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);


    memset(cur, 0x3f, SIZE);
    cur[0][0] = 0;

    for (int i=1; i<=N; i++) {
	memset(nxt, 0x3f, SIZE);

	REP (k, i+1) {
	    if (k > (N+1)/2) break;

	    amin(nxt[k][0], cur[k][0]);
	    amin(nxt[k][0], cur[k][2]);
	    if (i >= 2 && A[i-2] > A[i-1]) {
		amin(nxt[k][0], cur[k][1]);
	    }

	    if (i == 1) {
		amin(nxt[1][1], 0LL);
	    }
	    if (k > 0 && i >= 2 && A[i-2] < A[i-1]) {
		amin(nxt[k][1], cur[k-1][0]);
		amin(nxt[k][1], cur[k-1][2]);
	    }
	    if (k > 0 && i >= 2 && A[i-2] >= A[i-1]) {
		LL cst = A[i-2] - A[i-1] + 1;
		amin(nxt[k][1], cur[k-1][0] + cst);
	    }
	    if (k > 0 && i >= 3) {
		LL h = min(A[i-3]-1, A[i-2]);
		LL cst = max(0LL, h - A[i-1] + 1);
		amin(nxt[k][1], cur[k-1][2] + cst);
	    }

	    if (i >= 2) {
		if (A[i-2] > A[i-1]) {
		    amin(nxt[k][2], cur[k][1]);
		} else {
		    LL cst = A[i-1] - A[i-2] + 1;
		    amin(nxt[k][2], cur[k][1] + cst);
		}
	    }
	}
	swap(cur, nxt);
    }

    vector<LL> ans;
    for (int k=1; k<=(N+1)/2; k++) {
	LL tmp = cur[k][0];
	amin(tmp, cur[k][1]);
	amin(tmp, cur[k][2]);
	ans.push_back(tmp);
    }
    rprintf("%lld", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}