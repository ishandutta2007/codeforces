#include<complex>
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

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

LL powMod(LL x, LL y, LL m){
    LL r = 1;
    for (; y; y>>=1) {
        if (y&1) r = r * x % m;
        x = x * x % m;
    }
    return r;
}

// MOD == 15*(1<<27)+1 (prime); ROOT has order (1<<27)
// const LL MOD = 2013265921LL, ROOT = 440564289, LEN = 27;
// MOD == 7*17*(1<<23)+1 (prime); ROOT has order (1<<23)
const LL MOD = 998244353, ROOT = 31, LEN = 23;

void ntt(vector<int> &a, bool inv=false){
    static vector<LL> e, er;
    int n = a.size(); // n == 1<<k (k < 27)
    if(n != (int)e.size()) {
        e.resize(n); er.resize(n);
        e[0] = 1; e[1] = powMod(ROOT, (1<<LEN)/n, MOD);
        er[0] = 1; er[1] = powMod(e[1], MOD-2, MOD);
        for (int i=2; i<n; i++) e[i] = e[i-1] * e[1] % MOD;
        for (int i=2; i<n; i++) er[i] = er[i-1] * er[1] % MOD;
    }
    if (inv) swap(e, er);
    for (int m=n, th=1; m>=2; m>>=1, th*=2) {
        int mh = m>>1;
        for (int i=0; i<mh; i++) {
            for (int j=i; j<n; j+=m) {
                int k = j + mh;
                LL x = (LL)a[j] + a[k], y = a[j] - a[k];
                a[j] = (x>=MOD?x-MOD:x);
                a[k] = e[i*th] * (y<0?y+MOD:y) % MOD;
            }
        }
    }
    for (int i=0, j=1; j<n-1; j++) {
        for (int k=n/2; k>(i^=k); k/=2) ;
        if (j<i) swap(a[i], a[j]);
    }
    if(inv) {
        swap(e, er);
        LL d = powMod(n, MOD-2, MOD);
        for (int i=0; i<n; i++) a[i] = a[i] * d % MOD;
    }
}
void mulPolynomial(VI &p, VI &q, VI &r) {
    ntt(p); ntt(q);
    for (int i=0; i<(int)p.size(); i++) r[i]=(LL)p[i]*q[i]%MOD;
    ntt(r, true);
};

int N, M, K;
char S[200111], T[200111];
int X[200111], Y[200111];;

void task(char C) {
    memset(X, 0, sizeof X);

    REP (i, N) if (S[i] == C) {
        X[max(i-K, 0)]++;
        X[min(N+10, i+K+1)]--;
    }
    REP (i, N) X[i+1] += X[i];
    VI A(1<<18), B(1<<18), Z(1<<18);
    REP (i, N) if (X[i]) A[i] = 1;
    double cnt = 0;
    REP (i, M) if (T[M-1-i] == C) { B[i] = 1; cnt+=1; }
    mulPolynomial(A, B, Z);
    REP (i, N-M+1) if (Z[i+M-1] >= cnt) Y[i]++;
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    scanf("%s%s", S, T);

    for (int i=0; i<4; i++) task("ATGC"[i]);
    int ans = 0;
    REP (i, N-M+1) if (Y[i] == 4) ans++;

    printf("%d\n", ans);

    return 0;
}