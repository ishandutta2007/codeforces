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

const int MAX = 5100000;
int min_factor[MAX+1];
int normal[MAX+1];
int pc[MAX+1];

void init() {
    for (int i=2; i<=MAX; i+=2) min_factor[i] = 2;
    for (int i=3; i<=MAX; i+=3) if (!min_factor[i]) min_factor[i] = 3;
    for (int i=5, d=2; i*i<=MAX; ) {
	if (!min_factor[i]) {
	    min_factor[i] = i;
	    for (int j=i*i; j<=MAX; j+=i)
		if (!min_factor[j]) min_factor[j] = i;
	}
	i += d; d = 6 - d;
    }
    for (int i=2; i<=MAX; i++) {
	if (min_factor[i]==0) min_factor[i] = i;
    }

    REP (i, MAX+1) normal[i] = i;
    for (int i=2; i<=MAX; i++) if (min_factor[i] == i) {
	for (int k=i; k<=MAX; k+=i) {
	    int cnt = 0;
	    while (normal[k] % i == 0) {
		normal[k] /= i;
		cnt++;
	    }
	    if (cnt & 1) {
		normal[k] *= i;
		pc[k]++;
	    }
	}
    }
}

void rec(int x, int acc, VI &ret) {
    if (x == 1) {
	ret.push_back(acc);
    } else {
	int p = min_factor[x];
	rec(x/p, acc, ret);
	rec(x/p, acc*p, ret);
    }
}

VI divisors(int x) {
    VI ret;
    rec(x, 1, ret);
    return ret;
}

int N, Q;
int A[200111];
int ans[1050111];
int dp[MAX+1][8];
int right_most[20];

struct Query {
    int l, r, i;
    bool operator<(const Query &y) const {
	return r < y.r;
    }
};
vector<Query> VQ;

void MAIN() {
    init();
    scanf("%d%d", &N, &Q);
    VQ.reserve(Q);

    REP (i, N) {
	scanf("%d", A+i);
    }
    REP (i, Q) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--;
	Query q;
	q.l = l;
	q.r = r;
	q.i = i;
	VQ.push_back(q);
    }
    sort(VQ.begin(), VQ.end());

    int cur = 0;
    memset(dp, -1, sizeof dp);
    memset(right_most, -1, sizeof right_most);

    EACH (e, VQ) {
	int l = e->l;
	int r = e->r;
//	eprintf("%d %d\n", l+1, r);

	while (cur < r) {
	    int x = normal[A[cur]];
	    VI D = divisors(x);
	    EACH (f, D) {
		int c = pc[x / *f];
		REP (t, 8) {
		    amax(right_most[c+t], dp[*f][t]);
		}
		dp[*f][c] = cur;
	    }
	    cur++;
	}

	ans[e->i] = 1000;
	REP (t, 20) if (right_most[t] >= e->l) {
	    ans[e->i] = t;
	    break;
	}
    }

    REP (i, Q) printf("%d\n", ans[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}