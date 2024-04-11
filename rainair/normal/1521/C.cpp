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

const int MAXN = 1e5 + 5;
int a[MAXN];

inline void Solve(){
    int n;scanf("%d",&n);
    int ps = n;
    FOR(i,1,n-1){
        printf("? 1 %d %d %d\n",i,i+1,n-1);
        std::fflush(stdout);
        int x;scanf("%d",&x);
//        int x = std::max(std::min(a[i],n-1),std::min(a[i+1],n));
        if(x == n) {ps = i+1;break;}
        if(x < n-1) {i++;continue;}
        printf("? 1 %d %d %d\n",i+1,i,n-1);
        std::fflush(stdout);
        scanf("%d",&x);
//        x = std::max(std::min(a[i],n),std::min(a[i+1],n-1));
        if(x == n){ps = i;break;}
    }
    a[ps] = n;
    FOR(i,1,n){
        if(i == ps) continue;
        printf("? 2 %d %d %d\n",i,ps,1);std::fflush(stdout);
        int x;scanf("%d",&x);
        a[i] = x;
    }
    printf("! ");
    FOR(i,1,n) printf("%d%c",a[i]," \n"[i==n]);
    std::fflush(stdout);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}