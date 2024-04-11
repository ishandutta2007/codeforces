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

int N, M;
LL L[200011], R[200011], A[200011];
pair<LL, int> B[200011];
struct Data {
    LL lo, hi, i;
};
struct ORD_LO {
    bool operator()(const Data &x, const Data &y) {
	return x.lo != y.lo ? x.lo < y.lo :
	    x.hi < y.hi;
    }
} ord_lo;
struct ORD_HI {
    bool operator()(const Data &x, const Data &y) {
	return x.hi != y.hi ? x.hi > y.hi:
	    x.lo < y.lo;
    }
} ord_hi;

Data D[200011];

int ans[200011];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%lld%lld", L+i, R+i);
    
    REP (i, M) {
	scanf("%lld", &B[i].first);
	B[i].second = i;
    }

    sort(B, B+M);

    REP (i, N-1) {
	D[i].lo = L[i+1] - R[i];
	D[i].hi = R[i+1] - L[i];
	D[i].i = i;
    }
    sort(D, D+N-1, ord_lo);

    // L[i+1]-R[i] <= a <= R[i+1]-L[i]
    priority_queue<Data, vector<Data>, ORD_HI> Q;
    for (int i=0, j=0; i<M; i++) {
	while (j < N-1 && D[j].lo <= B[i].first) {
	    Q.push(D[j]);
	    j++;
	}

	if (!Q.empty()) {
	    Data d = Q.top();
	    if (d.lo <= B[i].first && B[i].first <= d.hi) {
		Q.pop();
		ans[d.i] = B[i].second + 1;
	    }
	}
    }

    bool yes = true;
    REP (i, N-1) if (ans[i] == 0) yes = false;
    if (yes) {
	puts("Yes");
	REP (i, N-1) printf("%d%c", ans[i], i+1==N-1?'\n':' ');
    } else {
	puts("No");
    }
    return 0;
}