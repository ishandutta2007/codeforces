#include<set>
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

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i=2; i*i<=x; i++) if (x % i == 0) return false;
    return true;
}

int N;
int A[100111];
LL inv[100111];

int main() {
    scanf("%d", &N);
    VI L;
    if (N == 1) {
	L.push_back(1);
    } else if (N == 2) {
	L.push_back(1);
	L.push_back(2);
    } else if (N == 4) {
	L.push_back(1);
	L.push_back(3);
	L.push_back(2);
	L.push_back(4);
    } else if (is_prime(N)) {

	inv[1] = 1;
	for (int i=2; i<N; i++) inv[i] = inv[N%i] * (N-N/i) % N;

	L.push_back(1);
	LL p = 1;
	REP (i, N-2) {
	    int x = inv[p] * (i + 2) % N;
	    L.push_back(x);
	    p = p * x % N;
	}
	L.push_back(N);
//	rprintf("%d", L.begin(), L.end());
    }

    if (L.size()) {
	puts("YES");
	REP (i, N) printf("%d\n", L[i]);
    } else {
	puts("NO");
    }

//    REP (i, L.size()) A[i] = L[i];
//    {
//	int p =1;
//	set<int> se;
//	REP (i, N) {
//	    p = p * A[i] % N;
//	    se.insert(p);
//	}
//	if ((int)se.size() == N) {
//	    rprintf("%d", A, A+N);
//	    p = 1;
//	    REP (i, N) {
//		p = p * A[i] % N;
//		printf("%d ", p);
//	    }
//	    puts("");
//	}
//	return 0;
//    }


    return 0;
}