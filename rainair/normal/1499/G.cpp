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

const int MAXN = 4e5 + 5;
const int ha = 998244353;

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

int f[MAXN],col[MAXN],od[MAXN];
int sm[MAXN][2],to[MAXN];
int n,m,ans,cnt,val=1;

inline int find(int x){
    if(x == f[x]) return x;
    int y = f[x],t = find(y);
    col[x] ^= col[y];
    return f[x] = t;
}

inline void link(int x,int y){
    (val <<= 1) %= ha;++cnt;f[cnt] = cnt;
    if(od[x] < od[y]) std::swap(x,y);
    if(!od[x]){
        od[x] ^= 1;od[y] ^= 1;
        to[x] = to[y] = cnt;
        sm[cnt][0] = val;
        return;
    }
    if(!od[y]){
        od[x] ^= 1;od[y] ^= 1;
        int w = to[x],rt = find(w);
        to[x] = 0;to[y] = cnt;
        col[cnt] = col[w]^1;
        f[cnt] = rt;
        add(sm[rt][col[cnt]],val);
        if(col[cnt]) add(ans,val);
        return;
    }
    od[x] ^= 1;od[y] ^= 1;
    int w1 = to[x],w2 = to[y];
    to[x] = to[y] = 0;
    int r1 = find(w1),r2 = find(w2);
    col[cnt] = col[w1]^1;f[cnt] = r1;
    add(sm[r1][col[cnt]],val);
    if(col[cnt]) add(ans,val);
    if(r1 == r2) return;
    f[r2] = r1;col[r2] = col[w1]^col[w2];
    add(sm[r1][0],sm[r2][col[r2]]);
    add(sm[r1][1],sm[r2][!col[r2]]);
    if(col[r2]) add(ans,sm[r2][0]),add(ans,ha-sm[r2][1]);
}

int main(){
    int q;scanf("%d%d%d",&n,&m,&q);
    FOR(i,1,q){
        int u,v;scanf("%d%d",&u,&v);
        link(u,n+v);
    }
    scanf("%d",&q);
    while(q--){
        int o;scanf("%d",&o);
        if(o == 1){
            int x,y;scanf("%d%d",&x,&y);
            link(x,n+y);
            printf("%d\n",ans);
        }
        else{
            std::vector<int> ans;
            FOR(i,1,cnt){
                find(i);
                if(col[i]) ans.pb(i);
            }
            printf("%d ",SZ(ans));
            for(auto x:ans) printf("%d ",x);puts("");
        }
        std::fflush(stdout);
    }
    return 0;
}