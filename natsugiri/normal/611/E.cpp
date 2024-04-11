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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

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

template<class T>
struct Fenwick : vector<T> {
    typedef vector<T> S;
    int N;
    Fenwick(int N_=0): S(N_), N(N_) {}
    void add(int i, T x) {
	for (; i<N; i|=i+1) S::operator[](i) += x;
    }
    inline T sum(int r) {
	T s = 0;
	for (; r; r&=r-1) s += S::operator[](r-1);
	return s;
    }
    T sum(int l, int r) {
	return sum(r) - sum(l);
    }
};


const int INF = 1<<30;

int N;
int A_[3], T[200111], A, B, C;
int K[8];
int D[3];

int main() {
    scanf("%d", &N);
    REP (i, 3) scanf("%d", A_+i);
    REP (i, N) scanf("%d", T+i);
    sort(A_, A_+3);
    sort(T, T+N);

    REP (s, 8) REP (i, 3) if (s & (1<<i)) K[s] += A_[i];

    VI v(T, T+N), unq;
    REP (s, 8) v.push_back(K[s]);
    VI CO = compress(v, &unq);

    REP (i, N) T[i] = CO[i];
    REP (s, 8) K[s] = CO[s+N];
    A = K[1];
    B = K[2];
    C = K[4];

    // REP (i, N) eprintf("%d ", T[i]); eprintf("\n");
    // REP (s, 8) eprintf("%d ", K[s]); eprintf("\n");
    
    // eprintf("%d %d %d\n", A, B, C);


    if (T[N-1] > K[7]) {
	puts("-1");
	return 0;
    }

    int part = 0;

    while (N && T[N-1] > K[6]) { // need A+B+C
	part++;
	N--;
    }

    while (N && T[N-1] > K[5]) { // need B+C
	part++;
	D[0]++;
	N--;
    }
    for (int i=N-1; i>=0; i--) {
	if (D[0] && T[i] <= A) {
	    D[0]--;
	    T[i] = INF;
	}
    }
    N = remove(T, T+N, INF) - T;


    while (N && T[N-1] > K[3] && T[N-1] > C) { // need A+C
	part++;
	D[1]++;
	N--;
    }
    
    for (int i=N-1; i>=0; i--) {
	if (D[1] && T[i] <= B) {
	    D[1]--;
	    T[i] = INF;
	}
    }
    N = remove(T, T+N, INF) - T;

    const int MAX = unq.size() + 10;
    Fenwick<int> F(MAX);
    REP (i, N) F.add(T[i], 1);

    int ans = INF;
    for (int y=0; y<=N; y++) {
	if (F.sum(C+1, MAX) <= 0) {
	    int g = 0;
	    amax(g, F.sum(B+1, MAX)); // C
	    amax(g, F.sum(K[3]+1, MAX));
	    amax(g, (F.sum(A+1, MAX)+1)/2); // B and C
	    amax(g, (F.sum(MAX)+2)/3); // A, B, and C
	    amin(ans, g+part+y);
	}

	F.add(C, -1);
	F.add(K[3], -1);
    }
    
    printf("%d\n", ans);
    
    return 0;
}