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

const int MAXN = 500011;
const int MAXH = 33;

const int TEST = 0;

int N, Q;
double P[MAXN][MAXH];
int par[MAXN];
int pp[MAXH + 10], pp_i;
int X;

char op[9];


void type1() {
    par[N] = X;
    REP (h, MAXH) P[N][h] = 1;
    int k = N;

    N++;

    pp_i = 0;
    while (true) {
	pp[pp_i++] = k;
	if (k == 0 || pp_i >= MAXH) break;
	k = par[k];
    }

    for (int i=pp_i-1; i>=2; i--) {
	int c = pp[i-1], x = pp[i];

	P[x][0] /= 0.5;
	for (int h=1; h<MAXH; h++) P[x][h] /= 0.5 * (1 + P[c][h-1]);
    }
    for (int i=0; i<pp_i-1; i++) {
	int c = pp[i], x = pp[i+1];

	P[x][0] *= 0.5;
	for (int h=1; h<MAXH; h++) P[x][h] *= 0.5 * (1 + P[c][h-1]);
    }
}
void type2() {
    double ans = 0;
    for (int h=1; h<MAXH; h++) {
	ans += h * (P[X][h] - P[X][h-1]);
    }
    ans += MAXH * (1.0 - P[X][MAXH-1]);

    printf("%.9f\n", ans);
}

int main() {
    scanf("%d", &Q);

    if (TEST) Q = 500000;

    REP (h, MAXH) P[0][h] = 1;
    N++;

    REP ($, Q) {
	if (TEST) {
	    op[0] = '2';
	    X = 1;
	    if ($ + 1 == Q) {
		op[0] = 2;
		X = 1;
	    }
	} else {
	    scanf("%s%d", op, &X);
	}
	X--;

	if (op[0] == '1') type1();
	else type2();
    }


    return 0;
}