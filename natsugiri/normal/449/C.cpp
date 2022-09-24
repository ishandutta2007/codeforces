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
bool P[100111];
int A[100111];

int main() {
    REP (i, 100111) P[i] = true;
    P[0] = P[1] = false;
    for (int i=2; i*i<100111; i++) if (P[i]) {
	for (int j=i*i; j<100111; j+=i) P[j] = false;
    }

    scanf("%d", &N);
    memset(A, -1, sizeof A);
    for (int i=N/2; i>=2; i--) if (P[i]) {
	int last = -1;
	for (int j=i; j<=N; j+=i) {
	    if (A[j] == -1) {
		if (last == -1) {
		    last = j;
		} else {
		    A[j] = last;
		    A[last] = j;
		    last = -1;
		}
	    }
	}

	if (last != -1) {
	    A[i] = last;
	    A[last] = i;
	    A[i+i] = -1;
	}
    }

    int ans = 0;
    REP (i, N+1) if (i < A[i]) ans++;
    printf("%d\n", ans);
    REP (i, N+1) if (i < A[i]) {
	printf("%d %d\n", i, A[i]);
    }



    return 0;
}