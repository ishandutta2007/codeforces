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

const int ha = 1e9 + 7;

struct Node{
    int a[2][2];
    Node(){CLR(a,0);}

    inline Node operator * (const Node &t) const {
        Node res;
        FOR(i,0,1) FOR(j,0,1) FOR(k,0,1) (res.a[i][j] += 1ll*a[i][k]*t.a[k][j]%ha) %= ha;
        return res;
    }
};

inline Node qpow(Node a,LL n){
    Node res;res.a[0][0] = res.a[1][1] = 1;
    while(n){
        if(n&1) res = res*a;
        a = a*a;
        n >>= 1;
    }
    return res;
}

int main(){
    LL a,b,n,x;scanf("%lld%lld%lld%lld",&a,&b,&n,&x);
    Node A;A.a[0][0] = a;A.a[0][1] = b;A.a[1][1] = 1;
    A = qpow(A,n);
    int ans = (1ll*x*A.a[0][0]%ha+A.a[0][1])%ha;
    printf("%d\n",ans);
    return 0;
}