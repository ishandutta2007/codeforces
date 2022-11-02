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

const int MAXN = 5000+5;
int a[MAXN],n;
int b[MAXN],c[MAXN];

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),b[i] = a[i],c[i] = 0;LL ans = 0;
    FOR(i,1,n){
        ans += a[i]-1;
        if(i != n){
            if(c[i] < a[i+1]) a[i+1] -= c[i];
            else c[i+1] += c[i]-a[i+1]+1,a[i+1] = 1;
        }
        FOR(j,i+2,std::min(n,i+b[i])){
            if(a[j] == 1) ++c[j];
            else --a[j];
        }
    }
    printf("%lld\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}