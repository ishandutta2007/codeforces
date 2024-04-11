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

const int MAXN = 3000+5;
int a[MAXN][MAXN],n,m;
char str[MAXN];
std::vector<int> G[MAXN<<1];
int l[MAXN][MAXN],r[MAXN][MAXN],ld[MAXN][MAXN];

struct BIT{
    #define lowbit(x) ((x)&(-(x)))
    #define MAX 3000
    int tree[MAXN<<1];

    inline void add(int pos,int x){
        pos += MAX;
        while(pos < (MAXN<<1)){
            tree[pos] += x;
            pos += lowbit(pos);
        }
    }

    inline int query(int pos){
        pos += MAX;int res = 0;
        while(pos){
            res += tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
    #undef MAX
}bit;

std::vector<P<int,int> > q[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("%s",str+1);
        FOR(j,1,m) a[i][j] = (str[j]=='z');
    }
    ROF(i,n,1){
        FOR(j,1,m) if(a[i][j]) l[i][j] = l[i][j-1]+1,ld[i][j] = ld[i+1][j-1]+1;
        ROF(j,m,1) if(a[i][j]) r[i][j] = r[i][j+1]+1;
    }
    FOR(i,1,n) FOR(j,1,m) G[i+j].pb(i);
    LL ans = 0;
    FOR(c,2,n+m){
        CLR(bit.tree,0);
        FOR(i,1,n+1) q[i].clear();
        for(auto i:G[c]){
            int ll = i,rr = std::min(l[i][c-i],ld[i][c-i])+i-1;
            if(ll <= rr) q[ll].pb(MP(i-1,1)),q[rr+1].pb(MP(i-1,-1));
        }
        ROF(i,n,1){
            if(c-i >= 1) bit.add(i-r[i][c-i],1);
            for(auto x:q[i]){
                ans += x.se*bit.query(x.fi);
            }
        }
//        DEBUG(ans);
//        exit(0);
    }
    printf("%lld\n",ans);
    return 0;
}