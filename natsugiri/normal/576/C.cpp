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

struct Data {
    int x, y, i;
    
};
struct XORD_ {
    bool operator()(const Data &x, const Data &y) const {
	return x.x < y.x;
    }
} XORD;
struct YORD_ {
    bool operator()(const Data &x, const Data &y) const {
	return x.y < y.y;
    }
} YORD;

int N;
Data P[1000011];
VI ans;
void rec(int l, int r, int t) {
    if (l == r) return;
    if (l+1 == r) {
	return;
    }

    int m= (r+l)/2;
    if (t == 0) nth_element(P+l, P+m, P+r, XORD);
    else nth_element(P+l, P+m, P+r, YORD);

    rec(l, m, 1-t);
    rec(m, r, 1-t);
}

const int TEST = 0;

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", &P[i].x, &P[i].y), P[i].i = i;

    if (TEST) {
	srand(1);
	N = 1000000;
	REP (i, N) P[i] = (Data){N-i, i, i};
    }
    
    rec(0, N, 0);
    
    if (!TEST) REP (i, N) printf("%d%c", P[i].i+1, i+1==N? '\n': ' ');

    if (TEST) {
	LL C = 0;
	REP (i, N-1) {
	    int v = i, w = i + 1;
	    C += abs(P[v].x - P[w].x) + abs(P[v].y - P[w].y);
	}
	eprintf("%lld\n", C);
    }
    
    return 0;
}