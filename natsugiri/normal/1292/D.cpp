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
const int MAX = 10011;
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


const int MAXN = 100111;
int C[5011];

struct Data {
    int k;
    int c;
    int x;
    bool operator<(const Data &o) const {
	return x < o.x;
    }
};


void MAIN() {
    make_prime();

    int N;
    scanf("%d", &N);
    REP (i, N) {
	int k;
	scanf("%d", &k);
	if (k == 0) k = 1;
	C[k]++;
    }

#ifdef MYTEST
    N = 1000000;
    memset(C, 0, sizeof C);
    REP (i, N) C[rand() % 5000 + 1]++;
#endif

    LL ans = 0;
    LL cst = 0;
    for (int i=1; i<=5000; i++) {
	int m = i;
	for (int j=2; j*j<=m; j++) {
	    while (m % j == 0) {
		cst++;
		m /= j;
	    }
	}
	if (m > 1) cst++;
	ans += C[i] * cst;
    }

    vector<Data> D;
    REP (i, 5001) if (C[i]) D.push_back((Data){ i, C[i], 0 });
    int idx = prime.size()-1;

    while (idx>=0) {
	bool edge = false;
	const int p = prime[idx];
	EACH (e, D) {
	    e->x = 0;
	    int k = e->k;
	    while (k >= p) {
		k /= p;
		e->x += k;
	    }
	    if (e->x) edge = true;
	}

	if (edge) {
	    sort(D.begin(), D.end());

	    vector<LL> h(D.back().x+1);
	    vector<LL> c(D.back().x+1);
	    h[0] = ans;
	    int subsize = 0;
	    EACH (e, D) subsize += e->c;
	    int i = 0;
	    REP (t, (int)h.size()-1) {
		int g = 0;
		while (i < (int)D.size() && D[i].x == t) {
		    g += D[i].c;
		    i++;
		}

		subsize -= g;
		h[t+1] = h[t] - subsize + (N-subsize);
		c[t] = g;
	    }
	    c[D.back().x] = subsize;

	    LL guess = *min_element(h.begin(), h.end());
	    amin(ans, guess);
	    vector<Data> nxt;

	    REP (t, h.size()) if (c[t]*2 > N) {
		EACH (e, D) if (e->x == t) nxt.push_back(*e);
		break;
	    }
	    if (nxt.empty()) break;
	    swap(D, nxt);
	}

	idx--;
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}