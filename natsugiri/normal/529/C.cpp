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

struct RMQ {
    typedef int T;
    static const T INF = 1<<29;
    int N, M; // M == 2**k && M > N
    vector<T> A; vector<int> I; // A[N] == INF
    RMQ(int N_=1): N(N_), M(2<<__lg(N)), A(N+1, INF), I(M*2, N) {
        for (int i=0; i<N; i++) I[i+M] = i;
        for (int i=M; --i;) I[i] = I[i*2];
    }
    RMQ(const vector<T> &v): N(v.size()), M(2<<__lg(N)), A(v), I(M*2, N) {
        A.push_back(INF);
        for (int i=0; i<N; i++) I[i+M] = i;
        for (int i=M; --i;) I[i] = (A[I[i*2+1]] < A[I[i*2]]? I[i*2+1]: I[i*2]);
    }
    void modify(int i, T v) {
	A[i] = v;
	for (i=(i+M)/2; i>1; i/=2)
            I[i] = (A[I[i*2+1]] < A[I[i*2]]? I[i*2+1]: I[i*2]);
    }
    int min_i(int x, int y) { return min_i(x, y, 1, 0, M); }
    int min_i(int x, int y, int k, int l, int r) {
        if (r<=x || y<=l) return N;
        if (x<=l && r<=y) return I[k];
        int p = min_i(x, y, 2*k, l, (l+r)/2), q = min_i(x, y, 2*k+1, (l+r)/2, r);
        return (A[q] < A[p]? q: p);
    }
    T min_v(int x, int y) { return A[min_i(x, y, 1, 0, M)]; }
};
const RMQ::T RMQ::INF;


struct Rect {
    int x0, y0, x1, y1, id;
    Rect() {}
    Rect(int a, int b, int c, int d, int i): x0(a), y0(b), x1(c), y1(d), id(i) {}
    bool operator<(const Rect &y) const {
        return y1 < y.y1;
    }
};

int N, M, K, Q, X[200111], Y[200111];
pair<int, int> Z[200111];
int P[200111][4];
Rect rect[200111];
bool yes[200111];
void solve() {
    REP (i, K) Z[i] = make_pair(Y[i], X[i]);
    sort(Z, Z+K);
    REP (i, Q) rect[i] = Rect(P[i][0], P[i][1], P[i][2], P[i][3], i);
    sort(rect, rect+Q);

    vector<int> v(100011, -1);
    RMQ rmq(v);
    
    int p = 0;
    REP (i, Q) {
        while (p < K && Z[p].first <= rect[i].y1) {
            rmq.modify(Z[p].second, Z[p].first);
            p++;
        }

        if (rmq.min_v(rect[i].x0, rect[i].x1+1) >= rect[i].y0) yes[rect[i].id] = true;
    }

    REP (i, K) swap(X[i], Y[i]);
    REP (i, Q) swap(P[i][0], P[i][1]), swap(P[i][2], P[i][3]);
    swap(N, M);
}

int main() {
    scanf("%d%d%d%d", &N, &M, &K, &Q);
    REP (i, K) scanf("%d%d", X+i, Y+i);
    REP (i, Q) REP (j, 4) scanf("%d", P[i]+j);

    solve();
    solve();

    REP (i, Q) puts(yes[i] ? "YES": "NO");
    return 0;
}