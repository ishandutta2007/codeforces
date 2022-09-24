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
LL gcd(LL x, LL y) {
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

LL F(LL m, LL g) {
    LL b = m/g;
    LL ret = b*(b+1)/2*g;
    for (LL i=b*g; i<=m; i++) ret += i/g+1;
    return ret;
}

const int SIZE = 1000011;
LL M, A, B;
bool vis[SIZE];

void MAIN() {
    scanf("%lld%lld%lld", &M, &A, &B);

    LL ans = 0;
    vis[0] = true;
    int cnt = 1;
    stack<int> st;
    for (int i=0; i<SIZE && i<=M; i++) {
	if (i >= A && vis[i-A]) {
	    vis[i] = true;
	    cnt++;
	    st.push(i);
	    while (!st.empty()) {
		int p = st.top(); st.pop();
		if (p + A <= i && !vis[p+A]) {
		    vis[p+A] = true;
		    cnt++;
		    st.push(p+A);
		}
		if (0 <= p-B && !vis[p-B]){ 
		    vis[p-B] = true;
		    cnt++;
		    st.push(p-B);
		}
	    }
	}
	ans += cnt;
    }

    if (SIZE-1 < M) {
	int g = gcd(A, B);
	ans += F(M, g);
	ans -= F(SIZE-1, g);
    }
    printf("%lld\n", ans);
    //eprintf("%lld\n", F(M, gcd(A, B)));
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}