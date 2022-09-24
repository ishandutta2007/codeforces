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
int A[100111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    if (count(A, A+N, 0) == N) {
	puts("NO");
    } else {
	int last = 0, cur = 0;
	VI L, R;
	while (A[cur] == 0) cur++;
	while (cur < N) {
	    cur++;
	    while (cur < N && A[cur] == 0) cur++;
	    L.push_back(last);
	    R.push_back(cur);
	    last = cur;
	}

	puts("YES");
	printf("%d\n", (int)L.size());
	REP (i, L.size()) printf("%d %d\n", L[i] + 1, R[i]);
    }


    return 0;
}