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

//public:
//    IRMQ<int> rmq;
//    void buildRMQ() {
//	rmq = IRMQ<int>(lcp.begin(), lcp.end());
//    }
//    int common_prefix(int x, int y) {
//	if (x == y) return N-1-x;
//	if (y >= N-1) return 0;
//	if (rank[x] > rank[y]) swap(x, y);
//	return rmq.min_v(rank[x], rank[y]);
//    }
//    int compare(int x, int xn, int y, int yn) {
//	int l = common_prefix(x, y);
//	if (l >= xn || l >= yn) return xn < yn ? -1 : xn == yn ? 0 : 1;
//	return rank[x] < rank[y] ? -1 : x == y ? 0 : 1;
//    }
};
vector<int>Z_Algorithm(const string&s) {
    int n=s.size();
    vector<int>z(n);
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
	if (i > r) {
	    l = r = i;
	    while (r<n && s[r-l] == s[r]) r++;
	    z[i] = r-l; r--;
	} else {
	    int k = i-l;
	    if (z[k] < r-i+1) z[i] = z[k];
	    else {
		l = i;
		while (r<n && s[r-l] == s[r]) r++;
		z[i] = r-l; r--;
	    }
	}
    }
    return z;
}

int N, M;
LL K;
string S, P;
char buf[1011];

int least[1011];

inline void aadd(LL &a, LL b) {
    a += b;
    amin(a, 1LL<<60);
}

LL dp[1011][1011];

// N*M;
LL calc() {
    VI z = Z_Algorithm(P + " " + S);
    REP (i, S.size()) {
	int len = z[(int)P.size()+1+i];
	if (len >= (int)P.size()) {
	    least[i] = i+len;
	} else if (P[len] < S[i+len]) {
	    least[i] = i+len+1;
	} else {
	    least[i] = -1;
	}
    }
    // rprintf("%d", least, least+N);
    if (least[0] == -1) return 0;

    memset(dp, 0, sizeof dp);
    dp[least[0]][0] = 1;

    REP (i, N) REP (m, M) if (dp[i][m]) {
	aadd(dp[i+1][m], dp[i][m]);
	if (least[i] > -1) aadd(dp[least[i]][m+1], dp[i][m]);
    }

    //eprintf("?? %s %lld\n", P.c_str(), dp[N][M-1]);
    return dp[N][M-1];
}

void MAIN() {
    scanf("%d%d%lld", &N, &M, &K);
    scanf("%s", buf);
    S = buf;

    SAIS sais(S);
    vector<pair<int, int> > vp;
    REP (i, N) for (int j=i+1; j<=N; j++) {
	vp.emplace_back(i, j-i);
    }
    sort(vp.begin(), vp.end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
	    if (a.first == b.first) return a.second < b.second;
	    return S.compare(a.first, a.second, S, b.first, b.second) < 0;
	    });
    int lo = 0, hi = vp.size();
    while (hi - lo > 1) {
	int mid = (lo + hi) / 2;
	P = S.substr(vp[mid].first, vp[mid].second);
	if (calc() >= K) lo = mid;
	else hi = mid;
    }
    puts(S.substr(vp[lo].first, vp[lo].second).c_str());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}