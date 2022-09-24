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
string A, B, ans;
char buf[1000111];

void MAIN() {
    scanf("%s", buf);
    A = buf;
    scanf("%s", buf);
    B = buf;

    N = A.size();
    if (N == 1) {
	ans = A;
    } else {

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	ans = A;

	int l = 0, r = N-1;
	int al = 0, ar = (N+1)/2 - 1;
	int bl = N-N/2, br = N-1;
	REP (i_, N) {
	    if (~i_ & 1) {
		if (A[al] < B[br]) {
		    ans[l++] = A[al++];
		} else {
		    ans[r--] = A[ar--];
		}
	    } else {
		if (A[al] < B[br]) {
		    ans[l++] = B[br--];
		} else {
		    ans[r--] = B[bl++];
		}
	    }
	}
    }
    printf("%s\n", ans.c_str());
}
int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}