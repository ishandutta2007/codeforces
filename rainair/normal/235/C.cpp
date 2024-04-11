#include<bits/stdc++.h>

#define fi first
#define se second
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

const int MAXN = 2e6 + 5;
int ts = 0;
struct SAM{
    int ch[MAXN][26],len[MAXN],fail[MAXN],sz[MAXN],las = 1,tot = 1;
    int vis[MAXN];
    std::vector<int> G[MAXN];

    inline void copy(int x,int y){
        FOR(i,0,25) ch[x][i] = ch[y][i];
        len[x] = len[y];fail[x] = fail[y];
    }

    inline int insert(int c){
        int p = las,np = las = ++tot;len[np] = len[p]+1;sz[np] = 1;
        for(;p&&!ch[p][c];p=fail[p]) ch[p][c] = np;
        if(!p) fail[np] = 1;
        else{
            int q = ch[p][c];
            if(len[q] == len[p]+1) fail[np] = q;
            else{
                int nq = ++tot;copy(nq,q);len[nq] = len[p]+1;fail[q] = fail[np] = nq;
                for(;p&&ch[p][c]==q;p=fail[p]) ch[p][c]=nq;
            }
        }
        return np;
    }

    inline void dfs(int v,int fa=0){
        for(auto x:G[v]){
            dfs(x,v);sz[v] += sz[x];
        }
    }

    inline void build(){
        FOR(i,1,tot) G[fail[i]].pb(i);
        dfs(1);
    }
}sam;

char str[MAXN];

int v,l,n;

inline void add(int c){
    if(!v) v = 1;
    while(v && !sam.ch[v][c]) l = sam.len[v=sam.fail[v]];
    if(sam.ch[v][c]){
        ++l;v = sam.ch[v][c];
    }
}

inline void del(){
    if(l > n && --l == sam.len[sam.fail[v]]) v = sam.fail[v];
}

int main(){
    scanf("%s",str+1);n = strlen(str+1);
    FOR(i,1,n) sam.insert(str[i]-'a');sam.build();
    int T;scanf("%d",&T);
    while(T--){
        ++ts;
        scanf("%s",str+1);n = strlen(str+1);
        v = 1;l = 0;LL ans = 0;
        FOR(i,1,n) add(str[i]-'a');
        if(l == n) ans += sam.sz[v],sam.vis[v] = ts;
        //DEBUG(ans);
        FOR(i,1,n-1){
//            del();
            add(str[i]-'a');del();
            if(l == n && sam.vis[v] < ts) ans += sam.sz[v],sam.vis[v] = ts;
          //  DEBUG(l);DEBUG(v);
        }
        printf("%lld\n",ans);
    }
    return 0;
}