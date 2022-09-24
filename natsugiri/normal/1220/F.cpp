#include<set>
#include<stack>
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

struct Data {
    int value;
    int height;
    int hh;
    Data() {}
    Data(int v, int h, int hh_) {
	value = v;
	height = h;
	hh = hh_;
    }
};

int N;
int A[400011];
void calc(int *L) {
    stack<Data> st;
    multiset<int> se;
    for (int i=1; i<N; i++) {
	int h = 0;
	while (!st.empty() && st.top().value > A[i]) {
	    auto p = st.top();
	    st.pop();
	    se.erase(se.find(p.hh));
	    h = max(p.height, h+1);
	}

    	int hh = st.size() + 1 + h;
	st.emplace(A[i], h+1, hh);
	se.insert(hh);
	L[i] = *se.rbegin();
    }
}

int L[200011];
int R[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;


    REP (i, N) A[i+N] = A[i];

    int add = 0;
    REP (i, N) if (A[i] == 0) {
	add = i;
	REP (j, N) A[j] = A[j+i];
	break;
    }

    calc(L);
    reverse(A+1, A+N);
    calc(R);
    
    //rprintf("%d", L, L+N);
    //rprintf("%d", R, R+N);

    int height = N+11;
    int shift = add;
    REP (i, N) {
	int h = max(L[i], R[N-1-i]) + 1;
	//eprintf("? %d %d\n", h, (add+N-i)%N);
	if (height > h) {
	    height = h;
	    shift = add + i + 1;
	}
    }
    shift %= N;
    printf("%d %d\n", height, shift);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}