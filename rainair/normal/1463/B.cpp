#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 50+5;
LL a[MAXN];
int n;

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%lld",a+i);
    LL sm1 = 0,sm2 = 0;
    FOR(i,1,n){
        if(i&1) sm1 += a[i];
        else sm2 += a[i];
    }
    if(sm1 < sm2){
        FOR(i,1,n){
            if(i&1) a[i] = 1;
        }
    }
    else{
        FOR(i,1,n){
            if(!(i&1)) a[i] = 1;
        }
    }
    FOR(i,1,n) printf("%lld ",a[i]);puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}