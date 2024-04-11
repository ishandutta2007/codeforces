#include<map>
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

const int MAX = 1000111;
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


void MAIN() {
    make_prime();
    int X2;
    scanf("%d", &X2);
    int X1_min = X2;

    {
	int m = X2;
	while (m > 1) {
	    int p = min_factor[m];
	    int k = X2 / p;
	    while (m % p == 0) m /= p;
	    if (k > 1) amin(X1_min, p*(k-1)+1);
	}
    }

    
    int X0_min = X1_min+1;
    for (int x1=X1_min; x1<=X2; x1++) {
	int m = x1;
	while (m > 1) {
	    int p = min_factor[m];
	    int k = x1 / p;
	    while (m % p == 0) m /= p;
	    if (k > 1) amin(X0_min, p*(k-1)+1);
	}
    }
    
    printf("%d\n", X0_min);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}