#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2000+5;
LL f[MAXN];

inline LL calc(int n){
    return (1ll<<(n+1))-2;
}

int a[MAXN];

inline void Solve(){
    LL k;scanf("%lld",&k);
    if(k&1){
        puts("-1");
        return;
    }
    std::vector<int> S;
    while(k){
        int n = 1;
        while(calc(n+1) <= k) ++n;
        k -= calc(n);
        S.pb(n);
    }
    int n = 0;
    for(auto x:S){
        a[++n] = 1;
        FOR(i,1,x-1) a[++n] = 0;
    }
    printf("%d\n",n);
    FOR(i,1,n) printf("%d ",a[i]);puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}