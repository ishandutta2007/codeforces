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

const int MAXN = 2000+5;
int n,s,a[MAXN],m;
std::vector<int> S;
int f[MAXN][MAXN];
std::vector<int> G[MAXN];

inline int dis(int i,int j){
    if(i < j) std::swap(i,j);
    return std::min(i-j,n-i+j);
}

int g[MAXN];
int p1[MAXN][MAXN],p2[MAXN][MAXN];
int ps[MAXN];

int main(){
    scanf("%d%d",&n,&s);
    FOR(i,1,n) scanf("%d",a+i),S.pb(a[i]);
    std::sort(all(S));S.erase(std::unique(all(S)),S.end());
    FOR(i,1,n) a[i] = std::lower_bound(all(S),a[i])-S.begin()+1;
    FOR(i,1,n) G[a[i]].pb(i),ps[i] = SZ(G[a[i]])-1;
    m = S.size();CLR(f,0x3f);
    G[0].pb(s);f[0][s] = 0;
    FOR(i,1,m){
        if(G[i].size() == 1){
            for(auto x:G[i-1]){
                if(f[i][G[i][0]] > f[i-1][x]+dis(x,G[i][0])){
                    f[i][G[i][0]] = f[i-1][x]+dis(x,G[i][0]);
                    p1[i][G[i][0]] = x;
                }
            }
            continue;
        }
        CLR(g,0x3f);
        for(auto x:G[i-1]) for(auto y:G[i]){
            if(g[y] > f[i-1][x]+dis(x,y)){
                g[y] = f[i-1][x]+dis(x,y);
                p1[i][y] = x;
            }
        }
        FOR(x,0,SZ(G[i])-1){
            for(int d = -1;d <= 1;d += 2){
                int y = (x+d+SZ(G[i]))%SZ(G[i]),gx = 0;
                if(d == -1) gx = G[i][x]-G[i][y];
                else gx = G[i][y]-G[i][x];
                if(gx < 0) gx += n;
                gx = n-gx;
                if(f[i][G[i][y]] > g[G[i][x]]+gx){
                    f[i][G[i][y]] = g[G[i][x]]+gx;
                    p2[i][G[i][y]] = d==-1?1:-1;
                }
            }
        }
    }
    int ans = 1e9,j = -1;
    for(auto x:G[m]){
        if(ans > f[m][x]){
            ans = f[m][x];
            j = x;
        }
    }
    printf("%d\n",ans);
    std::vector<P<int,int> > S;
    ROF(i,m,1){
        auto gao = [&](int x,int y){
            bool flag = x < y;if(x < y) std::swap(x,y);
            if(x-y <= n-x+y) S.pb(MP(1,x-y));
            else S.pb(MP(0,n-x+y));
            S.back().fi ^= flag;
        };
        if(G[i].size() == 1){
            gao(G[i][0],p1[i][G[i][0]]);
            j = p1[i][G[i][0]];continue;
        }
        int y = (ps[j]+p2[i][j]+SZ(G[i]))%SZ(G[i]),p = ps[j];
        if(p2[i][j] == -1){
            while(p != y){
                int d = G[i][(p+1)%SZ(G[i])]-G[i][p];
                if(d < 0) d += n;
                S.pb(MP(0,d));
                (p += 1) %= SZ(G[i]);
            }
        }
        else{
            while(p != y){
                int d = G[i][p]-G[i][(p-1+SZ(G[i]))%SZ(G[i])];
                if(d < 0) d += n;
                S.pb(MP(1,d));
                (p += SZ(G[i])-1) %= SZ(G[i]);
            }
        }
        gao(G[i][y],p1[i][G[i][y]]);
   //     if(i == 3){
 //           DEBUG(G[i][y]);DEBUG(p1[i][G[i][y]]);
 //           DEBUG(S.back().fi);DEBUG(S.back().se);
     //   }
        j = p1[i][G[i][y]];
    }
    std::reverse(all(S));
    for(auto x:S){
        if(x.fi == 1) printf("+%d\n",x.se);
        else printf("-%d\n",x.se);
    }
    static bool vis[MAXN];
    auto chk = [&](){
        int now = 1,res = 0;
        std::sort(a+1,a+n+1);
        for(auto x:S){
            if(x.fi == 1) now = (now-1+x.se)%n+1;
            else now = (now-1-x.se+n)%n+1;
            assert(!vis[now]);
//            if(vis[now]) return false;
            vis[now] = 1;res += x.se;
        }
//        DEBUG(res);
        assert(res==ans);
//        return res==ans;
    };
    chk();
    return 0;
}