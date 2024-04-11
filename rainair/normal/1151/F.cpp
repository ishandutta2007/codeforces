#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
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
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100+5;
const int ha = 1e9 + 7;

inline int qpow(int a,int n){
    int res = 1;
    while(n){
        if(n & 1) res = 1ll*res*a%ha;
        a = 1ll*a*a%ha;
        n >>= 1;
    }
    return res;
}

struct Matrix{
    static const int SIZE = MAXN + 5;
    int a[SIZE][SIZE];
    Matrix(){CLR(a,0);}

    friend Matrix operator * (const Matrix &a,const Matrix &b){
        Matrix res;
        FOR(i,0,MAXN){
            FOR(j,0,MAXN){
                FOR(k,0,MAXN){
                    (res.a[i][j] += 1ll*a.a[i][k]*b.a[k][j]%ha) %= ha;
                }
            }
        }
        return res;
    }

    Matrix operator ^ (int n) const {
        Matrix res;FOR(i,0,MAXN) res.a[i][i] = 1;
        Matrix now = (*this);
        while(n){
            if(n & 1) res = res*now;
            now = now*now;
            n >>= 1;
        }
        return res;
    }
}A,B;

int n,k,a[MAXN];

int main(){
    scanf("%d%d",&n,&k);
    int c = 0,t = 0;
    FOR(i,1,n) scanf("%d",a+i),c += (a[i] == 0);
    FOR(i,1,c) t += (a[i] == 0);
    A.a[0][t] = 1;
    FOR(i,0,c){
        if(i) B.a[i-1][i] = 1ll*(c-(i-1))*(c-(i-1))%ha;
        (B.a[i][i] += (1ll*i*(c-i)%ha+1ll*(c-i)*(n-c-(c-i))%ha)%ha) %= ha;
        (B.a[i][i] += 1ll*c*(c-1)/2%ha) %= ha;
        (B.a[i][i] += 1ll*(n-c)*(n-c-1)/2%ha) %= ha;
        if(i != c) (B.a[i+1][i] += 1ll*(n-c-(c-(i+1)))*(i+1)%ha) %= ha;
    }
    B = B^k;
    A = A*B;
    int ans = A.a[0][c];t = 0;
    FOR(i,0,c) (t += A.a[0][i])%=ha;
    t = qpow(t,ha-2);ans = 1ll*ans*t%ha;
    printf("%d\n",ans);
    return 0;
}