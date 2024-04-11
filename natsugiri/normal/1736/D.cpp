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

int N;
char S[200011];

void MAIN() {
    scanf("%d%s", &N, S);

#ifdef LOCAL
    N = 200;
    static char aux[10000];
    REP (i, N) aux[i] = rand() % 2 + '0';
    VI bit;
    REP (i, N) {
	bit.push_back(0);
	bit.push_back(1);
    }
    random_shuffle(bit.begin(), bit.end());
    int C[2] = {};
    REP (i, N*2) {
	S[i] = aux[C[bit[i]]++];
    }
#endif

    N += N;
    int zero = count(S, S+N, '0');
    if (zero % 2) {
	puts("-1");
	return;
    }

    VI B;

    for (int i=0; i<N; i+=2) {
	if (S[i] != S[i+1]) {
	    int a = i;
	    if ((B.size() % 2 == 0 && S[i] == '0') || (B.size() % 2 == 1 && S[i] == '1')) {
		a = i+1;
	    }
	    B.push_back(a);
	}
    }

    printf("%d", (int)B.size());
    REP (i, B.size()) printf(" %d", B[i]+1);
    puts("");

    if (B.size()) {
	char prv = S[B.back()];
	REP (i, B.size()) {
	    swap(S[B[i]], prv);
	}
    }

    REP (i, N/2) printf("%d%c", i*2+1, " \n"[i==N/2-1]);

#ifdef LOCAL
    puts(S);
#endif
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}