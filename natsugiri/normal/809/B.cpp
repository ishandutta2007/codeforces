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

int A[100011];

void test_init() {
    REP (i, N) A[i] = i;
    random_shuffle(A, A+N);
    sort(A, A+K);
    puts("oracle");
    rprintf("%d", A, A+K);
}

bool test_query(int a, int b) {
    int la = N, lb = N;
    REP (i, K) {
	amin(la, abs(a - A[i]));
	amin(lb, abs(b - A[i]));
    }
    return la <= lb;
}

void check(int x, int y) {
    REP (i, K) {
	if (x == A[i]) x = -1;
	if (y == A[i]) y = -1;
    }

    if (x == -1 && y == -1) 
	puts("OK");
    else 
	puts("NO");
}

bool query(int a, int b) {
//    return test_query(a, b);
    printf("1 %d %d\n", a + 1, b + 1);
    fflush(stdout);
    static char buf[11];
    scanf("%s", buf);
    return (*buf == 'T');
}

bool left_wide;
int rec(int L, int H) {
    if (L >= H) return -1;
    if (L+1 == H) return L;

    int len = H - L - 2;
    int a, m, b;
    if (left_wide) { // left wide
	a = L + 0 + len / 4 + (len % 4 > 0);
	m = a + 1 + len / 4 + (len % 4 > 1);
	b = m + 0 + len / 4 + (len % 4 > 2);
	if (query(a, b)) return rec(L, m);
	else return rec(m, H);
    } else { // right wide
	a = L + 0 + len / 4;
	m = a + 1 + len / 4 + (len % 4 > 2);
	b = m + 0 + len / 4 + (len % 4 > 1);
	if (query(b, a)) return rec(m, H);
	else return rec(L, m);
    }
}

void MAIN() {
    scanf("%d%d", &N, &K);
//    test_init();
    

    int x, y;
    left_wide = true;
    x = rec(0, N);
    eprintf("%d\n", x);

    if (x == 0) {
	left_wide = true;
	y = rec(1, N);
    } else if (x == N-1) {
	left_wide = false;
	y = rec(0, N-1);
    } else {
	left_wide = false;
	int t = rec(0, x);
	if (query(t, x)) {
	    y = t;
	} else {
	    left_wide = true;
	    y = rec(x+1, N);
	}
    }

    printf("2 %d %d\n", x+1, y+1);
    fflush(stdout);
//    check(x, y);
}


int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}