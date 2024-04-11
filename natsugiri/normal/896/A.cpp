#include<cassert>
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

const string O = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string L = "What are you doing while sending \"";
const string C = "\"? Are you busy? Will you send \"";
const string R = "\"?";

const int Os = O.size();
const int Ls = L.size();
const int Cs = C.size();
const int Rs = R.size();


const LL INF = 1LL<<60;
LL len[100111];

char calc(int n, LL k) {
    if (k >= len[n]) return '.';
    while (n>=1) {
	if (k < Ls) return L[k];
	k -= Ls;
	if (k < len[n-1]) { n--; continue; }
	k -= len[n-1];
	if (k < Cs) return C[k];
	k -= Cs;
	if (k < len[n-1]) { n--; continue; }
	k -= len[n-1];
	assert(k < Rs);
	return R[k];
    }
    assert(k < Os);
    return O[k];
}

int Q, N;
LL K;
void MAIN() {
//    cerr << L << O << C << O << R << endl;
    scanf("%d", &Q);
    len[0] = O.size();
    for (int i=1; i<100111; i++) {
	len[i] = Ls + Cs + Rs + len[i-1] * 2;
	amin(len[i], INF);
    }

    REP ($, Q) {
	scanf("%d%lld", &N, &K);
	K--;
	putchar(calc(N, K));
    }
    puts("");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}