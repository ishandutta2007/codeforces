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
std::string s[MAXN],tmp[MAXN],str[MAXN];
int n,len;
int id[MAXN];
LL ans = 0;

struct Trie{
    int ch[MAXN][26],tot;
    int dfn[MAXN],sz[MAXN],ts;
    inline void reset(){
        ts = 0;FOR(i,1,tot) CLR(ch[i],0),dfn[i] = sz[i] = 0;tot = 1;
    }

    inline int insert(const std::string &str,bool flag=0){
        int v = 1;
        FOR(i,1,len){
            int o = str[flag?len-i+1:i]-'a';
            if(!ch[v][o]) ch[v][o] = ++tot;
            v = ch[v][o];
        }
        return v;
    }

    inline void dfs(int v){
        dfn[v] = ++ts;sz[v] = 1;
        FOR(i,0,25) if(ch[v][i]) dfs(ch[v][i]),sz[v] += sz[ch[v][i]];
    }
}t1,t2;

int pre[MAXN],suf[MAXN];
int p1[MAXN],p2[MAXN];

struct Node{
    int o,l,r,d;
    Node(int o=0,int l=0,int r=0,int d=0) : o(o),l(l),r(r),d(d) {}

    inline bool operator < (const Node &t) const {
        return o < t.o;
    }
};
// 0:add,1:query
std::vector<Node> G[MAXN];

struct BIT{
#define lowbit(x) ((x)&(-(x)))
    int tree[MAXN],ts[MAXN],now;
    BIT(){CLR(ts,0);now = 0;}

    inline void reset(){++now;}

    inline void add(int p,int x){
        for(;p<MAXN;p += lowbit(p)){
            if(ts[p] != now) ts[p] = now,tree[p] = 0;
            tree[p] += x;
        }
    }

    inline int calc(int p){// prefix p
        int res = 0;
        for(;p;p-=lowbit(p)){
            if(ts[p] != now) ts[p] = now,tree[p] = 0;
            res += tree[p];
        }
        return res;
    }

    inline int query(int l,int r){
        return calc(r)-calc(l-1);
    }
}bit;

inline void work(int n){
    LL c0 = 0;
    std::sort(str+1,str+n+1);
    FOR(i,1,n) str[i] = " " + str[i];
    for(int l = 1,r;l <= n;l = r+1){
        r = l;while(r+1 <= n && str[r+1] == str[l]) ++r;
        c0 += 1ll*(r-l+1)*(r-l)/2;
    }
    t1.reset();t2.reset();
    FOR(i,1,n){
        p1[i] = t1.insert(str[i],0),p2[i] = t2.insert(str[i],1);
    }
    int m = t1.tot;
    FOR(i,0,m) G[i].clear();
    t1.dfs(1);t2.dfs(1);
    FOR(i,1,n) G[t1.dfn[p1[i]]].pb(0,t2.dfn[p2[i]]);
    LL c1=0;
    FOR(i,1,n){
        pre[0] = suf[len+1] = 1;
        FOR(j,1,len) pre[j] = t1.ch[pre[j-1]][str[i][j]-'a'];
        ROF(j,len,1) suf[j] = t2.ch[suf[j+1]][str[i][j]-'a'];
        for(int l = 1,r;l <= len;l = r+1){
            r = l;
            while(r+1 <= len && str[i][r] <= str[i][r+1]) ++r;
            // pre[l-1],suf[r+1]
            int l1 = t1.dfn[pre[l-1]],r1 = t1.dfn[pre[l-1]]+t1.sz[pre[l-1]]-1;
            int l2 = t2.dfn[suf[r+1]],r2 = t2.dfn[suf[r+1]]+t2.sz[suf[r+1]]-1;
            G[l1-1].pb(1,l2,r2,-1);G[r1].pb(1,l2,r2,1);
            --c1;
        }
    }
    bit.reset();
    FOR(i,1,m){
        std::sort(all(G[i]));
        for(auto x:G[i]){
            if(x.o == 0){
                bit.add(x.l,1);
            }
            else{
                c1 += x.d*bit.query(x.l,x.r);
            }
        }
    }
//    DEBUG(c1);
    LL c2 = 1ll*n*(n-1)/2-c0-c1;
    ans += c2*2+c1;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    FOR(i,1,n){
        std::cin >> s[i];tmp[i] = s[i];
        std::sort(all(tmp[i]));id[i] = i;
    }len = SZ(s[1]);
    std::sort(id+1,id+n+1,[&](int x,int y){return tmp[x] < tmp[y];});
    LL coe = 1ll*n*(n-1)/2;
    for(int l = 1,r;l <= n;l = r+1){
        r = l;while(r+1 <= n && tmp[id[r+1]] == tmp[id[l]]) ++r;
        FOR(i,l,r) str[i-l+1] = s[id[i]];
        work(r-l+1);
        coe -= 1ll*(r-l+1)*(r-l)/2;
    }
    ans += coe*1337;
    printf("%lld\n",ans);
    return 0;
}