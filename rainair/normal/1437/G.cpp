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

const int MAXN = 3e5 + 5;

int ch[MAXN][26],fail[MAXN],tot = 1,rt = 1;
int ps[MAXN];

inline void insert(char str[],int id){
    int len = strlen(str+1),v = rt;
    FOR(i,1,len){
        int o = str[i]-'a';
        if(!ch[v][o]) ch[v][o] = ++tot;
        v = ch[v][o];
    }
    ps[id] = v;
}

std::vector<int> G[MAXN];

inline void build(){
    std::queue<int> q;
    FOR(i,0,25){
        if(ch[rt][i]) q.push(ch[rt][i]),fail[ch[rt][i]] = rt;
        else ch[rt][i] = rt;
    }
    while(!q.empty()){
        int v = q.front();q.pop();
        FOR(i,0,25){
            if(ch[v][i]) q.push(ch[v][i]),fail[ch[v][i]] = ch[fail[v]][i];
            else ch[v][i] = ch[fail[v]][i];
        }
    }
    FOR(i,2,tot) G[fail[i]].pb(i);
}

int mx[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void update(int x,int l,int r,int p,int d){
    if(l == r){
        mx[x] = d;
        return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) update(lc,l,mid,p,d);
    else update(rc,mid+1,r,p,d);
    mx[x] = std::max(mx[lc],mx[rc]);
}

inline int query(int x,int l,int r,int L,int R){
    if(l == L && r == R) return mx[x];
    int mid = (l + r) >> 1;
    if(R <= mid) return query(lc,l,mid,L,R);
    if(L > mid) return query(rc,mid+1,r,L,R);
    return std::max(query(lc,l,mid,L,mid),query(rc,mid+1,r,mid+1,R));
}

int dfn[MAXN],sz[MAXN],tp[MAXN],fa[MAXN],son[MAXN];
inline void dfs1(int v){
    sz[v] = 1;
    for(auto x:G[v]){
        fa[x] = v;
        dfs1(x);sz[v] += sz[x];
        if(sz[son[v]] < sz[x]) son[v] = x;
    }
}

inline void dfs2(int v,int tp=1){
    static int ts = 0;dfn[v] = ++ts;::tp[v] = tp;
    if(son[v]) dfs2(son[v],tp);
    for(auto x:G[v]){
        if(x == son[v]) continue;
        dfs2(x,x);
    }
}

inline int query(int x){
    int res = -1;
    while(tp[x] != 1){
        res = std::max(res,query(1,1,tot,dfn[tp[x]],dfn[x]));
        x = fa[tp[x]];
    }
    res = std::max(res,query(1,1,tot,dfn[1],dfn[x]));
    return res;
}

int n,m;
std::multiset<int> S[MAXN];
int val[MAXN];
char str[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    CLR(mx,-1);
    FOR(i,1,n){
        scanf("%s",str+1);
        insert(str,i);
        S[ps[i]].insert(0);
    }
    build();
    dfs1(1);dfs2(1);
    FOR(i,1,n) update(1,1,tot,dfn[ps[i]],*S[ps[i]].rbegin());
    while(m--){
        int opt;scanf("%d",&opt);
        if(opt == 1){
            int p,x;scanf("%d%d",&p,&x);
            S[ps[p]].erase(S[ps[p]].find(val[p]));
            val[p] = x;
            S[ps[p]].insert(val[p]);
            update(1,1,tot,dfn[ps[p]],*S[ps[p]].rbegin());
        }
        else{
            scanf("%s",str+1);int len = strlen(str+1);
            int v = 1,res = -1;
            FOR(i,1,len){
                v = ch[v][str[i]-'a'];
                res = std::max(res,query(v));
            }
            printf("%d\n",res);
        }
    }
    return 0;
}