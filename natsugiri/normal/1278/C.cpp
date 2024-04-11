#include<map>
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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
int A[100011];
int B[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);
    reverse(B, B+N);

    int s = 0;
    int eat = N;
    map<int, int> mp;
    mp[s] = N;
    REP (i, N) {
	if (A[i] == 1) s++;
	else s--;
	eat--;
	mp[s] = eat;
    }

    int ans = 2*N;
    s = 0;
    eat = N;
    REP (i, N+1) {
	auto it = mp.find(s);
	if (it != mp.end()) {
	    amin(ans, eat + it->second);
	}

	if (i == N) break;
	if (B[i] == 1) s--;
	else s++;
	eat--;
    }


    printf("%d\n", ans);

}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}