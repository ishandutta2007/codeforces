#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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

char A[1111];
char B[1111];
int N, M, K;

void MAIN() {
    scanf("%d%d%d%s%s", &N, &M, &K, A, B);

    sort(A, A+N);
    sort(B, B+M);

    string ans;
    int i = 0, j = 0;
    char prv = 0;
    int streak = 0;

    while (1) {
	if (i == N) break;
	if (j == M) break;
	char nxt = 0;
	if (prv == 'A' && streak == K) {
	    nxt = 'B';
	} else if (prv == 'B' && streak == K) {
	    nxt = 'A';
	} else if (A[i] < B[j]) {
	    nxt = 'A';
	} else {
	    nxt = 'B';
	}
	if (nxt == 'A') {
	    ans.push_back(A[i++]);
	    if (prv == 'A') {
		streak++;
	    } else {
		prv = 'A';
		streak = 1;
	    } 
	} else {
	    ans.push_back(B[j++]);
	    if (prv == 'B') {
		streak++;
	    } else {
		prv = 'B';
		streak = 1;
	    }
	}
    }
    puts(ans.c_str());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}