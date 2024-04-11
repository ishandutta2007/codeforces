#include<set>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

const int MAXN = 100011;

int N;
int A[MAXN];
pair<int, int> B[MAXN];
bool use[MAXN];

struct Data {
    int l, r;
    Data(){}
    Data(int l_, int r_) {
	l = l_;
	r = r_;
    }

    int length() const {
	return r - l;
    }

    bool operator<(const Data &y) const {
	return r-l != y.r-y.l ? r-l < y.r-y.l :
	    l != y.l ? l < y.l : 
	    r < y.r;
    }
    bool operator==(const Data &y) const {
	return l == y.l && r == y.r;
    }
};

Data U[MAXN];
void init() {
    REP (i, N) U[i].l = U[i].r = i;
}
int rootL(int x) {
    if (U[x].l == x) return x;
    else return U[x].l = rootL(U[x].l);
}
int rootR(int x) {
    if (U[x].r == x) return x;
    else return U[x].r = rootR(U[x].r);
}
void link(int x, int y) {
    if (x > y) swap(x, y);
    U[x].r = y;
    U[y].l = x;
}

Data get_data(int x) {
    return Data(rootL(x), rootR(x)+1);
}

set<Data> se;
const int INF = 1<<30;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) B[i] = make_pair(A[i], i);
    sort(B, B+N);
    init();

    int segs = 0;
    int dist = INF;

    REP (i_, N) {
	int val = B[i_].first;
	int pos = B[i_].second;
	Data d(pos, pos+1);

	if (pos > 0 && use[pos-1]) {
	    Data z = get_data(pos-1);
	    se.erase(z);
	    d = Data(z.l, d.r);
	    link(pos-1, pos);
	}
	if (pos+1 < N && use[pos+1]) {
	    Data z = get_data(pos+1);
	    se.erase(z);
	    d = Data(d.l, z.r);
	    link(pos, pos+1);
	}

	se.insert(d);
	use[pos] = true;

	if (se.begin()->length() == se.rbegin()->length()) {
	    if (segs < (int)se.size()) {
		segs = se.size();
		dist = INF;
	    }
	    if (segs == (int)se.size()) {
		amin(dist, val+1);
	    }
	}
    }

    printf("%d\n", dist);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}