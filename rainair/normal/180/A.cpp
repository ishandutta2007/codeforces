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

const int MAXN = 1e5+5;
P<int,int> obj[MAXN];

int n,m;
std::vector<int> G[MAXN];
std::vector<P<int,int> > ans;
int bel[MAXN],ps[MAXN];

inline void copy(int x,int y){// x -> y
    ans.pb(x,y);
    bel[y] = bel[x];ps[y] = ps[x];bel[x] = ps[x] = 0;
}

int main(){
//    freopen("A.in","r",stdin);
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int sz;scanf("%d",&sz);
        G[i].resize(sz);FOR(j,0,sz-1) scanf("%d",&G[i][j]),bel[G[i][j]] = i,ps[G[i][j]] = j;
#ifdef RainAir
        FOR(j,0,sz-1) obj[G[i][j]] = MP(i,j);
#endif
    }
    int tot = 0,tmp = -1;
    FOR(i,1,n) if(!bel[i]) {tmp = i;break;}
    FOR(i,1,m){
        for(auto &x:G[i]){
            ++tot;
            if(x == tot) continue;
            if(!bel[tot]){
                if(tot == tmp) tmp = x;
                copy(x,tot),x = tot;
            }
            else{
                G[bel[tot]][ps[tot]] = tmp;
                copy(tot,tmp);
                copy(x,tot);
                tmp = x;
                x = tot;
            }
        }
    }
    printf("%d\n",SZ(ans));
    for(auto x:ans) printf("%d %d\n",x.fi,x.se);
#ifdef RainAir
{
    for(auto x:ans) obj[x.se] = obj[x.fi];
    int tot = 1;
    FOR(i,1,m){
        FOR(j,0,SZ(G[i])-1) assert(obj[tot].fi == i),assert(obj[tot].se == j),++tot;
    }
    assert(SZ(ans) <= 2*n);
}
#endif
    return 0;
}
// m=1