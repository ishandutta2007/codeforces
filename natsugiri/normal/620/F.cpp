#include<cassert>
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

int F_(int x) {
    switch (x & 3) {
    case 0: return x;
    case 1: return 1;
    case 2: return x^1;
    case 3: return 0;
    default: assert(false);
    }
}
int F(int x, int y) {
    return F_(x-1) ^ F_(y);
}

struct Query {
    int l, r, i;
    bool operator<(const Query &y) const {
	return r < y.r;
    }
};

int N, M;
int A[50011];
Query P[5011];


int R[50011], L[50011];
int ma[50011];
int ans[5011];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);
    REP (i, M) {
	scanf("%d%d", &P[i].l, &P[i].r);
	P[i].l--;
	P[i].r--;
	P[i].i = i;
    }
    REP (i, N) {
	R[i] = F_(A[i]);
	L[i] = F_(A[i]-1);
    }
    
    sort(P, P+M);

//    REP (i, 10) eprintf("%d %d\n", i, F_(i));
    int k = 0;
    REP (i, N) {
	REP (j, i+1) {
	    // if (A[j] <= A[i]) amax(ma[j], F(A[j], A[i]));
	    // if (A[i] < A[j]) amax(ma[j], F(A[i], A[j]));
	    amax(ma[j], (A[j] <= A[i]) ? L[j]^R[i]: L[i]^R[j]);
	}
	while (k < M && P[k].r <= i) {
	    for (int j=P[k].l; j <= P[k].r; j++) {
		amax(ans[P[k].i], ma[j]);
	    }
	    k++;
	}
    }//

    REP (i, M) printf("%d\n", ans[i]);
    return 0;
}