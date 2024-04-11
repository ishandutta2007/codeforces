#include<cassert>
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

const int MAX = 10000010;
int min_factor[MAX+1];
vector<int>prime;
void make_prime() {
    for (int i=2; i<=MAX; i+=2) min_factor[i] = 2;
    for (int i=3; i<=MAX; i+=3) if (!min_factor[i]) min_factor[i] = 3;
    for (int i=5, d=2; i*i<=MAX; ) {
	if (!min_factor[i]) {
	    min_factor[i] = i;
	    for (int j=i*i; j<=MAX; j+=i)
		if (!min_factor[j]) min_factor[j] = i;
	}
	i += d; d = 6 - d;
    }
    for (int i=2; i<=MAX; i++) {
	if (min_factor[i]==0) min_factor[i] = i;
	if (min_factor[i]==i) prime.push_back(i);
    }
}
VI fast_prime_factor(int n) { // n<=MAX
    assert(n <= MAX);
    VI r;
    while (n > 1) {
	int t = min_factor[n], cnt = 0;
	while (n%t == 0) { n /= t, cnt++; }
	r.push_back(t);
    }
    return r;
}

bool use[MAX+1];

int N;
int A[100011];
int B[100011];

void MAIN() {
    make_prime();

    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    bool eq = true;
    int pos = 2;
    REP (i, N) {
	if (eq) {
	    int cur = A[i];
	    while (1) {
		if (!use[cur]) {
		    B[i] = cur;
		    VI f = fast_prime_factor(cur);
		    EACH (e, f) {
			for (int j=*e; j<MAX; j+=*e) use[j] = true;
		    }
		    break;
		} else {
		    eq = false;
		    cur++;
		}
	    }
	} else {
	    while (1) {
		if (!use[pos]) {
		    B[i] = pos;
		    VI f = fast_prime_factor(pos);
		    EACH (e, f) {
			for (int j=*e; j<MAX; j+=*e) use[j] = true;
		    }
		    break;
		} else {
		    eq = false;
		    pos++;
		}
	    }
	}
    }

    rprintf("%d", B, B+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}