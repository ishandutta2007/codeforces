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
LL gcd(LL x_, LL y_) {
    typedef unsigned long long ULL;
    ULL x = abs(x_);
    ULL y = abs(y_);
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

int N;
char S[500011];
int sums[500011];
int ans[500011];

void MAIN() {
    scanf("%d", &N);
    scanf("%s", S);
    REP (i, N) sums[i+1] = sums[i] + (S[i] == 'D'? 1: 0);

    REP (i, N+1) ans[i] = 1;

    REP (i, N) {
	if (S[i] != S[0]) break;
	amax(ans[i+1], i+1);
    }

    vector<pair<int, int> > V, W;
    REP (i, N) {
	int a = sums[i+1];
	int b = i+1-a;

	int g = gcd(a, b);
	a /= g;
	b /= g;
	V.emplace_back(a, b);
	if (a && b) {
	    W.emplace_back(a, b);
	}
    }

    W = V;
    sort_unique(W);
    VI X(W.size());
    REP (i, N) {
	int a = V[i].first;
	int b = V[i].second;
	if (a && b) {
	    int k = lower_bound(W.begin(), W.end(), V[i]) - W.begin();
	    amax(ans[i+1], X[k]+1);
	    X[k]++;
	}
    }

    rprintf("%d", ans+1, ans+N+1);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}