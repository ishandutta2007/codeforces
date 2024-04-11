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

int N;
char buf[100011];

void read(int a[]) {
    scanf("%s", buf);
    REP (i, N) a[i] = buf[i] - '0';

}
int A[100011];
int B[100011];
LL C[100011];
bool in[100011];

bool valid(int i) {
    if (C[i] == 0) return false;
    int s = (C[i]<0? -1: 1);
    int k = (i == 0? 1: 0);
    return k <= A[i] + s && A[i] + s <= 9 &&
	0 <= A[i+1] + s && A[i+1] + s <= 9;
}

void MAIN() {
#ifdef MYTEST 
    srand(19);
    N = 100000;
    REP (i, N) A[i] = B[i] = rand() % 10;
    A[0] = B[0] = 4;

    REP (t, N*100) {
	int i = rand() % (N-1);
	int s = rand() % 2;
	if (s == 0 && B[i] > 1 && B[i+1] >= 1) {
	    B[i]--;
	    B[i+1]--;
	}
	if (s == 1 && B[i] < 9 && B[i+1] < 9) {
	    B[i]++;
	    B[i+1]++;
	}
    }

#else
    scanf("%d", &N);
    read(A);
    read(B);
#endif

    LL carry = 0;
    REP (i, N) {
	C[i] = carry = B[i] - A[i] - carry;
    }

    if (carry != 0) {
	puts("-1");
	return;
    }

    LL sum = 0;
    REP (i, N) sum += abs(C[i]);
    printf("%lld\n", sum);

    stack<int> st;
    REP (i, N-1) {
	if (valid(i)) {
	    st.push(i);
	    in[i] = true;
	}
    }

    int cnt = 0;
    while (!st.empty()) {
	int i = st.top(); st.pop();
	in[i] = false;

	if (valid(i)) {
	    int s = (C[i] < 0? -1: 1);
	    printf("%d %d\n", i+1, s);
	    cnt++;
	    if (cnt == 100000) {
		return;
	    }

	    A[i] += s;
	    A[i+1] += s;
	    C[i] -= s;

	    for (int k=i-1; k<=i+1; k++) {
		if (0<=k && k+1 < N && !in[k] && valid(k)) {
		    st.push(k);
		    in[k] = true;
		}
	    }
	}
    }

    REP (i, N) assert(C[i] == 0);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}