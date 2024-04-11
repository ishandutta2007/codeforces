#include<bitset>
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
typedef bitset<1024> Bits;
Bits A[20];
bool B[20];
int ans[1024];

bool check() {
    REP (i, N) {
	Bits x; x.reset();
	REP (j, 20) if (!A[j][i]) x |= A[j];

	if ((int)x.count() != N-1) {
	    return false;
	}
    }

    return true;
}

int main() {
    scanf("%d", &N);

    REP (i, N) ans[i] = 1e9;

    REP (i, 20) B[i] = i & 1;
    while (1) {
	REP (j, N) {
	    random_shuffle(B, B+20);
	    REP (i, 20) A[i][j] = B[i];
	}

	if (check()) break;
    }

    REP (t, 20) {
	if (A[t].count() == 0u) continue;
	VI v;
	REP (i, N) if (A[t][i]) v.push_back(i+1);

	printf("%d\n", (int)v.size());
	rprintf("%d", v.begin(), v.end());
	fflush(stdout);

	REP (i, N) {
	    int x;
	    scanf("%d", &x);
	    if (!A[t][i]) amin(ans[i], x);
	}
    }

    puts("-1");
    rprintf("%d", ans, ans+N);
    fflush(stdout);

    return 0;
}