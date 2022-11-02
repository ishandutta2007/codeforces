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

const int MAXN = 5e5 + 5;

int ch[MAXN][26],fail[MAXN],len[MAXN],tot=1;

inline int work(int p,int c){
    int q = ch[p][c],nq = ++tot;
    FOR(i,0,25) ch[nq][i] = ch[q][i];fail[nq] = fail[q];len[nq] = len[p]+1;
    fail[q] = nq;for(;p&&ch[p][c]==q;p=fail[p]) ch[p][c] = nq;
    return nq;
}

inline int insert(int p,int c){
    int q = ch[p][c];
    if(q){
        if(len[q] == len[p]+1) return q;
        return work(p,c);
    }
    int np = ++tot;len[np] = len[p]+1;
    for(;p&&!ch[p][c];p=fail[p]) ch[p][c] = np;
    if(!p) fail[np] = 1;
    else{
        q = ch[p][c];
        if(len[q] == len[p]+1) fail[np] = q;
        else fail[np] = work(p,c);
    }
    return np;
}

int n,q;
char str[MAXN];
int ps[MAXN];
std::vector<int> T[MAXN];
int dfn[MAXN],sz[MAXN];

inline void dfs(int v){
    static int ts = 0;dfn[v] = ++ts;sz[v] = 1;
    for(auto x:T[v]) dfs(x),sz[v] += sz[x];
}

//  (c,dfn[])
struct Node{
    int opt,l,r,d,id;
};

struct BIT{
    #define lowbit(x) ((x)&(-(x)))
    int tree[MAXN];

    inline void add(int pos,int x){
        for(;pos<MAXN;pos+=lowbit(pos)) tree[pos] += x;
    }

    inline int query(int pos){
        int res = 0;
        for(;pos;pos-=lowbit(pos)) res += tree[pos];
        return res;
    }
}bit;

std::vector<Node> G[MAXN];
int ans[MAXN];

int main(){
//    freopen("A.in","r",stdin);
//    freopen("A.out","w",stdout);
    scanf("%d%d",&n,&q);int p = 1;
    FOR(c,1,n){
        scanf("%s",str+1);int len = strlen(str+1);p = 1;
        FOR(i,1,len) p = insert(p,str[i]-'a'),G[c].pb({0,p,p,1,0});
        ps[c] = p;
    }
    FOR(i,2,tot) T[fail[i]].pb(i);
    dfs(1);
    FOR(i,1,q){
        int l,r,k;scanf("%d%d%d",&l,&r,&k);
        int ll = dfn[ps[k]],rr = dfn[ps[k]]+sz[ps[k]]-1;
        G[l-1].pb({1,ll,rr,-1,i});
        G[r].pb({1,ll,rr,1,i});
    }
    FOR(i,1,n){
        for(auto x:G[i]){
            if(x.opt == 0){
                bit.add(dfn[x.l],1);
            }
            else{
                ans[x.id] += x.d*(bit.query(x.r)-bit.query(x.l-1));
            }
        }
    }
    FOR(i,1,q) printf("%d\n",ans[i]);
    return 0;
}