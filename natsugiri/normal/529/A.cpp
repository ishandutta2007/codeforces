#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }
// <O(nlogn), O(1)>
template<class T>
struct IRMQ {
    vector<T> A;
    vector<vector<int> > M;
    IRMQ(const vector<T> &A_): A(A_) {
	int N = A.size(), LOGN = __lg(N)+1;
	M.resize(LOGN);
	for (int i=0; i<LOGN; i++) M[i].resize(N);
	for (int j=0; j<N; j++) M[0][j] = j;
	for (int i=0; i<LOGN-1; i++)
	    for (int j=0; j+(1<<i)<N; j++)
		if (A[M[i][j+(1<<i)]] < A[M[i][j]]) M[i+1][j] = M[i][j+(1<<i)];
		else M[i+1][j] = M[i][j];
    }
    T min_v(int l, int r) { // assert(0 <= l < r <= N)
	return A[min_i(l, r)];
    }
    int min_i(int l, int r) {
	int d = __lg(r-l);
	if (A[M[d][r-(1<<d)]] < A[M[d][l]]) return M[d][r-(1<<d)];
	else return M[d][l];
    }
};
struct SAIS {
    string str;
    vector<int>S, SA, lcp, rank;
    int A_SIZE;
    int N;

    vector<int>t, B;
    enum { STYPE, LTYPE };

    bool is_lms(int i) {
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
	    int j = SA[i]-1;
	    if (j >= 0 && S[j] >= S[j+1]) SA[B[S[j]-1]++] = j;
	}
	bucket();
	for (int i=N; i--; ) {
	    int j = SA[i]-1;
	    if (j >= 0 && S[j] <= S[j+1]) SA[--B[S[j]]] = j;
	}
    }
    SAIS(const vector<int>&S, int A_SIZE) : S(S), A_SIZE(A_SIZE) {
	N = S.size();
	SA = vector<int>(N, -1);
	if (N==1) {
	    SA[0] = 0;
	    return;
	}
	t = vector<int>(N, STYPE);
	for (int i=N-1; i--;)
	    if (S[i] > S[i+1] || (S[i] == S[i+1] && t[i+1] == LTYPE))
		t[i] = LTYPE;
	bucket();
	for (int i=N; i--;)
	    if (is_lms(i)) SA[--B[S[i]]] = i;
	induced_sort();

	int N1 = 0;
	for (int i=0; i<N; i++) if (is_lms(SA[i])) SA[N1++] = SA[i];

	fill(SA.begin()+N1, SA.end(), -1);
	int name = 0, prev = -1;
	for (int i=0; i<N1; i++) {
	    int cur = SA[i];
	    bool diff = (prev == -1);
	    for (int j=0; !diff; j++) {
		if (j>0 && is_lms(cur+j)) break;
		if (S[cur+j] != S[prev+j]) diff = true;
	    }
	    if (diff) name++;
	    SA[N1+cur/2] = name-1;
	    prev = cur;
	}
	vector<int> S1, SA1(N1);
	for (int i=N1; i<N; i++) if (SA[i]>=0) S1.push_back(SA[i]);
	if (name == N1) for (int i=0; i<N1; i++) SA1[S1[i]] = i;
	else SA1 = SAIS(S1, name).SA;

	N1 = 0;
	for (int i=0; i<N; i++) if (is_lms(i)) S1[N1++] = i;
	for (int i=0; i<N1; i++) SA1[i] = S1[SA1[i]];

	fill(SA.begin(), SA.end(), -1);
	bucket();
	for (int i=N1; i--;) {
	    int j = SA1[i];
	    SA[--B[S[j]]] = j;
	}
	induced_sort();
        make_lcp();
    }
    SAIS(const string &str_) : str(str_) {
	N = str.size()+1;
	S = vector<int>(N, 0);
	for (int i=0; i<N; i++) S[i] = str[i];
	*this = SAIS(S, 256);
    }

    bool find(const string&P) {
	int l = 0, r = N;
	for (;r-l>1;) {
	    int m = (r+l)/2;
	    SA[m];
	    if (str.compare(SA[m], P.size(), P) < 0) l = m;
	    else r = m;
	}
	return str.compare(SA[r], P.size(), P) == 0;
    }

    void make_lcp() {
	rank = lcp = vector<int>(N);
	for (int i=0; i<N; i++) rank[SA[i]] = i;
	int h = 0;
	for (int i=0; i<N-1; i++) {
	    int j = SA[rank[i]-1];
	    if (h>0) h--;
	    for (; j+h<N && i+h<N; h++) if (S[j+h] != S[i+h]) break;
	    lcp[rank[i]-1] = h;
	}
    }
};


char S[2000111];
int sums[2000111];
int seq[2000111];
int M;


int main() {
    scanf("%s", S);
    int N = strlen(S);
    int cnt = 0, mi = 0;
    REP (i, N) {
        if (S[i] == '(') cnt++;
        else cnt--;
        amin(mi, cnt);
    }

    string str(S); str += str;

    SAIS sais(str);

    const VI &rank = sais.rank;
    
    REP (i, 2*N) {
        sums[i+1] = sums[i];
        if (S[i%N] == '(') sums[i+1]++;
        else sums[i+1]--;
    }

    vector<int> D(sums, sums+2*N);
    IRMQ<int> rmq(D);
    
    int open = 0;
    for (int i=2*N-1; i--;) {
        if (S[i%N] == '(') open++;
        else open = 0;
        seq[i] = open;
    }
    
    if (cnt <= 0) {    
        int p = -1;

        REP (i, N) {
            if (rmq.min_v(i, i+N) - sums[i] >= cnt) {
                if (p == -1 || rank[p] > rank[i]) p = i;
            }
        }
        REP (i, -cnt) putchar('(');
        REP (i, N) putchar(S[(i+p)%N]);
        putchar('\n');
    } else {
        int p = -1;
        REP (i, N) {
            if (rmq.min_v(i, i+N) - sums[i] >= 0) {
                if (p == -1 || rank[p] > rank[i]) p = i;
            }
        }
        REP (i, N) putchar(S[(i+p)%N]);
        REP (i, cnt) putchar(')');
        putchar('\n');

    }
    
    return 0;
}