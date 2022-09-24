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

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

double mem[101][101][101];
double prob(int R, int S, int P) {
    REP (r, R+1) REP (s, S+1) REP (p, P+1) {
	double &x = mem[r][s][p];
	if (r == 0) {
	    x = 0;
	} else if (p == 0) {
	    x = 1;
	} else if (s == 0) {
	    x = 0;
	} else {
	    double B = r*s + s*p + p*r;
	    x = 0;
	    x += mem[r][s-1][p] * r * s / B;
	    x += mem[r-1][s][p] * r * p / B;
	    x += mem[r][s][p-1] * s * p / B;
	}
    }
    
    return mem[R][S][P];
}

int R, S, P;
int main() {
    scanf("%d%d%d", &R, &S, &P);
    printf("%.9f %.9f %.9f\n",
	   prob(R, S, P),
	   prob(S, P, R),
	   prob(P, R, S));
    return 0;
}