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

const int MAX = 200000;
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

int K;
vector<pair<int, int> > fast_prime_factor(int n) { // n<=MAX
    vector<pair<int, int> > r;
    while (n > 1) {
	int t = min_factor[n], cnt = 0;
	while (n%t == 0) { n /= t, cnt++; }
	cnt %= K;
	if (cnt) {
	    r.emplace_back(t, cnt);
	}
    }
    return r;
}

int N;
int A[100011];

void MAIN() {
    make_prime();

    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

#ifdef MYTEST
    N = 100000;
    K = 2;
    REP (i, N) A[i] = 30030;
#endif

    vector<vector<pair<int, int> > > X;
    X.reserve(N);
    REP (i, N) {
	auto f = fast_prime_factor(A[i]);
	X.push_back(f);
    }

    sort(X.begin(), X.end());
    LL ans = 0;
    EACH (e, X) {
	vector<pair<int, int> > key = *e;
	EACH (g, key) {
	    g->second = K - g->second;
	}
	auto p = equal_range(X.begin(), X.end(), key);
	ans += p.second - p.first;
	if (key == *e) ans--;
    }

    ans /= 2;
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}