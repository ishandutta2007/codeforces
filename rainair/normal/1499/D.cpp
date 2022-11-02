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

const int MAXN = 2e7 + 5;
bool p[MAXN];int prime[MAXN],d[MAXN],cnt;

inline void prework(){
    FOR(i,2,MAXN-1){
        if(!p[i]) prime[++cnt] = i,d[i] = 1;
        for(int j = 1;j <= cnt && 1ll*i*prime[j] < MAXN;++j){
            p[i*prime[j]] = 1;d[i*prime[j]] = d[i]+(i%prime[j] != 0);
            if(!(i%prime[j])) break;
        }
    }
}

int main(){
    prework();
    int T;scanf("%d",&T);
    while(T--){
        int c,d,x;scanf("%d%d%d",&c,&d,&x);
        int q = std::sqrt(1.0*x);
        LL ans = 0;
        FOR(g,1,q){
            if(x%g) continue;
            auto work = [&](int g){
                int t = x/g+d;
                if(t%c) return;
                t /= c;
                ans += 1<<::d[t];
            };
            work(g);
            if(g != x/g) work(x/g);
        }
        printf("%lld\n",ans);
    }
    return 0;
}