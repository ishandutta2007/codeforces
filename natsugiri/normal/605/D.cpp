#include<queue>
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

template<class T> struct RMQ {
    int n;
    vector<T> A; vector<int> I;
    RMQ(int n_=0): n(n_), A(n), I(2*n) {
	for (int i=0; i<n; i++) I[i+n] = i;
	for (int i=n; --i;) I[i] = I[2*i];
    }
    RMQ(const vector<T> &a): n(a.size()), A(a), I(2*n) {
	for (int i=0; i<n; i++) I[i+n] = i;
	for (int i=n; --i;) I[i] = (A[I[i*2+1]] < A[I[i*2]]? I[i*2+1]: I[i*2]);
    }
    void modify(int i, const T &v) {
	A[i] = v;
	for (i+=n; i>>=1;) I[i] = (A[I[i*2+1]] < A[I[i*2]]? I[i*2+1]: I[i*2]);
    }
    int min_i(int x, int y) {
	x += n; y += n;
	int p = -1;
	for (; x<y; x>>=1, y>>=1) {
	    if (y & 1) { --y; if (p < 0 || A[I[y]] < A[p]) p = I[y]; }
	    if (x & 1) { if (p < 0 || A[I[x]] < A[p]) p = I[x]; x++; }
	}
	return p;
    }
    T min_v(int x, int y) { return A[min_i(x, y)]; }
};


const int MAXN = 100111;

int N;
int A[MAXN], B[MAXN], C[MAXN], D[MAXN];

const int INF = 1<<30;
int from[MAXN];

vector<pair<int, int> > G[MAXN];

int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d%d%d%d", A+i, B+i, C+i, D+i);
    N += 1;
    

    VI unqA;
    VI cA = compress(VI(A, A+N), &unqA);

    for (int i=1; i<N; i++) G[cA[i]].push_back(make_pair(B[i], i));
    REP (i, N) sort(G[i].rbegin(), G[i].rend());

    RMQ<int> rmq(VI(N, INF));
    REP (i, N) if (G[i].size()) rmq.modify(i, G[i].back().first);

    memset(from, -1, sizeof from);
    from[0] = 0;

    queue<int> qu; 
    qu.push(0);
    
    while (!qu.empty()) {
	int v = qu.front(); qu.pop();
	int x = upper_bound(unqA.begin(), unqA.end(), C[v]) - unqA.begin();
	while (rmq.min_v(0, x) <= D[v]) {
	    int i = rmq.min_i(0, x);
	    int t = G[i].back().second; G[i].pop_back();

	    if (G[i].empty()) rmq.modify(i, INF);
	    else rmq.modify(i, G[i].back().first);
		
	    from[t] = v;
	    qu.push(t);
	}
    }

    if (from[N-1] == -1) puts("-1");
    else {
	VI v;
	int cur = N-1;
	while (cur) {
	    v.push_back(cur);
	    cur = from[cur];
	}
	reverse(v.begin(), v.end());
	printf("%lu\n", v.size());
	REP (i, v.size()) printf("%d%c", v[i], i==(int)v.size()-1?'\n':' ');
    }
    return 0;
}