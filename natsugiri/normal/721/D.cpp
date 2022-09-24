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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, K, X;

typedef pair<LL, int> Pair;
priority_queue<Pair, vector<Pair>, greater<Pair> > P, Z;
priority_queue<Pair> M;

LL ans[200111];

int main() {
    scanf("%d%d%d", &N, &K, &X);
    REP (i, N) {
	int x;
	scanf("%d", &x);
	if (x > 0) P.push(Pair(x, i));
	else if (x < 0) M.push(Pair(x, i));
	else Z.push(Pair(x, i));
    }

    while (K > 0 && M.size() % 2 == 0) {
	Pair o;
	K--;
	if (Z.size()) {
	    o = Z.top(); Z.pop();
	    o.first -= X;
	} else if (P.size() && M.size()) {
	    if (P.top().first < abs(M.top().first)) {
		o = P.top(); P.pop();
		o.first -= X;
	    } else {
		o = M.top(); M.pop();
		o.first += X;
	    }
	} else if (P.size()) {
	    o = P.top(); P.pop();
	    o.first -= X;
	} else {
	    o = M.top(); M.pop();
	    o.first += X;
	}

	if (o.first < 0) {
	    M.push(o);
	} else if (o.first == 0) {
	    Z.push(o);
	} else {
	    P.push(o);
	}
    }

    while (K > 0) {
	    K--;
	if (Z.size()) {
	    Pair o = Z.top(); Z.pop();
	    o.first += X;
	    P.push(o);
	} else if (P.size() && M.size()) {
	    if (P.top().first < abs(M.top().first)) {
		Pair o = P.top(); P.pop();
		o.first += X;
		P.push(o);
	    } else {
		Pair o = M.top(); M.pop();
		o.first -= X;
		M.push(o);
	    } 
	} else if (P.size()) {
	    Pair o = P.top(); P.pop();
	    o.first += X;
	    P.push(o);
	} else {
	    Pair o = M.top(); M.pop();
	    o.first -= X;
	    M.push(o);
	}
    }


    while (P.size()) {
	Pair o = P.top(); P.pop();
	ans[o.second] = o.first;
    }
    while (M.size()) {
	Pair o = M.top(); M.pop();
	ans[o.second] = o.first;
    }
    while (Z.size()) {
	Pair o = Z.top(); Z.pop();
	ans[o.second] = o.first;
    }


    REP (i, N) printf("%lld%c", ans[i], i==N-1? '\n': ' ');
    return 0;
}