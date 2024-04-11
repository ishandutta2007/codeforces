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

const int MAXN = 2e5 + 5;

#define lc ((x)<<1)
#define rc ((x)<<1|1)
int sm[MAXN<<2],tag[MAXN<<2];
//   tag 

inline void modify(int x,int l,int r,int L,int R,int d){
    if(l == L && r == R){
        tag[x] += d;
        sm[x] = tag[x] ? r-l+1 : (l==r ? 0 : sm[lc]+sm[rc]);
        return;
    }
    int mid = (l + r) >> 1;
    if(R <= mid) modify(lc,l,mid,L,R,d);
    else if(L > mid) modify(rc,mid+1,r,L,R,d);
    else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
    sm[x] = tag[x]?r-l+1:sm[lc]+sm[rc];
}

int n,m,N;

inline int id(int i,int j){
    return (i-1)*m+j;
}

std::vector<char> str[MAXN];
char _[MAXN];

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],du[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;du[v]++;
}

int dfn[MAXN],sz[MAXN];

inline void dfs(int v){
    static int ts=0;dfn[v] = ++ts;sz[v] = 1;
    for(int i = head[v];i;i = e[i].nxt){
        dfs(e[i].to);
        sz[v] += sz[e[i].to];
    }
}

struct Node{
    int l,r,d;
    Node(int l=0,int r=0,int d=0) : l(l),r(r),d(d) {}
};

std::vector<Node> G[MAXN];
bool vis[MAXN];

int main(){
    scanf("%d%d",&n,&m);N = id(n,m);
    FOR(i,1,n){
        scanf("%s",_+1);str[i].pb('#');
        FOR(j,1,m) str[i].pb(_[j]);
    }
    int R = N+1;++N;
    FOR(i,1,n){
        FOR(j,1,m){
            if(str[i][j] == 'U' && i+2 <= n){
                add(id(i+2,j),id(i,j));
            }
            else if(str[i][j] == 'D' && i-2 >= 1){
                add(id(i-2,j),id(i,j));
            }
            else if(str[i][j] == 'L' && j+2 <= m){
                add(id(i,j+2),id(i,j));
            }
            else if(str[i][j] == 'R' && j-2 >= 1){
                add(id(i,j-2),id(i,j));
            }
            else add(R,id(i,j));
        }
    }
    dfs(R);
    FOR(i,1,n){
        FOR(j,1,m){
            if(vis[id(i,j)]) continue;// 
            vis[id(i,j)] = 1;int p = id(i,j),q;
            if(str[i][j] == 'U'){
                vis[q = id(i+1,j)] = 1;
            }
            if(str[i][j] == 'D'){
                vis[q = id(i-1,j)] = 1;
            }
            if(str[i][j] == 'L'){
                vis[q = id(i,j+1)] = 1;
            }
            if(str[i][j] == 'R'){
                vis[q = id(i,j-1)] = 1;
            }
            if(dfn[p] > dfn[q]) std::swap(p,q);
            G[dfn[p]].pb(Node(dfn[q],dfn[q]+sz[q]-1,1));
            G[dfn[p]+sz[p]].pb(Node(dfn[q],dfn[q]+sz[q]-1,-1));
        }
    }
    LL ans = 0;
    FOR(i,1,N){
        for(auto x:G[i]){
            modify(1,1,N,x.l,x.r,x.d);
        }
        ans += sm[1];
    }
    printf("%lld\n",ans);
    return 0;
}