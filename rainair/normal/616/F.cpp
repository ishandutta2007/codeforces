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

const int MAXN = 1e6 + 5;
int n;

int fail[MAXN],ch[MAXN][26],len[MAXN],tot = 1,rt = 1,las = 1;
LL sm[MAXN];

inline int work(int p,int c){
    int q = ch[p][c],nq = ++tot;
    FOR(i,0,25) ch[nq][i] = ch[q][i];
    len[nq] = len[p]+1;fail[nq] = fail[q];
    fail[q] = nq;
    for(;p&&ch[p][c]==q;p=fail[p]) ch[p][c] = nq;
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

char str[MAXN];
std::vector<int> G[MAXN];
std::vector<int> ep[MAXN];

inline void dfs(int v){
    for(auto x:G[v]) dfs(x),sm[v] += sm[x];
}

int main(){
    scanf("%d",&n);
    FOR(cc,1,n){
        las = 1;
        scanf("%s",str+1);int len = strlen(str+1);
        FOR(i,1,len){
            las = insert(las,str[i]-'a');
            ep[cc].pb(las);
        }
    }
    FOR(i,1,n){
        int x;scanf("%d",&x);
        for(auto v:ep[i]) sm[v] += x;
    }
    FOR(i,1,tot) G[fail[i]].pb(i);
    dfs(1);
    LL ans = 0;
    FOR(i,2,tot) ans = std::max(ans,sm[i]*len[i]);
    printf("%lld\n",ans);
    return 0;
}