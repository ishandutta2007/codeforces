/*
 * Author: RainAir
 * Time: 2019-07-21 20:32:31
 */
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
//#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 100+5;
const int ha = 998244353;
const int phi = ha-1;
const int g = 3;
int k,n,m;

inline int qpow(int a,int n,int ha){
    int res = 1;
    while(n){
        if(n & 1) res = 1ll*res*a%ha;
        a = 1ll*a*a%ha;
        n >>= 1;
    }
    return res;
}

inline int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x = 1,y = 0;
        return a;
    }
    int g = exgcd(b,a%b,x,y);
    int t = x;x = y;y = t-(a/b)*y;
    return g;
}

struct Matrix{
    int a[MAXN][MAXN];
    Matrix(){CLR(a,0);}

    inline void sete(){
        CLR(a,0);
        FOR(i,1,k+1) a[i][i] = 1;
    }

    Matrix operator * (const Matrix &t) const {
        Matrix res;
        FOR(k,1,::k){
            FOR(i,1,::k){
                FOR(j,1,::k){
                    res.a[i][j] += a[i][k]*t.a[k][j]%phi;
                    res.a[i][j] %= phi;
                }
            }
        }
        return res;
    }
}P;

Matrix qpow(Matrix a,int n){
    Matrix res;res.sete();
    while(n){
        if(n & 1) res = res*a;
        a = a*a;
        n >>= 1;
    }
    return res;
}

int b[MAXN],e;
// ans^e == m(mod p)
std::unordered_map<int,int> S;

inline int BSGS(int a,int b,int p){ // a^x == b(mod p)
    int q = std::sqrt(1.0*p)+1;b %= p;int t = b;
    FOR(i,0,q-1){
        S[t] = i;
        t = 1ll*t*a%p;
    }
    a %= p;
    if(!a){
        return b ? -1 : 1;
    }
    t = 1;int base = qpow(a,q,p);
    FOR(i,0,q){
        if(S.count(t)){
            int res = i*q-S[t];
            if(res >= 0) return res;
        }
        t = 1ll*t*base%p;
    }
    return -1;
}

signed main(){
    scanf("%lld",&k);
    FOR(i,1,k) scanf("%lld",b+i);
    scanf("%lld%lld",&n,&m);
    FOR(i,1,k) P.a[1][i] = b[i];
    FOR(i,2,k) P.a[i][i-1] = 1;
    P = qpow(P,n-k);e = P.a[1][1];
    int lgm = BSGS(g,m,ha);
    if(lgm == -1){
        puts("-1");return 0;
    }
    int x=0,y=0;int g = exgcd(e,phi,x,y);
    if(lgm%g){puts("-1");return 0;}
    x = x*(lgm/g)%phi;x = (x%phi+phi)%phi;
    printf("%lld\n",qpow(::g,x,ha));
    return 0;
}