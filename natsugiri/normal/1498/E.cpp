#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
int in[511];

struct Data {
    int diff;
    int i, j;

    Data() {}

    bool operator<(const Data &y) const {
	return diff < y.diff;
    }
};

vector<Data> D;

bool query(int i, int j) {
    printf("? %d %d\n", i+1, j+1);
    fflush(stdout);

    static char s[11];
    scanf("%s", s);
    return s[0] == 'Y';
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", in+i);

    REP (i, N) REP (j, i) {
	Data x;
	if (in[i] > in[j]) {
	    x.i = i;
	    x.j = j;
	} else {
	    x.i = j;
	    x.j = i;
	}
	x.diff = abs(in[i] - in[j]);
	D.push_back(x);
    }

    sort(D.begin(), D.end());
    for (int k=D.size(); k--;) {
	bool b = query(D[k].i, D[k].j);
	if (b) {
	    printf("! %d %d\n", D[k].i+1, D[k].j+1);
	    fflush(stdout);
	    return;
	}
    }

    puts("! 0 0");
    fflush(stdout);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}