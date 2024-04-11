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

const int MAX = 1e6 + 5;
const int MAXN = 5e4 + 4;
const int MAXM = 19;

struct Trie{
    int mn[MAX],ch[MAX][2],tot,rt;

    inline int New(){
        ++tot;mn[tot] = 1e9;ch[tot][0] = ch[tot][1] = 0;return tot;
    }

    inline void reset(){
        tot = 0;rt = New();
    }

    inline void insert(int x,int d){
        int v = rt;mn[v] = std::min(mn[v],d);
        ROF(i,MAXM,0){
            int o = (x>>i)&1;
            if(!ch[v][o]) ch[v][o] = New();
            v = ch[v][o];mn[v] = std::min(mn[v],d);
        }
    }

    inline int query(int x,int d){
        int v = rt,res = 0;
        ROF(i,MAXM,0){
            int o = (x>>i)&1;
            if(ch[v][!o] && mn[ch[v][!o]] <= d) v = ch[v][!o],res |= 1<<i;
            else v = ch[v][o];
        }
        return res;
    }
}tr[2];

int n,m,a[MAXN];
int sm[1000005];
int bel[MAXN],B;

struct Node{
    int l,r,id;
    inline bool operator < (const Node &t) const {
        if(bel[l] != bel[t.l]) return bel[l] < bel[t.l];
        return r < t.r;
    }
}q[MAXN];
int g[MAXN],ans[MAXN];

int main(){
    FOR(i,1,1000000) sm[i] = sm[i-1]^i;
    scanf("%d%d",&n,&m);B = std::sqrt(1.0*n*n/m);B = std::max(B,1);
    //B = 2;
    FOR(i,1,n) scanf("%d",a+i),bel[i] = (i-1)/B+1;
    FOR(i,1,m) scanf("%d%d",&q[i].l,&q[i].r),q[i].id = i;
    std::sort(q+1,q+m+1);
    FOR(c,1,bel[n]){
        int l = (c-1)*B+1,r = std::min(n,c*B);
        tr[0].reset();tr[1].reset();
        ROF(i,r,l){
            tr[0].insert(sm[a[i]-1],a[i]);
            g[i] = std::max(g[i+1],tr[0].query(sm[a[i]],a[i]));
            tr[1].insert(sm[a[i]],-a[i]);
            g[i] = std::max(g[i],tr[1].query(sm[a[i]-1],-a[i]));
        }
    }
    int lst = 0,rst = 0,mx = 0;
    FOR(i,1,m){
        if(lst != bel[q[i].l]){
            tr[0].reset();tr[1].reset();
            lst = bel[q[i].l];
            rst = bel[q[i].l]*B;
            mx = 0;
        }
        if(q[i].r <= bel[q[i].l]*B){
            FOR(k,q[i].l,q[i].r){
                tr[0].insert(sm[a[k]-1],a[k]);
                ans[q[i].id] = std::max(ans[q[i].id],tr[0].query(sm[a[k]],a[k]));
                tr[1].insert(sm[a[k]],-a[k]);
                ans[q[i].id] = std::max(ans[q[i].id],tr[1].query(sm[a[k]-1],-a[k]));
            }
            tr[0].reset();tr[1].reset();
            continue;
        }
        while(rst+1 <= q[i].r){
            ++rst;
            tr[0].insert(sm[a[rst]-1],a[rst]);
            mx = std::max(mx,tr[0].query(sm[a[rst]],a[rst]));
            tr[1].insert(sm[a[rst]],-a[rst]);
            mx = std::max(mx,tr[1].query(sm[a[rst]-1],-a[rst]));
        }
        ans[q[i].id] = std::max(mx,g[q[i].l]);
        FOR(k,q[i].l,bel[q[i].l]*B){
            ans[q[i].id] = std::max(ans[q[i].id],tr[0].query(sm[a[k]],a[k]));
            ans[q[i].id] = std::max(ans[q[i].id],tr[1].query(sm[a[k]-1],-a[k]));
        }
    }
    FOR(i,1,m) printf("%d\n",ans[i]);
    return 0;
}