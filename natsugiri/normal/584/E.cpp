#include<cassert>
#include<stack>
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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

struct RXQ {
    typedef long long T;
    static const T INF = 1LL<<60;
    int N, M; // M == 2**k && M > N
    vector<T> A; vector<int> I; // A[N] == INF
    RXQ(int N_=1): N(N_), M(2<<__lg(max(1, N))), A(N+1, -INF), I(M*2, N) {
        for (int i=0; i<N; i++) I[i+M] = i;
        for (int i=M; --i;) I[i] = I[i*2];
    }
    RXQ(const vector<T> &v): N(v.size()), M(2<<__lg(N)), A(v), I(M*2, N) {
        A.push_back(-INF);
        for (int i=0; i<N; i++) I[i+M] = i;
	for (int i=M; --i;) I[i] = (A[I[i*2]] < A[I[i*2+1]]? I[i*2+1]: I[i*2]);
    }
    void modify(int i, T v) {
	A[i] = v;
	for (i=(i+M)/2; i>1; i/=2)
            I[i] = (A[I[i*2]] < A[I[i*2+1]]? I[i*2+1]: I[i*2]);
    }
    int max_i(int x, int y) { return max_i(x, y, 1, 0, M); }
    int max_i(int x, int y, int k, int l, int r) {
	if (r<=x || y<=l) return N;
	if (x<=l && r<=y) return I[k];
        int p = max_i(x, y, 2*k, l, (l+r)/2), q = max_i(x, y, 2*k+1, (l+r)/2, r);
        return (A[p] < A[q]? q: p);
    }
    T max_v(int x, int y) { return A[max_i(x, y, 1, 0, M)]; }
};
const RXQ::T RXQ::INF;


int N, P[2222], S[2222];
int tar[2222];


int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", P+i);
    REP (i, N) scanf("%d", S+i);

    // N = 2000;
    // REP (i, N) P[i] = S[i] = i+1;
    // random_shuffle(P, P+N);
    // random_shuffle(S, S+N);
    // reverse(S, S+N);

    REP (i, N) {
        tar[S[i]] = i;
    }

    RXQ X(N);
    REP (i, N) X.modify(i, tar[P[i]]);

    int cost = 0;
    VI A, B;
    bool update = true;
    while (update) {
        update = false;
        REP (i, N) if (tar[P[i]] < i) {
            int j = X.max_i(tar[P[i]], i);
            if (i <= tar[P[j]]) {
                swap(P[i], P[j]);
                X.modify(i, tar[P[i]]);
                X.modify(j, tar[P[j]]);
                cost += abs(i - j);
                A.push_back(i+1);
                B.push_back(j+1);
                update = true;
                // REP (k, N) eprintf("%d ", P[k]); eprintf("\n");
                // REP (k, N) eprintf("%d ", S[k]); eprintf("\n");
                // eprintf("\n");
            }
        }

    }

    printf("%d\n", cost);
    printf("%lu\n", A.size());
    REP (i, A.size()) printf("%d %d\n", A[i], B[i]);


    REP (i, N) assert(P[i] == S[i]);

    return 0;
}