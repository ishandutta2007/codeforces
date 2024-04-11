#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

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
char str[MAXN];

int ch[MAXN][26],len[MAXN],fail[MAXN],tot=1,rt=1,las = 1;
int sz[MAXN];

inline void extend(int c){
    int p = las,np = las = ++tot;len[np] = len[p]+1;
    for(;p&&!ch[p][c];p=fail[p]) ch[p][c] = np;
    if(!p) fail[np] = 1;
    else{
        int q = ch[p][c];
        if(len[q] == len[p]+1) fail[np] = q;
        else{
            int nq = ++tot;FOR(j,0,25) ch[nq][j] = ch[q][j];
            len[nq] = len[p]+1;fail[nq] = fail[q];
            fail[q] = fail[np] = nq;
            for(;p&&ch[p][c]==q;p=fail[p]) ch[p][c] = nq;
        }
    }
    sz[np]++;
}

int n;
int sa[MAXN],rk[MAXN],tax[MAXN],tp[MAXN],H[MAXN],M;
const int MAXM = 17;
int mn[MAXM+1][MAXN];

inline void sort(){
    FOR(i,0,M) tax[i] = 0;
    FOR(i,1,n) tax[rk[i]]++;
    FOR(i,1,M) tax[i] += tax[i-1];
    ROF(i,n,1) sa[tax[rk[tp[i]]]--] = tp[i];
}

inline void build(){
    M = 26;
    FOR(i,1,n) rk[i] = str[i]-'a'+1,tp[i] = i;
    sort();
    for(int w=1,p=0;p<n;w<<=1,M = p){
        p = 0;
        FOR(i,1,w) tp[++p] = n-w+i;
        FOR(i,1,n) if(sa[i] > w) tp[++p] = sa[i]-w;
        sort();std::swap(rk,tp);
        rk[sa[1]] = p = 1;
        FOR(i,2,n) rk[sa[i]] = tp[sa[i-1]]==tp[sa[i]]&&tp[sa[i-1]+w] == tp[sa[i]+w] ? p : ++p;
    }
    int j = 0;
    FOR(i,1,n){
        if(j) j--;
        while(str[i+j] == str[sa[rk[i]-1]+j]) ++j;
        H[rk[i]] = j;
    }
    FOR(i,1,n) mn[0][i] = H[i];
    FOR(i,1,MAXM){
        for(int j = 1;j+(1<<(i-1))<MAXN;++j){
            mn[i][j] = std::min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
        }
    }
}

int pc[MAXN];
std::set<int> S[MAXN];
LL ans[MAXN];

inline int calc(int l,int r){
    int c = pc[r-l+1];
    return std::min(mn[c][l],mn[c][r-(1<<c)+1]);
}

inline void insert(int x,int y){
    auto it = S[x].insert(y).fi;
    if(it != S[x].begin()){
        auto pre = it;--pre;
        ans[x] -= calc((*pre)+1,*it);
    }
    auto suf = it;++suf;
    if(suf != S[x].end()){
        ans[x] -= calc((*it)+1,*suf);
        if(it != S[x].begin()){
            auto pre = it;--pre;
            ans[x] += calc((*pre)+1,*suf);
        }
    }
    ans[x] += n-sa[y]+1;
}

inline void merge(int x,int y){
    if(S[x].size() < S[y].size()) std::swap(S[x],S[y]),std::swap(ans[x],ans[y]);
    for(auto v:S[y]) insert(x,v);S[y].clear();
}

inline int qqqq(int x,int y){
    x = rk[x];y = rk[y];
    if(x > y) std::swap(x,y);
    return calc(x+1,y);
}

std::vector<int> G[MAXN];
LL res=0;

inline void dfs(int v){
    for(auto x:G[v]){
        dfs(x);
        merge(v,x);
    }
//    if(v == 5) DEBUG(ans[5]);
    res += 1ll*(len[v]-len[fail[v]])*ans[v];
}

int main(){
    pc[0] = -1;FOR(i,1,MAXN-1) pc[i] = pc[i>>1]+1;
    scanf("%s",str+1);n = strlen(str+1);build();
    LL ttt =0;
    FOR(i,1,n){
        extend(str[i]-'a');
        if(i == n-1) FOR(j,1,tot) res += len[j]-len[fail[j]];
        if(i+2 <= n) insert(las,rk[i+2]);
    }
    FOR(i,1,tot) res += len[i]-len[fail[i]];
    FOR(i,2,tot) G[fail[i]].pb(i);
    dfs(1);
    S[0].clear();ans[0] = 0;
    FOR(i,2,n) insert(0,rk[i]);res += ans[0];
    printf("%lld\n",res+2);
    return 0;
}