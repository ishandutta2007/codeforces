#include<set>
#include<bitset>
#include<array>
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

int N, K;

using Arr = array<int, 5>;

int cnt;
Arr A[120];
map<Arr, int> name;

int F[120][120];

int P[200011];

int prv[120];

using Bits = bitset<128>;
void apply(Bits &b, const int idx, const VI &u) {
    static int stk[128];
    int len = 0;

    REP (i, cnt) if (b.test(i)) {
	int k = F[i][idx];
	if (!b.test(k)) {
	    b.set(k);
	    stk[len++] = k;
	}
    }

    for (int i_=0; i_<len; i_++) {
	int a = stk[i_];
	EACH (e, u) {
	    int k = F[a][*e];
	    if (!b.test(k)) {
		b.set(k);
		stk[len++] = k;
	    }
	}
    }
    assert(len <= cnt);
}

void MAIN() {
    scanf("%d%d", &N, &K);

#ifdef TEST
    N = 200000;
    K = 5;
#endif

    {
	Arr g = {};
	REP (i, K) g[i] = i;
	do {
	    name[g] = cnt;
	    A[cnt] = g;
	    cnt++;
	} while (next_permutation(g.begin(), g.begin() + K));

	REP (i, cnt) {
	    REP (j, cnt) {
		REP (k, K) {
		    g[k] = A[i][A[j][k]];
		}
		F[i][j] = name[g];
	    }
	}
    }

    Arr p = {};
#ifdef TEST
    REP (i, N) {
	P[i] = rand() % cnt;
    }
#else
    REP (i, N) {
	REP (j, K) scanf("%d", &p[j]), p[j]--;
	P[i] = name[p];
    }
#endif

    memset(prv, -1, sizeof prv);
    LL ans = 0;
    set<int> se;
    se.insert(-1);
    Bits b = {};
    VI u;
    REP (i, N) {
	b.reset();
	u.clear();
	b.set(0);
	u.push_back(P[i]);
	apply(b, P[i], u);
//	REP (t, 24) eprintf("%d", (int)b[t]);
//	eprintf(" (%d)\n", P[i]);

	auto it = se.end();
	int r = i;
	while (1) {
	    --it;
//	    eprintf("i %d, (%d %d], %d\n", i, *it, r, (int)b.count());
	    LL c = b.count(); 
	    ans += (LL)(r - *it) * c;
	    if (*it == -1) break;
	    r = *it;

	    if (c < cnt) {
		u.push_back(P[*it]);
		apply(b, P[*it], u);
	    }
	}

	if (prv[P[i]] != -1) {
	    se.erase(prv[P[i]]);
	}
	prv[P[i]] = i;
	se.insert(i);
	// eprintf("%d size %d %d\n", i, (int)se.size(), (int)u.size());
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}