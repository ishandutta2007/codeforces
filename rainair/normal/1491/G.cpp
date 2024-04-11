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

const int MAXN = 2e5 + 5;
int a[MAXN],n,m;
std::vector<int> cir[MAXN];
std::vector<P<int,int> > ans;
bool vis[MAXN];

int main(){
#ifdef RainAir
    std::mt19937 g(time(NULL));
//    n = 2e5;
//    a[1] = 2;a[2] = 1;a[3] = 5;a[4] = 4;a[5] = 6;a[6] = 3;
    FOR(i,1,n) a[i] = i;
    std::shuffle(a+1,a+n+1,g);
    FOR(i,1,n) DEBUG(a[i]);
#else
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
#endif
    FOR(i,1,n){
        if(vis[i]) continue;
        int v = i;++m;
        while(!vis[v]){
            cir[m].pb(v);vis[v] = 1;v = a[v];
        }
    }
    if(m == 1){
        ans.pb(cir[1][0],cir[1][1]);
        ans.pb(cir[1].back(),cir[1][1]);
        FOR(j,2,SZ(cir[1])-1) ans.pb(cir[1][j],cir[1][0]);
        ans.pb(cir[1][0],cir[1][1]);
    }
    else{
        std::sort(cir+1,cir+m+1,[&](const std::vector<int> &x,const std::vector<int> &y){return SZ(x)>SZ(y);});
        int ps = -1;
        for(int i = 1;i <= m;i += 2){
            if(SZ(cir[i]) == 1) break;
            if(i+1 > m || SZ(cir[i+1]) == 1){ps = i;break;}
            ans.pb(cir[i][0],cir[i+1][0]);
            ans.pb(cir[i][1],cir[i+1][1]);
            std::swap(cir[i][1],cir[i+1][1]);
            FOR(j,2,SZ(cir[i])-1) ans.pb(cir[i][1],cir[i][j]);
            ans.pb(cir[i][0],cir[i][1]);
            FOR(j,2,SZ(cir[i+1])-1) ans.pb(cir[i+1][1],cir[i+1][j]);
            ans.pb(cir[i+1][0],cir[i+1][1]);
        }
        if(ps != -1){
            int ext = -1;
            if(ps == 1) ext = cir[m][0];
            else ext = cir[1][0];
            ans.pb(cir[ps][0],ext);
            ans.pb(cir[ps][1],ext);
            cir[ps][1] = ext;
            FOR(j,2,SZ(cir[ps])-1) ans.pb(cir[ps][1],cir[ps][j]);
            ans.pb(cir[ps][0],cir[ps][1]);
        }
    }
    printf("%d\n",SZ(ans));
    for(auto x:ans) printf("%d %d\n",x.fi,x.se);
#ifdef RainAir
    static bool zt[MAXN];
    for(auto x:ans){
        zt[a[x.fi]] ^= 1;
        zt[a[x.se]] ^= 1;
        std::swap(a[x.fi],a[x.se]);
    }
    FOR(i,1,n) assert(!zt[i]);
    FOR(i,1,n) assert(a[i]==i);
    assert(SZ(ans) <= n+1);
#endif
    return 0;
}