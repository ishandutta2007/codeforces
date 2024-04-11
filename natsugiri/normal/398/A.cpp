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
LL sq(LL x) { return x * x; }

int A, B;

int main() {
    scanf("%d%d", &A, &B);

    if (A == 0) {
	printf("%lld\n%s\n", -sq(B), string(B, 'x').c_str());
    } else if (B == 0) {
	printf("%lld\n%s\n", sq(A), string(A, 'o').c_str());
    } else {
	int C = 0;
	LL score = -(1LL<<60);
	for (LL a=1; a<=A; a++) {
	    LL tmp = 0;
	    tmp += sq(a);
	    tmp += A - a;

	    LL q = B / (A - a + 2), r = B % (A - a + 2);
	    tmp -= r * sq(q+1) + (A - a + 2 - r) * sq(q);

	    if (tmp > score) {
		C = a;
		score = tmp;
	    }
	}

	{
	    LL q = B / (A - C + 2), r = B % (A - C + 2);
	    VI v, w;
	    REP (i, r) v.push_back(q+1);
	    REP (i, A-C+2-r) v.push_back(q);
	    w.assign(A - C, 1);
	    w.push_back(C);

	    printf("%lld\n", score);
	    REP (i, max(v.size(), w.size())) {
		if (i < (int)v.size()) printf("%s", string(v[i], 'x').c_str());
		if (i < (int)w.size()) printf("%s", string(w[i], 'o').c_str());
	    }
	    puts("");
	}
    }


    



    return 0;
}