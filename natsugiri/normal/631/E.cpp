#include<set>

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

const LL INF = 1LL<<60; 
struct CHT2 {  
    CHT2() {
	// 
	S.insert({L(INF,0), L(-INF,0)});
	C.insert(cp(L(INF,0),L(-INF,0)));
    }
    // for debug
//    void print() {
//	cout << "S : "; for (auto it : S) printf("(%LLd,%LLd)", it.a, it.b); puts("");
//	cout << "C : "; for (auto it : C) printf("(%LLd,%LLd)", it.n, it.d); puts("");
//    }
    // |ab| < LLONG_MAX/4 ???
    void add(LL a, LL b) {
	const L p(a,b);
	It pos = S.insert(p).first;
	if (check(*it_m1(pos), p, *it_p1(pos))) {
	    // (a,b)
	    S.erase(pos);
	    return;
	}
	C.erase(cp(*it_m1(pos), *it_p1(pos)));
	{
	    // 
	    It it = it_m1(pos);
	    while(it!=S.begin() && check(*it_m1(it), *it, p)) --it;
	    C_erase(it, it_m1(pos));
	    S.erase(++it,pos);
	    pos = S.find(p);
	}
	{
	    // 
	    It it = it_p1(pos);
	    while(it_p1(it)!=S.end() && check(p,*it, *it_p1(it))) ++it;
	    C_erase(++pos, it);
	    S.erase(pos, it);
	    pos = S.find(p);
	}
	C.insert(cp(*it_m1(pos), *pos));
	C.insert(cp(*pos, *it_p1(pos)));
    }
    LL query(LL x) {
	const L &p = (--C.lower_bound(CP(x,1,L(0,0))))->p;
	return p.a*x + p.b;
    }

private:

    template<class T> T it_p1(T a) { return ++a; }
    template<class T> T it_m1(T a) { return --a; }  
    struct L {
	LL a, b;
	L(LL a, LL b) : a(a),b(b) {}
	bool operator<(const L &rhs) const {
	    return a != rhs.a ? a > rhs.a : b < rhs.b;
	}
    };
    struct CP {
	LL n,d;
	L p;
	CP(LL _n, LL _d, const L &p) : n(_n),d(_d),p(p) {
	    if (d < 0) { n *= -1; d *= -1; }
	};
	bool operator<(const CP &rhs) const {
	    if (n == INF || rhs.n == -INF) return 0;
	    if (n == -INF || rhs.n == INF) return 1;      
	    return n * rhs.d < rhs.n * d;
	}
    };
    set<L> S;
    set<CP> C;

    typedef set<L>::iterator It;

    void C_erase(It a, It b) {
	for (It it=a; it!=b; ++it)
	    C.erase(cp(*it, *it_p1(it)));
    }
    CP cp(const L &p1, const L &p2) {
	if (p1.a == INF) return CP(-INF,1,p2);
	if (p2.a == -INF) return CP(INF,1,p2);
	return CP(p1.b-p2.b, p2.a-p1.a, p2);
    }
    bool check(const L &p1, const L &p2, const L &p3) {
	if (p1.a==p2.a && p1.b <= p2.b) return 1;
	if (p1.a == INF || p3.a == -INF) return 0;
	return (p2.a-p1.a)*(p3.b-p2.b) >= (p2.b-p1.b)*(p3.a-p2.a);
    }
};
int N, A[200111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    LL delta = 0;
    LL s = 0;
    { // go right
	CHT2 X;
	REP (i, N) {
	    s += A[i];
	    X.add(-A[i], -s + (LL)A[i] * i);
	    amax(delta, -X.query(i) - s);
	}
    }

    { // go left
	CHT2 X;
	for (int i=N; i--; ) {
	    s -= A[i];
	    X.add(-A[i], -s + (LL)A[i] * i);
	    amax(delta, -X.query(i) - s);
	}
    }

    LL ans = 0;
    REP (i, N) ans += (LL)(i+1) * A[i];
    printf("%lld\n", ans + delta);

    return 0;
}