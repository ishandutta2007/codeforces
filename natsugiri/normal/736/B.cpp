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

LL N;
bool is_prime(LL x) {
    for (LL i=2; i*i<=x; i++) {
	if (x % i == 0) return false;
    }
    return true;
}

int main() {
    scanf("%lld", &N);
    
    if (N == 2) {
	puts("1");
    } else if (N % 2 == 0) {
	puts("2");
    } else {
	if (is_prime(N)) {
	    puts("1");
	} else if (N >= 5 && is_prime(N-2)) {
	    puts("2");
	} else {
	    puts("3");
	}
    }


    return 0;
}