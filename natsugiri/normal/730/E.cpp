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


int N;
int A[111], D[111];

bool order(int a, int b, int c, int d) {
    return a < b && b < c && c < d;
}

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", A+i, D+i);
    REP (i, N) {
	A[i] *= 1000;
	D[i] *= 1000;
	A[i] += 100 - i;
    }
    int ans = 0;

    REP (i, N) REP (j, i) {
	if (A[i] < A[j] && A[i] + D[i] > A[j] + D[j]) {
	    ans++;
	} else if (A[i] > A[j] && A[i] + D[i] < A[j] + D[j]) {
	    ans++;
	} else if (order(A[i], A[j], A[i]+D[i], A[j]+D[j])) {
	    ans += 2;
	} else if (order(A[j], A[i], A[j]+D[j], A[i]+D[i])) {
	    ans += 2;
	} else if (order(A[j]+D[j], A[i]+D[i], A[j], A[i])) {
	    ans += 2;
	} else if (order(A[i]+D[i], A[j]+D[j], A[i], A[j])) {
	    ans += 2;
	}
    }
    printf("%d\n", ans);


    return 0;
}