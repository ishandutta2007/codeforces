#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100 + 5;
const int ha = 1e9 + 7;
int n;LL k;
LL a[MAXN];

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

struct Matrix{
    int a[MAXN][MAXN];
    Matrix(){CLR(a,0);}

    inline Matrix operator * (Matrix t){
        Matrix res;
        FOR(i,1,n){
            FOR(j,1,n){
                FOR(k,1,n){
                    add(res.a[i][j],1ll*a[i][k]*t.a[k][j]%ha);
                }
            }
        }
        return res;
    }
}A;

inline Matrix qpow(Matrix a,LL n){
    Matrix res;FOR(i,1,::n) res.a[i][i] = 1;
    while(n){
        if(n&1) res = res*a;
        a = a*a;
        n >>= 1;
    }
    return res;
}

int main(){
    scanf("%d%lld",&n,&k);
    FOR(i,1,n) scanf("%lld",a+i);
    FOR(i,1,n) FOR(j,1,n) if(__builtin_popcountll(a[i]^a[j])%3 == 0) A.a[j][i] = 1;
    A = qpow(A,k-1);
    int ans = 0;
    FOR(i,1,n) FOR(j,1,n) add(ans,A.a[i][j]);
    printf("%d\n",ans);
    return 0;
}