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
const LL MOD = 1e9+7;
const int SIZE = 20;
struct Arr {
    unsigned D[SIZE];
    Arr() { memset(D, 0, sizeof D); }
    unsigned &operator[](int i) { return D[i]; }
    const unsigned &operator[](int i) const { return D[i]; }
    Arr& operator+=(const Arr &y) {
	for (int i=0; i<SIZE; i++)
	    if ((D[i] += y[i]) >= MOD) D[i] -= MOD;
	return *this;
    }
    Arr& operator-=(const Arr &y) {
	for (int i=0; i<SIZE; i++)
	    if ((D[i] += MOD-y[i]) >= MOD) D[i] -= MOD;
	return *this;
    }
    Arr operator+(const Arr &y) const { return Arr(*this) += y; }
    Arr operator-(const Arr &y) const { return Arr(*this) -= y; }
};

struct Mat {
    unsigned D[SIZE][SIZE];
    Mat() { memset(D, 0, sizeof D); }
    unsigned (&operator[](int i))[SIZE] { return D[i]; }
    const unsigned (&operator[](int i) const)[SIZE] { return D[i]; }
    static unsigned long long z[SIZE];
    Mat& operator+=(const Mat &y) {
	for (int i=0; i<SIZE; i++)
	    for (int j=0; j<SIZE; j++)
		if ((D[i][j] += y[i][j]) >= MOD) D[i][j] -= MOD;
	return *this;
    }
    Mat& operator-=(const Mat &y) {
    	for (int i=0; i<SIZE; i++)
	    for (int j=0; j<SIZE; j++)
		if ((D[i][j] += MOD-y[i][j]) >= MOD) D[i][j] -= MOD;
	return *this;
    }
    Mat& operator*=(const Mat &y) { return *this = *this * y; }
    Mat operator+(const Mat &y) const { return Mat(*this) += y; }
    Mat operator-(const Mat &y) const { return Mat(*this) -= y; }
    Mat operator*(const Mat &y) const {
	Mat r = Mat();
	memset(z, 0, sizeof z);
	for (int i=0; i<SIZE; i++) {
	    for (int k=0; k<SIZE; k++) {
		for (int j=0; j<SIZE; j++)
		    z[j] += (unsigned long long)D[i][k] * y[k][j];
		if ((k&7)==7)
		    for (int j=0; j<SIZE; j++)
			z[j] %= MOD;
	    }
	    for (int j=0; j<SIZE; j++) {
		r[i][j] = z[j] % MOD;
		z[j] = 0;
	    }
	}
	return r;
    }
    Arr operator*(const Arr &y) const {
	Arr r = Arr();
	memset(z, 0, sizeof z);
	for (int i=0; i<SIZE; i++) {
	    for (int j=0; j<SIZE; j++) {
		z[i] += (unsigned long long)D[i][j] * y[j];
		if (z[i] & (1LL<<63)) z[i] %= MOD;
	    }
	    r[i] = z[i] % MOD;
	    z[i] = 0;
	}
	return r;
    }
    Mat pow(unsigned long long y) const {
	Mat x(*this), r = I();
	for (; y; y>>=1) {
	    if (y&1) r *= x;
	    x *= x;
	}
	return r;
    }
    Arr powmul(unsigned long long y, Arr z) const {
	Mat x(*this);
	for (; y; y>>=1) {
	    if (y&1) z = x * z;
	    x *= x;
	}
	return z;
    }
    static Mat I() {
	Mat x = Mat();
	for (int i=0; i<SIZE; i++) x[i][i] = 1;
	return x;
    }
};
unsigned long long Mat::z[SIZE];


const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int N, M, Q;
char F[32][32];
Mat X;
inline bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

void getMat() {
    REP (i, SIZE) REP (j, SIZE) X[i][j] = 0;

    REP (i, N) REP (j, M) if (!F[i][j]) {
	X[i*M+j][i*M+j] += 1;
	REP (d, 4) {
	    int x = j + dx[d], y = i + dy[d];
	    if (in(y, x) && !F[y][x]) {
		X[y*M+x][i*M+j] += 1;
	    }
	}
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &Q);

    Arr A;
    REP (i, N*M) A[i] = 0;
    A[0] = 1;
    int tm = 1;

    REP ($, Q) {
	char op[7];
	int x, y, t;
	scanf("%s%d%d%d", op, &y, &x, &t);
	x--; y--;

	getMat();
	A = X.powmul(t-tm, A);
	tm = t;
	if (op[0] == '1') {
	    printf("%d\n", (int)A[y*M+x]);
	} else if (op[0] == '2') {
	    F[y][x] = true;
	    A[y*M+x] = 0;
	} else {
	    F[y][x] = false;
	}
    }
    return 0;
}