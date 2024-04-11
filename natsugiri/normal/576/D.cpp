#include<bitset>
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

const int SIZE = 151;
typedef bitset<SIZE> Arr;

struct Mat {
    Arr D[SIZE];
    Mat() { }
    Arr &operator[](int i) { return D[i]; }
    const Arr &operator[](int i) const { return D[i]; }
    Mat& operator|=(const Mat &y) {
	for (int i=0; i<SIZE; i++) D[i] |= y[i];
	return *this;
    }
    Mat& operator*=(const Mat &);
    Mat pow(unsigned long long y) const {
	Mat x(*this), r = I();
	for (; y; y>>=1) {
	    if (y&1) r *= x;
	    x *= x;
	}
	return r;
    }
    static Mat I() {
	Mat x = Mat();
	for (int i=0; i<SIZE; i++) x[i][i] = true;
	return x;
    }
};
Mat operator|(Mat x, const Mat &y) { return x |= y; }
Mat operator*(const Mat &x, const Mat &y) {
    Mat r = Mat();
    for (int i=0; i<SIZE; i++)
	for (int k=0; k<SIZE; k++)
	    if (x[i][k]) r[i] |= y[k];
    return r;
}
Arr operator*(const Mat &x, const Arr &y) {
    Arr r;
    REP (i, SIZE) r[i] = (x[i] & y).any();
    return r;
}
Mat& Mat::operator*=(const Mat &y) { return *this = *this * y; }

struct Edge {
    int src, dst;
    int cst;
    bool operator<(const Edge &y) const {
	return cst < y.cst;
    };
} E[SIZE];

int N, M;
int FW[SIZE][SIZE];
LL INF;
LL cur;
Arr C;
Mat P;

LL go() {
    LL ret = INF;
    REP (i, N) if (C[i] && FW[i][N-1] <= N) amin(ret, cur + FW[i][N-1]);
    return ret;
}

int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) scanf("%d%d%d", &E[i].src, &E[i].dst, &E[i].cst), E[i].src--, E[i].dst--;
    sort(E, E+M);
    
    memset(&INF, 0x3f, sizeof INF);
    memset(FW, 0x3f, sizeof FW);
    REP (i, N) FW[i][i] = 0;

    C[0] = true;
    LL ans = go();
    
    REP (i, M) {
	int a = E[i].src, b = E[i].dst, d = E[i].cst;

	if (d > cur) {
	    C = P.pow(d - cur) * C;
	    cur = d;
	}
	P[b][a] = true;
	FW[a][b] = 1;
	REP (i, N) REP (j, N) amin(FW[i][j], FW[i][a] + FW[a][j]);
	REP (i, N) REP (j, N) amin(FW[i][j], FW[i][b] + FW[b][j]);
	amin(ans, go());
    }

    if (ans == INF) {
	puts("Impossible");
    } else {
	printf("%lld\n", ans);
    }

    return 0;
}