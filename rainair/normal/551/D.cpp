/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-18 16:54:58
 */
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
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 1e6+5;
int n,k,l,ha;
int f[MAXN][2];

struct Matrix{
    int a[2][2];
    Matrix(){CLR(a,0);}

    Matrix operator * (const Matrix &t) const {
        Matrix res;
        FOR(i,0,1){
            FOR(j,0,1){
                FOR(k,0,1){
                    (res.a[i][j] += 1ll*a[i][k]*t.a[k][j]%ha) %= ha;
                }
            }
        }
        return res;
    }
};

inline Matrix qpow(Matrix a,int n){
    Matrix res;res.a[0][0] = res.a[1][1] = 1;
    while(n){
        if(n & 1) res = res*a;
        a = a*a;
        n >>= 1;
    }
    return res;
}

inline int qpow(int a,int n=ha-2){
    int res = 1;
    while(n){
        if(n & 1) res = 1ll*res*a%ha;
        a = 1ll*a*a%ha;
        n >>= 1;
    }
    return res;
}

signed main(){
    scanf("%lld%lld%lld%lld",&n,&k,&l,&ha);
    if(l <= 63 && (1ull<<l) <= k){
        puts("0");
        return 0;
    }
//    f[1][0] = f[1][1] = 1;
    Matrix res;res.a[1][0] = res.a[0][0] = res.a[0][1] = 1;
    res = qpow(res,n+1);
 //   return 0;
//    FOR(i,2,n){
//        f[i][0] = (f[i-1][0]+f[i-1][1]) % ha;
//        f[i][1] = f[i-1][0];
//    }
    int ans = 1;
    int gx1 = res.a[0][0];
//    int gx1 = (f[n][0]+f[n][1])%ha;
    int gx2 = (qpow(2,n)-gx1+ha)%ha;
    FOR(i,0,l-1){
        if((1ll<<i)&k) (ans *= gx2) %= ha;
        else (ans *= gx1) %= ha;
    }
    printf("%lld\n",ans%ha);
    return 0;
}