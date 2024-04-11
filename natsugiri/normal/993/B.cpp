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
int A[55][2];
int B[55][2];

VI Ag[55], Bg[55];

void uni(VI &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d%d", A[i], A[i]+1);
    REP (i, M) scanf("%d%d", B[i], B[i]+1);

    VI guess;
    REP (i, N) REP (j, M) {
	int cnt = 0, val = 0;
	REP (a, 2) REP (b, 2) if (A[i][a] == B[j][b]) {
	    cnt++;
	    val = A[i][a];
	}

	if (cnt == 1) {
	    guess.push_back(val);
	    Ag[i].push_back(val);
	    Bg[j].push_back(val);
	}
    }

    uni(guess);

    if (guess.size() == 1u) {
	printf("%d\n", guess[0]);
    } else {
	int maA = 0, maB = 0;
	REP (i, N) {
	    uni(Ag[i]);
	    amax(maA, (int)Ag[i].size());
	}
	REP (j, M) {
	    uni(Bg[j]);
	    amax(maB, (int)Bg[j].size());
	}

	if (maA == 1 && maB == 1) {
	    puts("0");
	} else {
	    puts("-1");
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}