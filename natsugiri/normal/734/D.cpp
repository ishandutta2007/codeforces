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

int N;
LL X0, Y0;
LL X[500111], Y[500111];
char P[500111];

int main() {
    scanf("%d", &N);
    scanf("%lld %lld", &X0, &Y0);

    REP (i, N) {
	scanf("%s%lld%lld", P+i, X+i, Y+i);
    }

    bool yes = false;
    int k;

    k = -1;
    REP (i, N) {
	if (X0 == X[i] && Y0 < Y[i]) 
	    if (k == -1 || Y[i] < Y[k]) 
		k = i;
    }
    if (k != -1 && P[k] != 'B') yes = true;

    k = -1;
    REP (i, N) {
	if (X0 == X[i] && Y0 > Y[i]) 
	    if (k == -1 || Y[i] > Y[k]) 
		k = i;
    }
    if (k != -1 && P[k] != 'B') yes = true;

    k = -1;
    REP (i, N) {
	if (Y0 == Y[i] && X0 < X[i]) 
	    if (k == -1 || X[i] < X[k]) 
		k = i;
    }
    if (k != -1 && P[k] != 'B') yes = true;

    k = -1;
    REP (i, N) {
	if (Y0 == Y[i] && X0 > X[i]) 
	    if (k == -1 || X[i] > X[k]) 
		k = i;
    }
    if (k != -1 && P[k] != 'B') yes = true;

    ////////////
    k = -1;
    REP (i, N) {
	if (Y0 - X0 == Y[i] - X[i] && Y0 < Y[i]) 
	    if (k == -1 || Y[i] < Y[k]) 
		k = i;
    }
    if (k != -1 && P[k] != 'R') yes = true;

    k = -1;
    REP (i, N) {
	if (Y0 - X0 == Y[i] - X[i] && Y0 > Y[i]) 
	    if (k == -1 || Y[i] > Y[k]) 
		k = i;
    }
    if (k != -1 && P[k] != 'R') yes = true;

    k = -1;
    REP (i, N) {
	if (Y0 + X0 == Y[i] + X[i] && Y0 < Y[i]) 
	    if (k == -1 || Y[i] < Y[k]) 
		k = i;
    }
    if (k != -1 && P[k] != 'R') yes = true;

    k = -1;
    REP (i, N) {
	if (Y0 + X0 == Y[i] + X[i] && Y0 > Y[i]) 
	    if (k == -1 || Y[i] > Y[k]) 
		k = i;
    }
    if (k != -1 && P[k] != 'R') yes = true;

    puts(yes? "YES": "NO");
    return 0;
}