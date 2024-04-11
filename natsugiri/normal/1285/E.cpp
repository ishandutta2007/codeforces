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

template<class T> vector<int> compress(const vector<T> &v, vector<T> *unq=NULL) {
    int n = v.size();
    vector<pair<T, int> > t(n);
    for (int i=0; i<n; i++) t[i] = make_pair(v[i], i);
    sort(t.begin(), t.end());
    vector<int> r(n);
    int cur = 0;
    for (int i=0, k=0; i<n; i++) {
	if (t[k].first < t[i].first) k = i, cur++;
	r[t[i].second] = cur;
    }
    if (unq) {
	unq->resize(cur+1);
	cur = 0;
	for (int i=0; i<n; i++)
	    if (i == 0 || t[i-1].first < t[i].first)
		(*unq)[cur++] = t[i].first;
    }
    return r;
}
int N;
int L[200011], R[200011];
const int SIZE = 400011;
int F[SIZE+10], G[SIZE+10];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d%d", L+i, R+i);
	L[i] = 2*L[i];
	R[i] = 2*R[i]+1;
    }

    VI X; X.reserve(N+N);
    REP (i, N) {
	X.push_back(L[i]);
	X.push_back(R[i]);
    }

    int LEN = N+N+5;
    memset(F, 0, sizeof (int) * (LEN));
    memset(G, 0, sizeof (int) * (LEN));

    VI Y = compress(X);
    REP (i, N) {
	L[i] = Y[i*2];
	R[i] = Y[i*2+1];
	
	F[L[i]]++;
	F[R[i]]--;
    }
    REP (i, LEN) F[i+1] += F[i];
    REP (i, LEN) {
	G[i+1] += G[i];
	if (F[i] == 1) G[i+1]++;
    }

    vector<pair<int, int> > p, st;
    REP (i, N) p.emplace_back(L[i], R[i]);
    sort(p.begin(), p.end());
    EACH (e, p) {
	if (st.empty() || st.back().second <= e->first) {
	    st.push_back(*e);
	} else {
	    amax(st.back().second, e->second);
	}
    }

    int base = st.size();

    int ans = 0;
    REP (i, N) {
	int g = G[R[i]] - G[L[i]];
	if (g == 0) {
	     amax(ans, base);
	} else if (L[i] + 1 == R[i] && g == 1) {
	    amax(ans, base - 1);
	} else {
	    if (F[L[i]] == 1) g--;
	    if (F[R[i]-1] == 1) g--;
	    amax(ans, base + g);
	}
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}