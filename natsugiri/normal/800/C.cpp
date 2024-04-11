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

// xs + yt = gcd(x, y), xu + yv = 0
LL extgcd(LL x, LL y, LL&s, LL&t) {
    for (LL u=t=1, v=s=0; x; ) {
	LL q = y / x;
	swap(s -= q * u, u);
	swap(t -= q * v, v);
	swap(y -= q * x, x);
    }
    return y;
}

LL invMod(LL a, LL mod) {
    LL x, y;
    if (extgcd(a, mod, x, y) == 1) return (x + mod) % mod;
    return 0; // unsolvable
}

int K, M;
int A[200111];
bool kill[200111];
int C[200111];
VI G[200111];
int dp[200111], to[200111];

void MAIN() {
    scanf("%d%d", &K, &M);
    REP (i, K) scanf("%d", A+i), kill[A[i]] = true;

    VI D;
    for (int i=1; i*i<=M; i++) {
	if (M % i == 0) {
	    D.push_back(i);
	    if (i*i < M) D.push_back(M / i);
	}
    }

    sort(D.begin(), D.end());
    EACH (e, D) {
	for (int v=*e; v<M; v+=*e)
	    C[v] = *e;
    }

    for (int i=1; i<M; i++) if (!kill[i]) G[C[i]].push_back(i);
    for (int i=D.size(); i--;) {
	int v = D[i];
	dp[v] = -1;
	to[v] = -1;
	for (int j=i+1; j<(int)D.size(); j++) {
	    int w = D[j];
	    if (w % v == 0) {
		if (dp[v] < dp[w]) {
		    dp[v] = dp[w];
		    to[v] = w;
		}
	    }
	}
	dp[v] += G[v].size();
    }

    VI ans;
    LL cur = 1, pre = 1, de = 1;
    while (cur != -1) {
	EACH (e, G[cur]) {
	    LL z = invMod(pre / de, M / de);
	    LL tmp = (LL)*e / de * z % M;
	    if (tmp < 0) tmp += M;
	    ans.push_back(tmp);
	    de = cur;
	    pre = *e;
	}
	cur = to[cur];
    }

    if (!kill[0]) ans.push_back(0);
    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());

#ifdef LOCAL
    if (1) {
	LL z = 1;
	REP (i, ans.size()) {
	    z = z * ans[i] % M;
	    eprintf("%lld ", z);
	    if (ans[i] < 0 || M <= ans[i]) {
		eprintf("%d out of bound\n", ans[i]);
		exit(-1);
	    }
	    if (kill[z]) {
		eprintf("out %lld at %d\n", z, i);
		exit(-1);
	    }
	    kill[z] = true;
	}
    }
#endif
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}