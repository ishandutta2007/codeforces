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

const int MAGIC = 400;
int N;
int A[100111];
int C[100111];
int cc[MAGIC+10][100111];
int counter[MAGIC+10];
int start[MAGIC+10], stop[MAGIC+10];
int ans[100111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    memset(ans, 0x3f, sizeof ans);

    for (int X=1; X<=MAGIC; X++) {
	int cnt = 0, last = 0;
	int tmp = 0;
	REP (i, N) {
	    if (C[A[i]] == 0) {
		if (cnt == X) {
		    tmp++;
		    while (last < i) {
			C[A[last++]] = 0;
		    }
		    cnt = 1;
		} else {
		    cnt++;
		}
		C[A[i]] = 1;
	    }
	}

	tmp++;
	while (last < N) { C[A[last++]] = 0; }
	amin(ans[X], tmp);
    }

    if (MAGIC < N) {
	int X = MAGIC;
	int cur = 0;
	REP (i, N) {
	    if (cc[cur][A[i]] == 0) {
		if (counter[cur] == X) {
		    stop[cur] = i;
		    cur++;
		    start[cur] = i;
		}
	    }
	    if (cc[cur][A[i]] == 0) {
		counter[cur]++;
	    }
	    cc[cur][A[i]]++;
	}
	stop[cur] = N;
	cur++;
	start[cur] = N;

	for (X++; X<=N; X++) {
	    REP (t, cur) {
		if (t != 0) {
		    while (start[t] < stop[t-1]) {
			int v = A[start[t]];
			if (cc[t][v] == 1) counter[t]--;
			cc[t][v]--;
			start[t]++;
		    }
		}
		while (stop[t] < N) {
		    int v = A[stop[t]];
		    if (cc[t][v] == 0) {
			if (counter[t] == X) break;
			counter[t]++;
		    }
		    cc[t][v]++;
		    stop[t]++;
		}
	    }

	    while (cur > 0 && start[cur-1] == N) cur--;
	    amin(ans[X], cur);
	}
    }
    rprintf("%d", ans+1, ans+N+1);

    return 0;
}