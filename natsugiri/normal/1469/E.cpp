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

template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}
int N, K;
char S[1000011];
char ans[1000011];
int sums[1000011];

int eval(int l, int r) {
    int ret = 0;
    for (int i=l; i<r; i++) {
	ret += ret;
	if (S[i] == '1') ret++;
    }
    return ret;
}

VI X;

void MAIN() {
    scanf("%d%d", &N, &K);
    scanf("%s", S);

    REP (i, N) sums[i+1] = sums[i] + (S[i] == '0'? 1: 0);
    
    int tail = min(K, 20);
    int head = K - tail;
    X.clear();

    REP (i, N-K+1) {
	if (sums[i+head] - sums[i]) {
	} else {
	    X.push_back(eval(i+head, i+K));
	}
    }
    sort_unique(X);

    if ((int)X.size() >= (1<<tail)) {
	assert((int)X.size() == (1<<tail));
	puts("NO");
    } else {
	REP (i, head) ans[i] = '0';
	int idx = head;

	int prefix = 0;
	for (int t=tail; t--;) {
	    int zero = lower_bound(X.begin(), X.end(), prefix|1<<t) - X.begin();
	    int one = (int)X.size() - zero;

	    if (one < (1<<t)) {
		ans[idx++] = '0';
		prefix |= 1<<t;
		X.erase(X.begin(), X.begin()+zero);
	    } else {
		ans[idx++] = '1';
		X.erase(X.begin()+zero, X.end());
	    }
	}
	assert(X.empty());
	ans[idx] = 0;
	puts("YES");
	puts(ans);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}