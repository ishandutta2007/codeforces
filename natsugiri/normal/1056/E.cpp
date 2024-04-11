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
template<class T> struct IRMQ {
    static const int npos = -1;

    int n, g; T *d;
    IRMQ() : n(0), g(0), d(NULL) {}
    template<class Iter> IRMQ(Iter begin, Iter end) : n(0), g(0), d(0) { build(begin, end); }
    IRMQ(const IRMQ &y) : n(y.n), g(0), d(NULL) { if (y.n) build(y.d[0], y.d[0] + n); }
    IRMQ(IRMQ &&y) : n(0), g(0), d(NULL) { swap(*this, y); }
    ~IRMQ() { if (n) { n = 0; delete d; d = NULL; } }
    friend void swap(IRMQ &x, IRMQ &y) { swap(x.n, y.n); swap(x.g, y.g); swap(x.d, y.d); }
    IRMQ& operator=(IRMQ y) { swap(*this, y); return *this; }

    template<class Iter> void build(Iter begin, Iter end) { // random access iterator
	n = end - begin;
	if (n == 0) return;
	g = __lg(n);
	d = new T[n*(g+1)];
	REP (i, n) { d[i] = *begin; ++begin; }
	for (int t=0, b=0; t<g; t++, b+=n) for (int i=0, j=1<<t; j<=n-(1<<t); i++, j++)
	    d[b+n+i] = (d[b+j] < d[b+i]? d[b+j]: d[b+i]);
    }

    const T at(int i) const { return d[i]; }

    const T min_v(int l, int r) const {
	int h = __lg(r - l), b = n * h;
	r -= 1<<h;
	return d[b+r] < d[b+l]? d[b+r]: d[b+l];
    }

    int min_i(int l, int r) const {
	return first_less_equal(l, min_v(l, r));
    }

    // for i in [l .. n-1]:
    //   if at(i) < v: return i;
    // return npos;
    int first_less_than(int l, const T v) const {
	for (int t=g+1; t--; )
	    if (l + (1<<t) <= n && !(d[n*t+l] < v))
		l += 1 << t;
	return l<n? l: npos;
    }

    // for i in [l .. n-1]:
    //   if at(i) <= v: return i;
    // return npos;
    int first_less_equal(int l, const T v) const {
	for (int t=g+1; t--; )
	    if (l + (1<<t) <= n && v < d[n*t+l])
		l += 1 << t;
	return l<n? l: npos;
    }

    // for i in [r-1 .. 0]:
    //   if at(i) < v: return i;
    // return npos;
    int last_less_than(int r, const T v) const {
	for (int t=g+1; t--; )
	    if (0 <= r - (1<<t) && !(d[n*t+r-(1<<t)] < v))
		r -= 1 << t;
	return r? r-1: npos;
    }

    // for i in [r-1 .. 0]:
    //   if at(i) < v: return i;
    // return npos;
    int last_less_equal(int r, const T v) const {
	for (int t=g+1; t--; )
	    if (0 <= r - (1<<t) && v < d[n*t+r-(1<<t)])
		r -= 1 << t;
	return r? r-1: npos;
    }
};

class SAIS {
public: 
    vector<int> sa, lcp, rank;
    SAIS(){}
    SAIS(const string &str_) : str(str_) {
	N = str.size()+1;
	S = vector<int>(N, 0);
	for (int i=0; i<N; i++) S[i] = str[i];
	*this = SAIS(S, 256);
    }
    SAIS(const vector<int> &S_, int A_SIZE_, bool lcp_flag=true) : S(S_), A_SIZE(A_SIZE_) {
	buildSA();
	if (lcp_flag) buildLCP();
    }
private:
    string str;
    vector<int> S;
    int A_SIZE;
    int N;
    vector<int> t, B;
    enum { STYPE, LTYPE };

    inline bool is_lms(int i) {
	return i>0 && t[i] == STYPE && t[i-1] == LTYPE;
    }
    void bucket() {
	B = vector<int>(A_SIZE);
	for (int i=0; i<N; i++) B[S[i]]++;
	for (int i=0; i<A_SIZE-1; i++) B[i+1] += B[i];
    }
    void induced_sort() {
	bucket();
	for (int i=0; i<N; i++) {
	    int j = sa[i]-1;
	    if (j >= 0 && S[j] >= S[j+1]) sa[B[S[j]-1]++] = j;
	}
	bucket();
	for (int i=N; i--; ) {
	    int j = sa[i]-1;
	    if (j >= 0 && S[j] <= S[j+1]) sa[--B[S[j]]] = j;
	}
    }
    void buildSA() {
	N = S.size();
	sa.assign(N, -1);
	if (N == 1) {
	    sa[0] = 0;
	    return;
	}
	t.assign(N, STYPE);
	for (int i=N-1; i--;)
	    if (S[i] > S[i+1] || (S[i] == S[i+1] && t[i+1] == LTYPE))
		t[i] = LTYPE;
	bucket();
	for (int i=N; i--;)
	    if (is_lms(i)) sa[--B[S[i]]] = i;
	induced_sort();

	int N1 = 0;
	for (int i=0; i<N; i++) if (is_lms(sa[i])) sa[N1++] = sa[i];

	fill(sa.begin()+N1, sa.end(), -1);
	int name = 0, prev = -1;
	for (int i=0; i<N1; i++) {
	    int cur = sa[i];
	    bool diff = (prev == -1);
	    for (int j=0; !diff; j++) {
		if (j>0 && is_lms(cur+j)) break;
		if (S[cur+j] != S[prev+j]) diff = true;
	    }
	    if (diff) name++;
	    sa[N1+cur/2] = name-1;
	    prev = cur;
	}
	vector<int> S1, sa1(N1);
	for (int i=N1; i<N; i++) if (sa[i]>=0) S1.push_back(sa[i]);
	if (name == N1) for (int i=0; i<N1; i++) sa1[S1[i]] = i;
	else sa1 = SAIS(S1, name, false).sa;

	N1 = 0;
	for (int i=0; i<N; i++) if (is_lms(i)) S1[N1++] = i;
	for (int i=0; i<N1; i++) sa1[i] = S1[sa1[i]];

	fill(sa.begin(), sa.end(), -1);
	bucket();
	for (int i=N1; i--;) {
	    int j = sa1[i];
	    sa[--B[S[j]]] = j;
	}
	induced_sort();
    }
    void buildLCP() {
	rank.resize(N);
	lcp.resize(N-1);
	for (int i=0; i<N; i++) rank[sa[i]] = i;
	int h = 0;
	for (int i=0; i<N-1; i++) {
	    int j = sa[rank[i]-1];
	    if (h>0) h--;
	    for (; j+h<N && i+h<N && S[j+h] == S[i+h]; h++) ;
	    lcp[rank[i]-1] = h;
	}
    }

public:
    IRMQ<int> rmq;
    void buildRMQ() {
	rmq = IRMQ<int>(lcp.begin(), lcp.end());
    }
    int common_prefix(int x, int y) {
	if (x == y) return N-1-x;
	if (y >= N-1) return 0;
	if (rank[x] > rank[y]) swap(x, y);
	return rmq.min_v(rank[x], rank[y]);
    }
    int compare(int x, int xn, int y, int yn) {
	int l = common_prefix(x, y);
	if (l >= xn || l >= yn) return xn < yn ? -1 : xn == yn ? 0 : 1;
	return rank[x] < rank[y] ? -1 : x == y ? 0 : 1;
    }
};

string S, T;


void MAIN() {
    cin >> S >> T;

    SAIS sais(T);
    sais.buildRMQ();
    int cnt0 = count(S.begin(), S.end(), '0');
    int cnt1 = count(S.begin(), S.end(), '1');

    int ans = 0;
    
    for (int len0=1; len0*cnt0 <= (int)T.size(); len0++) {
	int rest = (int)T.size() - len0 * cnt0;

	if (rest > 0 && rest % cnt1 == 0) {
	    int len1 = rest / cnt1;
	    int l0, r0, l1, r1;
	    l0 = r0 = l1 = r1 = -1;

	    bool yes = true;
	    int cur = 0;
	    EACH (e, S) {
		int nxt;
		if (*e == '0') {
		    nxt = cur + len0;
		    if (l0 == -1) {
			l0 = cur;
			r0 = nxt;
		    } else if (sais.compare(l0, r0-l0, cur, nxt-cur) != 0) {
			yes = false;
			break;
		    }
		} else {
		    nxt = cur + len1;
		    if (l1 == -1) {
			l1 = cur;
			r1 = nxt;
		    } else if (sais.compare(l1, r1-l1, cur, nxt-cur) != 0) {
			yes = false;
			break;
		    }
		}
		cur = nxt;
	    }

	    if (yes && sais.compare(l0, r0-l0, l1, r1-l1) != 0) {
//		eprintf("%d %d\n", len0, len1);
		ans++;
	    }
	}
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}