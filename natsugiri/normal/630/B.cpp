#include<cmath>
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

long double R =  1.000000011L;
long double X = 1.011060722383550382782399454922040L;

long double pow(long double x, LL y) {
    long double r = 1;
    for (;y ;y>>=1) {
	if (y&1) r = r * x;
	x = x * x;
    }
    return r;
}

LL N, T;
int main() {
    scanf("%lld%lld", &N, &T);
    // long double ans = N * pow(X, T / 1000000) * pow(R, T % 1000000);
    long double ans = N;
    REP (i, T/1000000) ans *= X;
    ans *= pow(R, T % 1000000);
    printf("%.30f\n", (double)ans);
    
    return 0;
}