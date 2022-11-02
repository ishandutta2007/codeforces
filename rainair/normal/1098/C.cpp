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

const int MAXN = 1e5 + 5;
int n;LL s;
int d[MAXN];

inline bool chk(int x){
    FOR(i,1,n) d[i] = 1;
    LL r = 1ll*n*(n+1)/2-s;
    if(r < 0) return 0;
    if(r == 0) return 1;
    int now = 2,lst = n;
    while(1){
        while(1ll*d[now-1]*x == d[now]) ++now;
        while(!d[lst]) --lst;
        if(lst <= now) return 0;
        if(r > lst-now){
            d[lst]--;d[now]++;
            r -= (lst-now);
            continue;
        }
        else{
            while(r < lst-now) ++now;
            d[now]++;d[lst]--;
            r = 0;
            return 1;
        }
    }
    return 0;
}

std::vector<P> G[MAXN];
int fa[MAXN],dep[MAXN];

int main(){
    scanf("%d%lld",&n,&s);
    int l = 1,r = n-1,ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(chk(mid)) ans = mid,r = mid-1;
        else l = mid+1;
    }
    if(ans == -1){
        puts("No");return 0;
    }
    puts("Yes");chk(ans);
    G[1].pb(MP(1,ans));int t = 1;
    FOR(i,2,n){
        FOR(j,1,d[i]){
            assert(!G[i-1].empty());++t;
            printf("%d ",fa[t]=G[i-1].back().fi);
            G[i-1].back().se--;
            if(!G[i-1].back().se) G[i-1].pop_back();
            G[i].pb(MP(t,ans));
        }
    }
    puts("");
//    dep[1] = 1;
//    FOR(i,2,n) dep[i] = dep[fa[i]]+1;
//    int tt = 0;FOR(i,1,n) tt += i*d[i];
   // DEBUG(tt);
    //puts("");
    return 0;
}