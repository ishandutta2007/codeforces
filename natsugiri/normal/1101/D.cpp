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

int gcd(int x, int y) {
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

const int MAX = 250000;
int min_factor[MAX+1];
vector<int>prime;
void make_prime() {
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
	if (min_factor[i]==i) prime.push_back(i);
    }
}


VI primes(int n) { // n<=MAX
    VI r;
    while (n > 1) {
	int t = min_factor[n], cnt = 0;
	while (n%t == 0) { n /= t, cnt++; }
	r.push_back(t);
    }
    return r;
}


const int MAXN = 200011;
int N;
int A[MAXN];
VI G[MAXN];
vector<pair<int, int> > P[MAXN];

VI ord;
int par[MAXN];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    ord.push_back(*e);
	}
    }

    int ans = 0;
    REP (i_, N) {
	int v = ord[N-1-i_];
	if (A[v] == 1) {
	    continue;
	}

	VI ps = primes(A[v]);
	amax(ans, 1);

	vector<pair<int, int> > &x = P[v];
	x.reserve(ps.size());
	EACH (e, ps) x.emplace_back(*e, 1);

	EACH (e, G[v]) if (*e != par[v]) {
	    int k = 0;
	    EACH (f, P[*e]) {
		while (k < (int)x.size() && x[k].first < f->first) k++;
		if (k < (int)x.size() && x[k].first == f->first) {
		    amax(ans, x[k].second + f->second);
		    amax(x[k].second, f->second + 1);
		}
	    }
	}
    }

    printf("%d\n", ans);
}

int main() {
    make_prime();
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}