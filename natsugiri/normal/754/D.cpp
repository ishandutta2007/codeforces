#include<queue>
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

int N, K;
struct Data {
    int l, r, id;
    Data() {}
    Data(int l_, int r_, int i_) : l(l_), r(r_), id(i_) {}
} D[300111];
struct CmpL {
    bool operator()(const Data &x, const Data &y) const {
	return x.l < y.l;
    }
} cmpL;
struct CmpPQ {
    bool operator()(const Data &x, const Data &y) const {
	return x.r > y.r;
    }
};

VI arr;
LL ans;
void solve(LL guess) {
//    multiset<Data, CmpR> se;
    priority_queue<Data, vector<Data>, CmpPQ> Q;

    for (int i=0; i<N; ) {
	int j = i;
	while (j < N && D[j].l == D[i].l) {
	    Q.push(D[j]);
	    while ((int)Q.size() > K) Q.pop();
	    j++;
	}


	if ((int)Q.size() == K) {
	    LL tmp = (LL)Q.top().r - D[i].l + 1;

	    amax(ans, tmp);
	    if (tmp >= 0 && tmp == guess) {
		while (!Q.empty()) {
		    arr.push_back(Q.top().id + 1);
		    Q.pop();
		}
		return;
	    }
	}

	i = j;
    }
}

int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) {
	int l, r;
	scanf("%d%d", &l, &r);
	D[i] = Data(l, r, i);
    }
    sort(D, D+N, cmpL);
    solve(-1e9);
    solve(ans);
    sort(arr.begin(), arr.end());
    if ((int)arr.size() != K) {
	arr.resize(K);
	REP (i, K) arr[i] = i + 1;
    }

    printf("%lld\n", ans);
    rprintf("%d", arr.begin(), arr.end());
    return 0;
}