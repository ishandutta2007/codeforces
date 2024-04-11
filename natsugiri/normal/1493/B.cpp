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

int F(int X) {
    if (X == 0) return 0;
    if (X == 1) return 1;
    if (X == 2) return 5;
    if (X == 5) return 2;
    if (X == 8) return 8;
    return -1;
}

int FLIP(int X) {
    int a = F(X % 10);
    int b = F(X / 10);
    if (a == -1 || b == -1) return -1;
    return a * 10 + b;
}


void MAIN() {
    int H, M;
    int A, B;
    scanf("%d%d%d:%d", &H, &M, &A, &B);
    while (1) {
	int A2 = FLIP(A);
	int B2 = FLIP(B);
	if (A2 != -1 && B2 != -1 && B2 < H && A2 < M) break;

	B++;
	if (B == M) {
	    B = 0;
	    A++;
	}
	if (A == H) {
	    A = 0;
	}
    }

    printf("%02d:%02d\n", A, B);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}