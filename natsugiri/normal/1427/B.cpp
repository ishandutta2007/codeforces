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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, K;
char S[100011];

void MAIN() {
    scanf("%d%d%s", &N, &K, S);

    int ans = 0;

    if (count(S, S+N, 'L') == N) {
	if (K == 0) ans = 0;
	else ans = K * 2 - 1;
    } else {
	REP (i, N) {
	    if (S[i] == 'W') {
		if (i == 0 || S[i-1] == 'L') ans++;
		else ans += 2;
	    }
	}

	int head = 0, tail = 0;
	VI V;

	{
	    int i = 0;
	    while (i < N && S[i] == 'L') i++;
	    head = i;
	    int cnt = 0;
	    for (; i<N; i++) {
		if (S[i] == 'L') cnt++;
		else {
		    if (cnt) V.push_back(cnt);
		    cnt = 0;
		}
	    }

	    tail = cnt;
	}

	sort(V.begin(), V.end());

	EACH (e, V) {
	    if (*e <= K) {
		ans += *e * 2 + 1;
		K -= *e;
	    } else {
		ans += K * 2;
		K = 0;
	    }
	}

	int g;
	g = min(head, K);
	ans += g * 2;
	K -= g;

	g = min(tail, K);
	ans += g * 2;
	K -= g;

    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}