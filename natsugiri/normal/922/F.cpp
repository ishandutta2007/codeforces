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

int N, K;

int D[300111];
int prv[211][5000];

void MAIN() {
    scanf("%d%d", &N, &K);
    for (int i=1; i<=N; i++) {
	for (int j=i+i; j<=N; j+=i)
	    D[j]++;
    }

    int stop = 1;
    LL cnt = 0;
    while (stop < N && cnt < K) {
	stop++;
	cnt += D[stop];
    }

    if (cnt < K) {
	puts("No");
	return;
    } else {
	int len = max(stop/2, stop-200);
	int rest = K;
	VI ans; ans.reserve(stop);
	for (int i=1; i<=len; i++) {
	    rest -= D[i];
	    ans.push_back(i);
	}

	VI x; x.reserve(211);
	for (int i=len+1; i<=stop; i++) x.push_back(i);
	// eprintf("%d %d\n", rest, len);
	
	memset(prv, -1, sizeof prv);
	prv[0][0] = 0;
	REP (i, x.size()) {
	    REP (j, rest+1) if (prv[i][j] != -1) {
		prv[i+1][j] = j;
		if (j+D[x[i]] <= rest) {
		    prv[i+1][j+D[x[i]]] = j;
		}
	    }
	}

	if (prv[x.size()][rest] == -1) {
	    puts("No");
	    return;
	}

	puts("Yes");
	int cur = rest;
	for (int i=x.size(); i--;) {
	    if (prv[i+1][cur] != cur) {
		ans.push_back(x[i]);
		cur = prv[i+1][cur];
	    }
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	rprintf("%d", ans.begin(), ans.end());
    }



}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}