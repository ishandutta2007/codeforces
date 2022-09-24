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

int N, K;
char A[1000011];
char B[1000011];
int CA[33];
int CB[33];

void MAIN() {
    scanf("%d%d", &N, &K);
    scanf("%s%s", A, B);

    memset(CA, 0, sizeof CA);
    memset(CB, 0, sizeof CB);
    REP (i, N) {
	CA[A[i]-'a']++;
	CB[B[i]-'a']++;
    }

    bool yes = true;

    REP (a, 26) {
	if (CA[a] < CB[a]) {
	    yes = false;
	    break;
	}
	int g = (CA[a] - CB[a]) / K;
	CA[a] -= g * K;
	CA[a+1] += g * K;
	if (CA[a] != CB[a]) {
	    yes = false;
	    break;
	}
    }

    puts(yes? "Yes": "No");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}