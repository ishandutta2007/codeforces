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

char alpha;
string rec(int N) {
    string ret;
    if (N <= 6) {
	REP (i, N) {
	    ret.push_back(alpha++);
	}
	return ret;
    }

    // 4 -> AxyAxAx;
    // 5 -> xAxAxxAx;
    // 6 -> AxxyAyyxA;


    int r = N % 3;
    while (r <= 3) r += 3;

    string tmp = rec((N-r)/3);
    if (r == 4) {
	char x = alpha++;
	char y = alpha++;
	ret += tmp;
	ret.push_back(x);
	ret.push_back(y);
	ret += tmp;
	ret.push_back(x);
	ret += tmp;
	ret.push_back(x);
    } else if (r == 5) {
	char x = alpha++;
	ret.push_back(x);
	ret += tmp;
	ret.push_back(x);
	ret += tmp;
	ret.push_back(x);
	ret.push_back(x);
	ret += tmp;
	ret.push_back(x);
    } else {
	char x = alpha++;
	char y = alpha++;
	ret += tmp;
	ret.push_back(x);
	ret.push_back(x);
	ret.push_back(y);
	ret += tmp;
	ret.push_back(y);
	ret.push_back(y);
	ret.push_back(x);
	ret += tmp;
    }
    return ret;
}

void MAIN() {
    int N;
    scanf("%d", &N);
    alpha = 'a';
    string ans = rec(N);
    puts(ans.c_str());
#ifdef LOCAL
    assert((int)ans.size() == N);
    printf("%c\n", alpha-1);
#endif
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}